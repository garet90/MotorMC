#include <openssl/evp.h>
#include "play.h"
#include "../../io/logger/logger.h"
#include "../../io/nbt/mnbt.h"
#include "../../io/commands/graph.h"
#include "../../motor.h"
#include "../../world/world.h"
#include "../../world/entity/entity.h"
#include "../../world/item/recipe/recipe.h"
#include "../../jobs/board.h"
#include "../../jobs/scheduler/scheduler.h"
#include "../../util/util.h"
#include "../../util/long_encode.h"

bool phd_play(ltg_client_t* client, pck_packet_t* packet) {

	const int32_t id = pck_read_var_int(packet);

	switch (id) {
		case 0x00: {
			return phd_handle_teleport_confirm(client, packet);
		}
		case 0x03: {
			return phd_handle_chat_message(client, packet);
		}
		case 0x04: {
			return phd_handle_client_status(client, packet);
		}
		case 0x05: {
			return phd_handle_client_settings(client, packet);
		}
		case 0x08: {
			return phd_handle_click_window(client, packet);
		}
		case 0x09: {
			return phd_handle_close_window(client, packet);
		}
		case 0x0a: {
			return phd_handle_plugin_message(client, packet);
		}
		case 0x0f: {
			return phd_handle_keep_alive(client, packet);
		}
		case 0x11: {
			return phd_handle_player_position(client, packet);
		}
		case 0x12: {
			return phd_handle_player_position_and_look(client, packet);
		}
		case 0x13: {
			return phd_handle_player_rotation(client, packet);
		}
		case 0x14: {
			return phd_handle_player_movement(client, packet);
		}
		case 0x1a: {
			return phd_handle_player_digging(client, packet);
		}
		case 0x1b: {
			return phd_handle_entity_action(client, packet);
		}
		case 0x25: {
			return phd_handle_held_item_change(client, packet);
		}
		case 0x2c: {
			return phd_handle_animation(client, packet);
		}
		case 0x2e: {
			return phd_handle_player_block_placement(client, packet);
		}
		case 0x2f: {
			return phd_handle_use_item(client, packet);
		}
		default: {
			log_warn("Unknown packet %02x received in play state!", id);
			return false;
		}
	}

}

bool phd_handle_teleport_confirm(ltg_client_t* client, pck_packet_t* packet) {

	uint32_t confirm = pck_read_var_int(packet);

	// the player must've not heard us right
	if (confirm != ent_get_id(ent_player_get_entity(ltg_client_get_entity(client)))) {
		return false;
	}

	return true;

}

bool phd_handle_chat_message(ltg_client_t* client, pck_packet_t* packet) {

	string_t message;
	message.length = (unsigned) pck_read_var_int(packet);
	message.value = malloc(message.length + 1);
	message.value[message.length] = '\0';
	pck_read_bytes(packet, (byte_t*) message.value, message.length);

	if (message.length > 0 && UTL_STRTOCSTR(message)[0] == '/') {
		log_info("%s issued server command: %s", UTL_STRTOCSTR(ltg_client_get_username(client)), UTL_STRTOCSTR(message));
		const cmd_sender_t sender = {
			.type = cmd_player,
			.player = client
		};
		cmd_handle(UTL_STRTOCSTR(message) + 1, &sender);
		free(UTL_STRTOCSTR(message));
	} else {
		job_add(job_new(job_global_chat_message, (job_payload_t) { .global_chat_message = { .client = client, .message = message } }));
	}

	return true;

}

bool phd_handle_client_status(ltg_client_t* client, pck_packet_t* packet) {

	const int32_t action = pck_read_var_int(packet);

	switch (action) {
		case 0: { // respawn
			if (ent_le_is_dead(ent_player_get_le(ltg_client_get_entity(client)))) {
				phd_update_respawn(client);
			}
		} break;
		case 1: { // request stats

		} break;
	}

	return true;

}

bool phd_handle_client_settings(ltg_client_t* client, pck_packet_t* packet) {

	PCK_READ_STRING(locale, packet);
	client->locale = utl_hash(locale);

	const uint8_t new_render_distance = UTL_MIN(sky_get_render_distance(), pck_read_int8(packet));
	phd_update_sent_chunks_view_distance(client, new_render_distance);
	ltg_client_set_render_distance(client, new_render_distance);
	ltg_client_set_chat_mode(client, pck_read_var_int(packet));
	__attribute__((unused)) bool colors = pck_read_int8(packet);

	ent_player_t* player = ltg_client_get_entity(client);

	ent_player_set_displayed_skin_parts(player, pck_read_int8(packet));
	ent_player_set_main_hand(player, pck_read_var_int(packet));

	__attribute__((unused)) bool disable_text_filtering = pck_read_int8(packet);
	__attribute__((unused)) bool allow_server_listings = pck_read_int8(packet); // TODO use this

	return true;

}

bool phd_handle_click_window(ltg_client_t* client, pck_packet_t* packet) {

	const uint8_t window_id = pck_read_int8(packet);
	const __attribute__((unused)) int32_t state_id = pck_read_var_int(packet);
	const int16_t slot = pck_read_int16(packet);
	const int8_t button = pck_read_int8(packet);
	const int32_t mode = pck_read_var_int(packet);

	ent_player_t* player = ltg_client_get_entity(client);

	// TODO use API functions to do this
	with_lock (&player->living_entity.entity.lock) {

		struct {
			itm_item_t* slot;
			itm_item_t* target;
			uint8_t target_size;
			bool grabbable : 1;
			bool droppable : 1;
		} clicked = {
			.slot = NULL,
			.grabbable = false,
			.droppable = false
		};

		switch (window_id) {
			case 0: { // player inventory
				if (slot == -999) { // outside
					clicked.droppable = true;
				} else if (slot == -1) {
					clicked.droppable = false;
					clicked.grabbable = false;
				} else if (slot == 0) { // crafting output
					clicked.grabbable = true;
				} else if (slot <= 4) { // crafting input
					clicked.droppable = true;
					clicked.grabbable = true;
				} else if (slot <= 8) { // armor
					// TODO variable droppable and grabbable based on hand item
					clicked.slot = &player->living_entity.armor[slot - 5];
				} else if (slot <= 35) { // main inventory
					clicked.droppable = true;
					clicked.grabbable = true;
					clicked.slot = &player->inventory[slot - 9];
				} else if (slot <= 44) { // hotbar
					clicked.droppable = true;
					clicked.grabbable = true;
					clicked.slot = &player->hotbar[slot - 36];
				} else if (slot == 45) { // offhand
					clicked.droppable = true;
					clicked.grabbable = true;
					clicked.slot = &player->living_entity.off_hand;
				}

				switch (mode) {
					case 1: { // shift click
						if (slot >= 9 && slot <= 35) { // inventory
							// attempt to put it in the hotbar
							clicked.target = player->hotbar;
							clicked.target_size = 9;
						} else { // not inventory
							// attempt to put it in general inventory
							clicked.target = player->inventory;
							clicked.target_size = 27;
						}
					} break;
					case 6: { // double click

					} break;
					default: {
						// do absolutely nothing
					} break;
				}
			} break;
		}

		switch (mode) {
			case 0: { // normal clicks
				player->paint.count = 0;
				switch (button) {
					case 0: { // left click
						if (slot == -999) {
							// TODO drop stack
							itm_set_count(&player->carried, 0);
						} else {
							if (player->carried.type == mat_item_air) {
								if (clicked.grabbable) {
									player->carried = *clicked.slot;
									itm_set_count(clicked.slot, 0);
								}
							} else {
								if (clicked.slot != NULL) {
									if (clicked.slot->type == mat_item_air) {
										if (clicked.droppable) {
											*clicked.slot = player->carried;
											itm_set_count(&player->carried, 0);
										}
									} else {
										if (itm_is_similar(clicked.slot, &player->carried)) {
											if (clicked.droppable) {
												const uint8_t total = clicked.slot->count + player->carried.count;
												if (total > 64) {
													itm_set_count(clicked.slot, 64);
													itm_set_count(&player->carried, total - 64);
												} else {
													itm_set_count(clicked.slot, total);
													itm_set_count(&player->carried, 0);
												}
											}
										} else { // swap
											if (clicked.droppable && clicked.grabbable) {
												itm_item_t temp = player->carried;
												player->carried = *clicked.slot;
												*clicked.slot = temp;
											}
										}
									}
								}
							}
						}
					} break;
					case 1: { // right click
						if (slot == -999) {
							if (player->carried.type != mat_item_air) {
								// TODO drop one
								itm_set_count(&player->carried, player->carried.count - 1);
							}
						} else {
							if (player->carried.type == mat_item_air) { // take half
								if (clicked.grabbable) {
									player->carried = *clicked.slot;
									itm_set_count(&player->carried, (clicked.slot->count + 1) >> 1);
									itm_set_count(clicked.slot, clicked.slot->count >> 1);
								}
							} else { // drop one
								if (clicked.droppable) {
									if (clicked.slot->type == mat_item_air) {
										*clicked.slot = player->carried;
										itm_set_count(clicked.slot, 1);
										itm_set_count(&player->carried, player->carried.count - 1);
									} else {
										if (itm_is_similar(clicked.slot, &player->carried)) {
											if (clicked.slot->count < 64) {
												itm_set_count(clicked.slot, clicked.slot->count + 1);
												itm_set_count(&player->carried, player->carried.count - 1);
											}
										}
									}
								}
							}
						}
					} break;
				}
			} break;
			case 1: { // shift clicks
				if (clicked.grabbable) {
					itm_item_t* empty = NULL;

					for (uint8_t i = 0; i < clicked.target_size; ++i) {
						if (itm_is_similar(clicked.slot, &clicked.target[i])) {
							const uint8_t total = clicked.slot->count + clicked.target[i].count;
							if (total <= 64) {
								itm_set_count(&clicked.target[i], total);
								itm_set_count(clicked.slot, 0);
								break;
							} else {
								itm_set_count(&clicked.target[i], 64);
								itm_set_count(clicked.slot, total - 64);
							}
						} else if (empty == NULL && clicked.target[i].type == mat_item_air) {
							empty = &clicked.target[i];
						}
					}

					if (empty != NULL && clicked.slot->count > 0) {
						*empty = *clicked.slot;
						itm_set_count(clicked.slot, 0);
					}
				}
			} break;
			case 2: { // number keys
				if (clicked.slot != NULL && player->carried.type == mat_item_air) {

					// kick hacked clients trying to wreak havoc					
					if (button > 8) return false;

					itm_item_t* target = &player->hotbar[button];
					if (clicked.slot->type == mat_item_air) {
						if (clicked.droppable) {
							*clicked.slot = *target;
							itm_set_count(target, 0);
						}
					} else {
						if (clicked.grabbable) {
							if (target->type == mat_item_air) {
								*target = *clicked.slot;
								itm_set_count(clicked.slot, 0);
							} else {
								if (clicked.droppable) {
									itm_item_t temp = *target;
									*target = *clicked.slot;
									*clicked.slot = temp;
								}
							}
						}
					}
				}
			} break;
			case 3: { // middle click
				player->paint.count = 0;
				// TODO only defined by creative players
			} break;
			case 4: { // drop key
				if (clicked.grabbable) {
					switch (button) {
						case 0: { // drop single item
							if (clicked.slot->type != mat_item_air) {
								// TODO drop item
								itm_set_count(clicked.slot, clicked.slot->count - 1);
							}
						} break;
						case 1: { // drop item stack
							// TODO drop item stack
							itm_set_count(clicked.slot, 0);
						} break;
					}
				}
			} break;
			case 5: { // drag
				switch (button) {
					case 0:
					case 4:
					case 8: { // begin drag
						player->paint.count = 0;
					} break;
					case 1:
					case 5:
					case 9: { // add slot to drag
						if (clicked.droppable) {
							player->paint.elements[player->paint.count++] = clicked.slot;
						}
					} break;
					case 2: {
						const uint8_t per_slot = player->carried.count / player->paint.count;
						for (uint8_t i = 0; i < player->paint.count; ++i) {
							if (player->paint.elements[i]->type == mat_item_air) {
								*player->paint.elements[i] = player->carried;
								itm_set_count(player->paint.elements[i], per_slot);
								itm_set_count(&player->carried, player->carried.count - per_slot);
							} else {
								if (itm_is_similar(player->paint.elements[i], &player->carried)) {
									const uint8_t total = player->paint.elements[i]->count + per_slot;
									if (total > 64) {
										const uint8_t to_add = 64 - player->paint.elements[i]->count;
										itm_set_count(player->paint.elements[i], 64);
										itm_set_count(&player->carried, player->carried.count - to_add);
									} else {
										itm_set_count(player->paint.elements[i], player->paint.elements[i]->count + per_slot);
										itm_set_count(&player->carried, player->carried.count - per_slot);
									}
								}
							}
						}
					} break;
					case 6: {
						for (uint8_t i = 0; i < player->paint.count && player->carried.count > 0; ++i) {
							if (player->paint.elements[i]->type == mat_item_air) {
								*player->paint.elements[i] = player->carried;
								itm_set_count(player->paint.elements[i], 1);
								itm_set_count(&player->carried, player->carried.count - 1);
							} else {
								if (itm_is_similar(player->paint.elements[i], &player->carried)) {
									if (player->paint.elements[i]->count != 64) {
										itm_set_count(player->paint.elements[i], player->paint.elements[i]->count + 1);
										itm_set_count(&player->carried, player->carried.count - 1);
									}
								}
							}
						}
					} break;
					case 10: { // paint clone
						// TODO only defined for creative players
					} break;
				}
			} break;
			case 6: { // double click

			} break;
		}

	}

	itm_item_t item;

	int32_t len = pck_read_var_int(packet);
	for (int32_t i = 0; i < len; ++i) {
		__attribute__((unused)) int16_t item_slot = pck_read_int16(packet);
		itm_from_packet(packet, &item);
	}

	itm_from_packet(packet, &item);
	
	// TODO remove this
	phd_send_player_inventory(client);

	return true;

}

bool phd_handle_close_window(__attribute__((unused)) ltg_client_t* client, pck_packet_t* packet) {

	// TODO actually do stuff
	__attribute__((unused)) uint8_t window_id = pck_read_int8(packet);

	return true;

}

bool phd_handle_plugin_message(__attribute__((unused)) ltg_client_t* client, pck_packet_t* packet) {

	PCK_READ_STRING(channel, packet);

	int32_t payload_length = packet->sub_length - (1 + io_var_int_length(channel_length) + channel_length);
	byte_t payload[payload_length];
	pck_read_bytes(packet, payload, payload_length);

	switch(utl_hash(channel)) {
		default:
			break;
	}

	return true;

}

bool phd_handle_keep_alive(ltg_client_t* client, pck_packet_t* packet) {

	int64_t out_ms = pck_read_int64(packet);

	struct timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
	ltg_client_set_last_receive(client, time.tv_sec * 1000 + time.tv_nsec / 0xF4240);

	ltg_client_set_ping(client, ltg_client_get_last_receive(client) - out_ms);

	return true;

}

bool phd_handle_player_position(ltg_client_t* client, pck_packet_t* packet) {

	ent_entity_t* entity = ent_player_get_entity(ltg_client_get_entity(client));

	const float64_t x = pck_read_float64(packet);
	const float64_t y = pck_read_float64(packet);
	const float64_t z = pck_read_float64(packet);
	const bool on_ground = pck_read_int8(packet);

	const float64_t d_x = x - ent_get_x(entity);
	const float64_t d_y = y - ent_get_y(entity);
	const float64_t d_z = z - ent_get_z(entity);

	ent_move(entity, d_x, d_y, d_z, on_ground);

	/*
	if (old_chunk != player->living_entity.entity.chunk) {

		phd_send_update_view_position(client);
		phd_update_sent_chunks_move(old_chunk, client);

	}
	*/

	return true;

}

bool phd_handle_player_position_and_look(ltg_client_t* client, pck_packet_t* packet) {

	ent_living_entity_t* player = ent_player_get_le(ltg_client_get_entity(client));

	const float64_t x = pck_read_float64(packet);
	const float64_t y = pck_read_float64(packet);
	const float64_t z = pck_read_float64(packet);
	
	const float32_t yaw = pck_read_float32(packet);
	const float32_t pitch = pck_read_float32(packet);

	const bool on_ground = pck_read_int8(packet);

	const float64_t d_x = x - ent_get_x(ent_le_get_entity(player));
	const float64_t d_y = y - ent_get_y(ent_le_get_entity(player));
	const float64_t d_z = z - ent_get_z(ent_le_get_entity(player));

	ent_le_move_look(player, d_x, d_y, d_z, yaw, pitch, on_ground);

	/*if (old_chunk != player->living_entity.entity.chunk) {

		phd_send_update_view_position(client);
		phd_update_sent_chunks_move(old_chunk, client);

	}*/
	
	return true;

}

bool phd_handle_player_rotation(ltg_client_t* client, pck_packet_t* packet) {

	ent_living_entity_t* player = ent_player_get_le(ltg_client_get_entity(client));

	const float32_t yaw = pck_read_float32(packet);
	const float32_t pitch = pck_read_float32(packet);

	const bool on_ground = pck_read_int8(packet);

	ent_le_look(player, yaw, pitch, on_ground);

	return true;

}

bool phd_handle_player_movement(ltg_client_t* client, pck_packet_t* packet) {

	ent_entity_t* player = ent_player_get_entity(ltg_client_get_entity(client));

	const bool on_ground = pck_read_int8(packet);

	ent_set_on_ground(player, on_ground);

	return true;

}

bool phd_handle_player_digging(ltg_client_t* client, pck_packet_t* packet) {

	const int32_t status = pck_read_var_int(packet);
	const pck_position_t position =  pck_read_position(packet);
	__attribute__((unused)) const wld_face_t face = pck_read_int8(packet);

	ent_player_t* player = ltg_client_get_entity(client);
	wld_chunk_t* chunk = ent_get_chunk(ent_player_get_entity(player));

	switch (status) {
		case 0: { // start digging
			if (!ent_player_is_digging_block(player)) {
				ent_player_start_digging_block(player,
					sch_schedule(
						job_new(
							job_dig_block,
							(job_payload_t) {
								.dig_block = {
									.client = client,
									.chunk = chunk,
									.x = position.x,
									.y = position.y,
									.z = position.z,
								}
							}),
						ent_player_get_break_speed(
							player,
							wld_get_block_type_at(chunk, position.x, position.y, position.z)
						)
					)
				);
			} else {
				return false;
			}
		} break;
		case 1: { // cancel digging
			if (ent_player_is_digging_block(player)) {
				ent_player_cancel_digging_block(player);
			}
		} break;
		case 2: { // finished digging
			// not really much to do, it's the server that determines when this is done
			// (unless were not digging then we gotta send that it was bad to resynchronize client)
		} break;
		case 3: { // drop item stack

		} break;
		case 4: { // drop item

		} break;
		case 5: { // shoot arrow / finish eating

		} break;
		case 6: { // swap item in hands

		} break;
	}

	return true;

}

bool phd_handle_entity_action(ltg_client_t* client, pck_packet_t* packet) {

	ent_entity_t* player = ent_player_get_entity(ltg_client_get_entity(client));

	// at this point, i have no idea what the client is doing
	// it should send its own entity id
	if (ent_get_id(player) != (uint32_t) pck_read_var_int(packet)) {
		return false;
	}

	int32_t action = pck_read_var_int(packet);
	__attribute__((unused)) int32_t jump_boost = pck_read_var_int(packet); // for jumping with horses

	switch (action) {
		case 0: { // start sneaking
			ent_set_crouching(player, true);
		} break;
		case 1: { // stop sneaking
			ent_set_crouching(player, false);
		} break;
		case 2: { // leave bed
		
		} break;
		case 3: { // start sprinting
			ent_set_sprinting(player, true);
		} break;
		case 4: { // stop sprinting
			ent_set_sprinting(player, false);
		} break;
		case 5: { // start jump with horse
		
		} break;
		case 6: { // stop jump with horse
		
		} break;
		case 7: { // open horse inventory
		
		} break;
		case 8: { // start flying with elytra
			ent_set_flying_with_elytra(player, true);
		} break;
	}

	return true;

}

bool phd_handle_held_item_change(ltg_client_t* client, pck_packet_t* packet) {

	uint16_t slot = pck_read_int16(packet);
	
	ent_player_t* player = ltg_client_get_entity(client);

	ent_player_set_held_item(player, slot);

	return true;

}

bool phd_handle_animation(__attribute__((unused)) ltg_client_t* client, pck_packet_t* packet) {

	__attribute__((unused)) uint8_t hand = pck_read_var_int(packet);

	// TODO

	return true;

}

bool phd_handle_player_block_placement(ltg_client_t* client, pck_packet_t* packet) {

	const enum {
		main_hand = 0,
		off_hand = 1
	} hand = pck_read_var_int(packet);
	
	pck_position_t position =  pck_read_position(packet);
	
	const wld_face_t face = pck_read_var_int(packet);

	switch (face) {
		case wld_face_top: {
			position.y += 1;
		} break;
		case wld_face_bottom: {
			position.y -= 1;
		} break;
		case wld_face_north: {
			position.z -= 1;
		} break;
		case wld_face_south: {
			position.z += 1;
		} break;
		case wld_face_west: {
			position.x -= 1;
		} break;
		case wld_face_east: {
			position.x += 1;
		} break;
		default: {
			return false;
		}
	}

	__attribute__((unused)) const struct {
		float32_t x;
		float32_t y;
		float32_t z;
	} cursor = {
		.x = pck_read_float32(packet),
		.y = pck_read_float32(packet),
		.z = pck_read_float32(packet)
	};
	__attribute__((unused)) const bool inside_block = pck_read_int8(packet);

	ent_player_t* player = client->entity;

	itm_item_t* slot = NULL;

	with_lock (&player->living_entity.entity.lock) {

		switch (hand) {
			case main_hand: {
				slot = player->hotbar + player->held_item;
			} break;
			case off_hand: {
				slot = &player->living_entity.off_hand;
			} break;
		}

		const mat_item_t* item = mat_get_item_by_type(slot->type);
		
		if (item->block != mat_block_air) {

			wld_chunk_t* player_chunk = player->living_entity.entity.chunk;

			wld_set_block_type_at(player_chunk, position.x, position.y, position.z, item->block);

			itm_set_count(slot, slot->count - 1);

		} else {
			// tried to place air, interact with block TODO
		}

	}

	return true;

}

bool phd_handle_use_item(__attribute__((unused)) ltg_client_t* client, pck_packet_t* packet) {

	const __attribute__((unused)) enum {
		main_hand = 0,
		off_hand = 1
	} hand = pck_read_var_int(packet);

	return true;

}

void phd_send_spawn_player(ltg_client_t* client, ent_player_t* player) {

	PCK_INLINE(packet, 48, io_big_endian);

	pck_write_var_int(packet, 0x04);
	pck_write_var_int(packet, ent_get_id(ent_player_get_entity(player)));
	pck_write_bytes(packet, ent_player_get_uuid(player), 16);
	pck_write_float64(packet, ent_get_x(ent_player_get_entity(player)));
	pck_write_float64(packet, ent_get_y(ent_player_get_entity(player)));
	pck_write_float64(packet, ent_get_z(ent_player_get_entity(player)));
	pck_write_int8(packet, 0);
	pck_write_int8(packet, io_angle_to_byte(ent_le_get_pitch(ent_player_get_le(player))));

	ltg_send(client, packet);

}

void phd_send_server_difficulty(ltg_client_t* client) {

	PCK_INLINE(packet, 3, io_big_endian);

	pck_write_var_int(packet, 0x0e);
	pck_write_int8(packet, sky_get_difficulty());
	pck_write_int8(packet, 0); // difficulty locked

	ltg_send(client, packet);

}

void phd_send_chat_message(ltg_client_t* client, const char* message, size_t message_len, const ltg_uuid_t uuid) {

	PCK_INLINE(packet, 23 + message_len, io_big_endian);

	pck_write_var_int(packet, 0x0F);
	pck_write_string(packet, message, message_len);
	pck_write_int8(packet, 0); // position
	pck_write_bytes(packet, uuid, 16);

	ltg_send(client, packet);

}

void phd_send_system_chat_message(ltg_client_t* client, const char* message, size_t message_len) {

	PCK_INLINE(packet, 23 + message_len, io_big_endian);

	pck_write_var_int(packet, 0x0F);
	pck_write_string(packet, message, message_len);
	pck_write_int8(packet, 1); // position
	pck_write_int64(packet, 0); // sender
	pck_write_int64(packet, 0);
	
	ltg_send(client, packet);

}

void phd_send_declare_commands(ltg_client_t* client) {

	ltg_send(client, cmd_get_graph());

}

void phd_send_player_inventory(ltg_client_t* client) {

	ent_player_t* player = ltg_client_get_entity(client);

	PCK_INLINE(packet, 1024, io_big_endian);

	pck_write_var_int(packet, 0x14);

	pck_write_int8(packet, 0); // window id = player inventory
	pck_write_var_int(packet, 0); // state id

	pck_write_var_int(packet, 46);
	
	ent_player_serialize_inventory(player, packet);

	ltg_send(client, packet);

}

void phd_send_plugin_message(ltg_client_t* client, const char* identifier, size_t identifier_length, const byte_t* data, size_t data_length) {

	PCK_INLINE(packet, 6 + identifier_length + data_length, io_big_endian);
	
	pck_write_var_int(packet, 0x18);
	pck_write_string(packet, identifier, identifier_length);
	pck_write_bytes(packet, data, data_length);

	ltg_send(client, packet);

}

void phd_send_disconnect(ltg_client_t* client, const char* message, size_t message_len) {

	PCK_INLINE(packet, 1 + message_len, io_big_endian);

	pck_write_var_int(packet, 0x1a);
	pck_write_string(packet, message, message_len);

	ltg_send(client, packet);

}

void phd_send_entity_status(ltg_client_t* client, ent_entity_t* entity, uint8_t status) {

	PCK_INLINE(packet, 6, io_big_endian);

	pck_write_var_int(packet, 0x1b);
	pck_write_int32(packet, ent_get_id(entity));
	pck_write_int8(packet, status);

	ltg_send(client, packet);

}

void phd_send_unload_chunk(ltg_client_t* client, wld_chunk_t* chunk) {
	
	PCK_INLINE(packet, 9, io_big_endian);

	pck_write_var_int(packet, 0x1d);
	pck_write_int32(packet, wld_get_chunk_x(chunk));
	pck_write_int32(packet, wld_get_chunk_z(chunk));

	ltg_send(client, packet);

}

void phd_send_initialize_world_border(ltg_client_t* client, __attribute__((unused)) wld_world_t* world) {

	PCK_INLINE(packet, 57, io_big_endian);

	pck_write_var_int(packet, 0x20);
	// TODO verify these fields, make them change by world
	pck_write_float64(packet, 0);
	pck_write_float64(packet, 0);
	pck_write_float64(packet, 59999968);
	pck_write_float64(packet, 59999968);
	pck_write_var_long(packet, 0);
	pck_write_var_int(packet, 29999984);
	pck_write_var_int(packet, 10);
	pck_write_var_int(packet, 5);

	ltg_send(client, packet);

}

void phd_send_keep_alive(ltg_client_t* client, uint64_t id) {

	PCK_INLINE(packet, 9, io_big_endian);

	pck_write_var_int(packet, 0x21);
	pck_write_int64(packet, id);

	ltg_send(client, packet);

}

struct {
	pck_packet_t* packet;
	pthread_mutex_t lock;
} phd_chunk_packet = {
	.packet = NULL,
	.lock = PTHREAD_MUTEX_INITIALIZER
};

// This is one chunky function, optimize it if possible TODO
void phd_send_chunk_data_and_update_light(ltg_client_t* client, wld_chunk_t* chunk) {

	with_lock (&phd_chunk_packet.lock) {

		if (phd_chunk_packet.packet == NULL) {
			phd_chunk_packet.packet = pck_create(262144, io_big_endian);
		}

		pck_packet_t* packet = phd_chunk_packet.packet;

		packet->cursor = 0;
		
		pck_write_var_int(packet, 0x22);
		pck_write_int32(packet, wld_get_chunk_x(chunk));
		pck_write_int32(packet, wld_get_chunk_z(chunk));

		// CHUNK MASK

		/*
		const uint16_t chunk_mask_length = ((chunk_height - 1) >> 6) + 1;
		pck_write_var_int(packet, chunk_mask_length);
		int64_t primary_chunk_mask[chunk_mask_length];
		memset(primary_chunk_mask, 0, sizeof(primary_chunk_mask));
		for (uint16_t i = 0; i < chunk_height; ++i) {
			if (wld_chunk_section_get_block_count(wld_chunk_get_section(chunk, i)) != 0) {
				primary_chunk_mask[i >> 6] |= (1 << (i & 0x3f));
			}
		}
		for (uint16_t i = 0; i < chunk_mask_length; ++i) {
			pck_write_int64(packet, primary_chunk_mask[i]);
		}*/

		/*
		int32_t primary_chunk_mask = 0;
		for (uint16_t i = 0; i < chunk_height; ++i) {
			if (chunk->sections[i].block_count != 0) {
				primary_chunk_mask |= (1 << i);
			}
		}
		pck_write_var_int(packet, primary_chunk_mask);
		*/

		// HEIGHTMAP
		
		const uint16_t chunk_height = mat_get_chunk_height(wld_get_environment(wld_chunk_get_world(chunk)));

		const uint8_t bits_per_heightmap = ceil(log2((chunk_height << 4) + 1));
		const uint32_t heightmap_size = 1 + (255 / (64 / bits_per_heightmap));
		int64_t motion_blocking[heightmap_size];
		int64_t world_surface[heightmap_size];

		utl_encode_shorts_to_longs(wld_chunk_get_highest_motion_blocking(chunk), 256, bits_per_heightmap, motion_blocking);
		utl_encode_shorts_to_longs(wld_chunk_get_highest_world_surface(chunk), 256, bits_per_heightmap, world_surface);

		// create heightmap
		mnbt_doc* doc = mnbt_new();
		mnbt_tag* tag = mnbt_new_tag(doc, UTL_CSTRTOARG(""), MNBT_COMPOUND, mnbt_val_compound());
		mnbt_push_tag(tag, mnbt_new_tag(doc, UTL_CSTRTOARG("MOTION_BLOCKING"), MNBT_LONG_ARRAY, mnbt_val_long_array(motion_blocking, heightmap_size)));
		mnbt_push_tag(tag, mnbt_new_tag(doc, UTL_CSTRTOARG("WORLD_SURFACE"), MNBT_LONG_ARRAY, mnbt_val_long_array(world_surface, heightmap_size)));
		mnbt_set_root(doc, tag);

		pck_write_nbt(packet, doc);

		mnbt_free(doc);

		// BIOMES

		/*
		pck_write_var_int(packet, chunk_height << 6);

		for (uint16_t i = 0; i < chunk_height; ++i) {
			for (uint8_t x = 0; x < 4; ++x) {
				for (uint8_t z = 0; z < 4; ++z) {
					for (uint8_t y = 0; y < 4; ++y) {
						pck_write_var_int(packet, wld_chunk_section_get_biome(wld_chunk_get_section(chunk, i), x, y, z));
					}
				}
			}
		}
		*/

		// CHUNK DATA

		// am i really gonna waste time copying data from one stream to another or am i gonna just waste 4 bytes?
		// you're damn right i'm gonna waste 4 bytes, speed is key
		const size_t data_len = packet->cursor;
		packet->cursor += 5;

		for (uint16_t i = 0; i < chunk_height; ++i) {

			const uint16_t block_count = wld_chunk_section_get_block_count(wld_chunk_get_section(chunk, i));

			pck_write_int16(packet, block_count);

			// block state array
			if (block_count > 0) {
				struct {
					mat_block_protocol_id_t array[256];
					uint8_t length;
				} palette = {
					.length = 1
				};
				palette.array[0] = wld_chunk_section_get_blocks(wld_chunk_get_section(chunk, i))[0];
				
				int8_t block_array[4096];

				struct {
					mat_block_protocol_id_t block;
					uint16_t palette;
				} previous = {
					.block = palette.array[0],
					.palette = 0
				};

				for (uint16_t j = 0; j < 4096; ++j) {

					const mat_block_protocol_id_t block = wld_chunk_section_get_blocks(wld_chunk_get_section(chunk, i))[j];
					if (block == previous.block) {
						block_array[j] = previous.palette;
					} else {
						// test if block is in palette
						for (uint8_t k = 0; k < palette.length; ++k) {
							if (palette.array[k] == block) {
								block_array[j] = previous.palette = k;
								previous.block = block;

								goto end;
							}
						}

						// add to palette (it hasn't been found)
						if (palette.length < 255) {
							palette.array[palette.length] = block;
							block_array[j] = previous.palette = palette.length++;
							previous.block = block;
						} else {
							// palette is too big, use direct
							break;
						}
					}
					end:{}
				}

				if (palette.length == 1) {
					pck_write_int8(packet, 0);
					pck_write_var_int(packet, palette.array[0]);
					pck_write_var_int(packet, 0);
				} else if (palette.length < 255) {
					// use palette
					uint8_t bits_per_block;
					if (palette.length < 17) {
						bits_per_block = 4;
					} else if (palette.length < 33) {
						bits_per_block = 5;
					} else if (palette.length < 65) {
						bits_per_block = 6;
					} else if (palette.length < 129) {
						bits_per_block = 7;
					} else {
						bits_per_block = 8;
					}
					const uint8_t blocks_per_long = 64 / bits_per_block;
					const int32_t data_array_length = 1 + (4095 / blocks_per_long);

					pck_write_int8(packet, bits_per_block);
					pck_write_var_int(packet, palette.length);
					for (uint8_t j = 0; j < palette.length; ++j) {
						pck_write_var_int(packet, palette.array[j]);
					}

					pck_write_var_int(packet, data_array_length);
					
					utl_encode_bytes_to_longs_r(block_array, 4096, bits_per_block, (int64_t*) pck_cursor(packet));
					packet->cursor += data_array_length << 3;
				} else {
					// direct
					const uint8_t bits_per_block = 15; // log2(block_state_count)
					const uint8_t blocks_per_long = 64 / bits_per_block;
					const int32_t data_array_length = 1 + (4095 / blocks_per_long);

					pck_write_int8(packet, bits_per_block);
					pck_write_var_int(packet, data_array_length); // data array length
					
					utl_encode_shorts_to_longs_r((int16_t*) wld_chunk_section_get_blocks(wld_chunk_get_section(chunk, i)), 4096, bits_per_block, (int64_t*) pck_cursor(packet));
					packet->cursor += data_array_length << 3;
				}
			} else {
				pck_write_int8(packet, 0);
				pck_write_var_int(packet, mat_get_block_default_protocol_id_by_type(mat_block_air));
				pck_write_var_int(packet, 0);
			}
			// biome array
			{
				struct {
					mat_biome_type_t array[64];
					uint8_t length;
				} palette = {
					.length = 1
				};
				palette.array[0] = wld_chunk_section_get_biomes(wld_chunk_get_section(chunk, i))[0];

				int8_t biome_array[64];

				struct {
					mat_biome_type_t biome;
					uint16_t palette;
				} previous = {
					.biome = palette.array[0],
					.palette = 0
				};

				for (uint16_t j = 0; j < 64; ++j) {

					const mat_biome_type_t biome = wld_chunk_section_get_biomes(wld_chunk_get_section(chunk, i))[j];
					if (biome == previous.biome) {
						biome_array[j] = previous.palette;
					} else {
						// test if block is in palette
						for (uint8_t k = 0; k < palette.length; ++k) {
							if (palette.array[k] == biome) {
								biome_array[j] = previous.palette = k;
								previous.biome = biome;

								goto endb;
							}
						}

						// add to palette (it hasn't been found)
						if (palette.length < 8) {
							palette.array[palette.length] = biome;
							biome_array[j] = previous.palette = palette.length++;
							previous.biome = biome;
						} else {
							// palette is too big, use direct
							break;
						}
					}
					endb:{}
				}

				if (palette.length == 1) {
					pck_write_int8(packet, 0);
					pck_write_var_int(packet, palette.array[0]);
					pck_write_var_int(packet, 0);
				} else if (palette.length < 9) {
					// use palette
					uint8_t bits_per_biome;
					if (palette.length < 3) {
						bits_per_biome = 1;
					} else if (palette.length < 5) {
						bits_per_biome = 2;
					} else {
						bits_per_biome = 3;
					}
					const uint8_t biomes_per_long = 64 / bits_per_biome;
					const int32_t data_array_length = 1 + (63 / biomes_per_long);

					pck_write_int8(packet, bits_per_biome);
					pck_write_var_int(packet, palette.length);
					for (uint8_t j = 0; j < palette.length; ++j) {
						pck_write_var_int(packet, palette.array[j]);
					}

					pck_write_var_int(packet, data_array_length);
					
					utl_encode_bytes_to_longs_r(biome_array, 64, bits_per_biome, (int64_t*) pck_cursor(packet));
					packet->cursor += data_array_length << 3;
				} else {
					// direct
					const uint8_t bits_per_biome = 4; // log2(biome_count)
					const uint8_t biomes_per_long = 64 / bits_per_biome;
					const int32_t data_array_length = 1 + (63 / biomes_per_long);

					pck_write_int8(packet, bits_per_biome);
					pck_write_var_int(packet, data_array_length); // data array length
					
					utl_encode_bytes_to_longs_r((int8_t*) wld_chunk_section_get_biomes(wld_chunk_get_section(chunk, i)), 64, bits_per_biome, (int64_t*) pck_cursor(packet));
					packet->cursor += data_array_length << 3;
				}
			}
		}

		const size_t current = packet->cursor;
		packet->cursor = data_len;
		pck_write_long_var_int(packet, current - data_len - 5);
		packet->cursor = current;

		// BLOCK ENTITIES
		// TODO block entities
		pck_write_var_int(packet, 0);

		// light
		pck_write_int8(packet, true); // trust edges

		pck_write_var_int(packet, 0); // sky light mask length

		pck_write_var_int(packet, 0); // block light mask length

		pck_write_var_int(packet, 0); // empty sky light mask length

		pck_write_var_int(packet, 0); // empty block light mask length

		pck_write_var_int(packet, 0); // sky light array count

		pck_write_var_int(packet, 0); // block light array count

		ltg_send(client, packet);

	}

}

void phd_send_update_light(ltg_client_t* client, wld_chunk_t* chunk) {

	PCK_INLINE(packet, 8192, io_big_endian);

	pck_write_var_int(packet, 0x25);
	pck_write_var_int(packet, wld_get_chunk_x(chunk));
	pck_write_var_int(packet, wld_get_chunk_z(chunk));

	pck_write_int8(packet, true); // trust edges
	
	pck_write_var_int(packet, 0); // sky light mask length

	pck_write_var_int(packet, 0); // block light mask length

	pck_write_var_int(packet, 0); // empty sky light mask length
	
	pck_write_var_int(packet, 0); // empty block light mask length
	
	pck_write_var_int(packet, 0); // sky light array count
	
	pck_write_var_int(packet, 0); // block light array count

	ltg_send(client, packet);

}

/**
 * @EntryPoint
 * This is the first function called in state play
 */
void phd_send_join_game(ltg_client_t* client) {

	wld_world_t* player_world = wld_get_default();

	// create an entity for the player
	ent_player_t* player = ent_alloc_player(ltg_client_get_uuid(client), player_world, wld_get_spawn_x(player_world), 256, wld_get_spawn_z(player_world));
	ltg_client_set_entity(client, player);
	ent_register_entity(ent_player_get_entity(player));

	// set last recieve packet to now
	struct timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
	ltg_client_set_last_receive(client, time.tv_sec * 1000 + time.tv_nsec / 0xF4240);

	client->keep_alive = sch_schedule_repeating(job_new(job_keep_alive, (job_payload_t) { .client = client }), 200, 200);

	const mat_codec_t* codec = mat_get_codec();
	const mat_codec_t* dimension_codec = mat_get_dimension_codec(wld_get_environment(player_world));

	PCK_INLINE(packet, codec->size + dimension_codec->size + 1024, io_big_endian);

	pck_write_var_int(packet, 0x26);
	pck_write_int32(packet, ent_get_id(ent_player_get_entity(player))); // entity ID
	pck_write_int8(packet, sky_is_hardcore());
	pck_write_int8(packet, sky_get_default_gamemode()); // TODO player gamemode
	pck_write_int8(packet, -1); // previous game mode

	// worlds
	uint16_t world_count = wld_get_count();
	pck_write_var_int(packet, world_count);
	for (size_t i = 0; i < world_count; ++i) {
		wld_world_t* world = wld_get_world(i);
		if (world != NULL) {
			pck_write_string(packet, world->name.value, world->name.length);
		} else {
			pck_write_string(packet, "", 0);
		}
	}

	pck_write_bytes(packet, codec->bytes, codec->size);
	pck_write_bytes(packet, dimension_codec->bytes, dimension_codec->size);

	pck_write_string(packet, player_world->name.value, player_world->name.length);
	
	// hash seed

	pck_write_int64(packet, wld_get_seed_hash(player_world)); // hashed seed
	
	pck_write_var_int(packet, ltg_get_online_max(sky_get_listener()));
	pck_write_var_int(packet, sky_get_render_distance()); // view distance
	pck_write_var_int(packet, sky_get_simulation_distance());
	pck_write_int8(packet, sky_is_reduced_debug_info()); // reduced debug info
	pck_write_int8(packet, sky_is_enabled_respawn_screen()); // enable respawn screen
	pck_write_int8(packet, wld_is_debug(player_world)); // is debug
	pck_write_int8(packet, wld_is_flat(player_world)); // is flat

	ltg_send(client, packet);

	// NORMAL LOGIN SEQUENCE
	phd_send_plugin_message(client, UTL_CSTRTOARG("minecraft:brand"), (const byte_t*) UTL_CSTRTOARG("\x07MotorMC"));
	phd_send_server_difficulty(client);
	phd_send_player_abilities(client);
	phd_send_held_item_change(client);
	phd_send_declare_recipes(client); // TODO should be cached
	phd_send_tags(client); // TODO should be cached
	phd_send_entity_status(client, ent_player_get_entity(player), 24); // TODO actual op level
	phd_send_declare_commands(client);
	phd_send_unlock_recipes(client);
	phd_send_player_position_and_look(client);
	phd_send_player_info_add_players(client);

	phd_send_update_view_position(client);
	phd_update_sent_chunks(client);

	phd_send_initialize_world_border(client, player_world);
	phd_send_time_update(client, player_world);
	phd_send_spawn_position(client);
	
	phd_send_player_position_and_look(client);

	phd_send_set_experience(client);
	phd_send_update_health(client);

	// TODO remove this, temporarily add two stacks of stone to inventory
	itm_set_type(&player->inventory[0], mat_item_stone);
	itm_set_count(&player->inventory[0], 64);
	itm_set_type(&player->inventory[1], mat_item_stone);
	itm_set_count(&player->inventory[1], 64);

	phd_send_player_inventory(client);

	// add to online players
	ltg_add_online(sky_get_listener(), client);

	job_add(job_new(job_player_join, (job_payload_t) { .client = client }));

}

void phd_send_entity_position(ltg_client_t* client, ent_entity_t* entity, float64_t d_x, float64_t d_y, float64_t d_z) {

	PCK_INLINE(packet, 13, io_big_endian);

	pck_write_var_int(packet, 0x29);

	pck_write_var_int(packet, ent_get_id(entity));
	pck_write_int16(packet, d_x * 4096);
	pck_write_int16(packet, d_y * 4096);
	pck_write_int16(packet, d_z * 4096);
	pck_write_int8(packet, ent_is_on_ground(entity));

	ltg_send(client, packet);

}

void phd_send_entity_position_and_rotation(ltg_client_t* client, ent_living_entity_t* entity, float64_t d_x, float64_t d_y, float64_t d_z) {

	PCK_INLINE(packet, 15, io_big_endian);

	pck_write_var_int(packet, 0x2a);

	pck_write_var_int(packet, ent_get_id(ent_le_get_entity(entity)));
	pck_write_int16(packet, d_x * 4096);
	pck_write_int16(packet, d_y * 4096);
	pck_write_int16(packet, d_z * 4096);
	pck_write_int8(packet, io_angle_to_byte(ent_le_get_yaw(entity)));
	pck_write_int8(packet, io_angle_to_byte(ent_le_get_pitch(entity)));
	pck_write_int8(packet, ent_is_on_ground(ent_le_get_entity(entity)));

	ltg_send(client, packet);

}

void phd_send_entity_rotation(ltg_client_t* client, ent_living_entity_t* entity) {
	
	PCK_INLINE(packet, 9, io_big_endian);

	pck_write_var_int(packet, 0x2b);

	pck_write_var_int(packet, ent_get_id(ent_le_get_entity(entity)));

	pck_write_int8(packet, io_angle_to_byte(ent_le_get_yaw(entity)));
	pck_write_int8(packet, io_angle_to_byte(ent_le_get_pitch(entity)));
	pck_write_int8(packet, ent_is_on_ground(ent_le_get_entity(entity)));

	ltg_send(client, packet);

}

void phd_send_player_abilities(ltg_client_t* client) {

	PCK_INLINE(packet, 10, io_big_endian);

	pck_write_var_int(packet, 0x32);
	pck_write_int8(packet, 0);
	pck_write_float32(packet, 0.05);
	pck_write_float32(packet, 0.1);

	ltg_send(client, packet);

}

void phd_send_death_combat_event(ltg_client_t* client, ent_player_t* player, ent_entity_t* killer, const char* message, size_t message_length) {

	PCK_INLINE(packet, 16 + message_length, io_big_endian);
	
	pck_write_var_int(packet, 0x35);
	pck_write_var_int(packet, ent_get_id(ent_player_get_entity(player)));
	if (killer != NULL) {
		pck_write_int32(packet, ent_get_id(killer));
	} else {
		pck_write_int32(packet, -1);
	}
	pck_write_string(packet, message, message_length);

	ltg_send(client, packet);

}

void phd_send_player_info_add_players(ltg_client_t* client) {

	uint32_t online_count = ltg_get_online_count(sky_get_listener());

	if (online_count == 0) {
		return;
	}

	PCK_INLINE(packet, 3 + (online_count * 2048), io_big_endian);

	pck_write_var_int(packet, 0x36);
	pck_write_var_int(packet, 0);
	pck_write_var_int(packet, online_count);

	
	const uint32_t online_length = ltg_get_online_length(sky_get_listener());
	for (uint32_t i = 0; i < online_length; ++i) {
		ltg_client_t* player = ltg_get_online_client(sky_get_listener(), i);
		if (player != NULL) {
			pck_write_bytes(packet, ltg_client_get_uuid(player), 16);
			pck_write_string(packet, UTL_STRTOARG(ltg_client_get_username(player)));
			if (ltg_client_has_textures(player)) {
				pck_write_var_int(packet, 1);
				pck_write_string(packet, UTL_CSTRTOARG("textures"));
				pck_write_string(packet, UTL_STRTOARG(ltg_client_get_textures(player)));
				if (ltg_client_has_textures_signature(player)) {
					pck_write_int8(packet, 1);
					pck_write_string(packet, UTL_STRTOARG(ltg_client_get_textures_signature(player)));
				} else {
					pck_write_int8(packet, 0);
				}
			} else {
				pck_write_var_int(packet, 0);
			}
			
			ent_player_t* player_ent = ltg_client_get_entity(player);

			pck_write_var_int(packet, ent_player_get_gamemode(player_ent)); // game mode
			
			pck_write_var_int(packet, ltg_client_get_ping(player)); // ping
			pck_write_int8(packet, 0); // has display name

			if (--online_count == 0) break;
		}
	}

	ltg_send(client, packet);

}

void phd_send_player_info_add_player(ltg_client_t* client, ltg_client_t* player) {

	PCK_INLINE(packet, 2048, io_big_endian);
	pck_write_var_int(packet, 0x36);
	pck_write_var_int(packet, 0); // action
	pck_write_var_int(packet, 1); // number of players
	pck_write_bytes(packet, ltg_client_get_uuid(player), 16);
	pck_write_string(packet, UTL_STRTOARG(ltg_client_get_username(player)));
	if (ltg_client_has_textures(player)) {
		pck_write_var_int(packet, 1);
		pck_write_string(packet, UTL_CSTRTOARG("textures"));
		pck_write_string(packet, UTL_STRTOARG(ltg_client_get_textures(player)));
		if (ltg_client_has_textures_signature(player)) {
			pck_write_int8(packet, true);
			pck_write_string(packet, UTL_STRTOARG(ltg_client_get_textures_signature(player)));
		} else {
			pck_write_int8(packet, false);
		}
	} else {
		pck_write_var_int(packet, 0);
	}
	ent_player_t* player_ent = ltg_client_get_entity(player);

	pck_write_var_int(packet, ent_player_get_gamemode(player_ent)); // game mode

	pck_write_var_int(packet, ltg_client_get_ping(player)); // ping

	pck_write_int8(packet, false); // has display name

	ltg_send(client, packet);

}

void phd_send_player_info_update_gamemode(__attribute__((unused)) ltg_client_t* client, __attribute__((unused)) ltg_client_t* player) {

}

void phd_send_player_info_update_latency(ltg_client_t* client) {

	uint32_t online_count = ltg_get_online_count(sky_get_listener());

	PCK_INLINE(packet, 21 * online_count + 6, io_big_endian);

	pck_write_var_int(packet, 0x36);
	pck_write_var_int(packet, 2); // update latency
	pck_write_var_int(packet, online_count);
	
	const uint32_t online_length = ltg_get_online_length(sky_get_listener());
	for (uint32_t i = 0; i < online_length; ++i) {
		ltg_client_t* player = ltg_get_online_client(sky_get_listener(), i);
		if (player != NULL) {
			pck_write_bytes(packet, ltg_client_get_uuid(player), 16);
			pck_write_var_int(packet, ltg_client_get_ping(player));

			if (--online_count == 0) break;
		}
	}

	ltg_send(client, packet);

}

void phd_send_player_info_update_display_name(__attribute__((unused)) ltg_client_t* client, __attribute__((unused)) ltg_client_t* player) {

}

void phd_send_player_info_remove_player(ltg_client_t* client, ltg_uuid_t uuid) {

	PCK_INLINE(packet, 19, io_big_endian);
	pck_write_var_int(packet, 0x36);
	pck_write_var_int(packet, 4);
	pck_write_var_int(packet, 1);
	pck_write_bytes(packet, uuid, 16);

	ltg_send(client, packet);

}

void phd_send_player_position_and_look(ltg_client_t* client) {

	PCK_INLINE(packet, 40, io_big_endian);

	ent_player_t* player = ltg_client_get_entity(client);

	pck_write_var_int(packet, 0x38);
	pck_write_float64(packet, ent_get_x(ent_player_get_entity(player))); // x
	pck_write_float64(packet, ent_get_y(ent_player_get_entity(player))); // y
	pck_write_float64(packet, ent_get_z(ent_player_get_entity(player))); // z
	pck_write_float32(packet, ent_le_get_yaw(ent_player_get_le(player))); // yaw
	pck_write_float32(packet, ent_le_get_pitch(ent_player_get_le(player))); // pitch
	pck_write_int8(packet, 0); // flags
	pck_write_var_int(packet, player->living_entity.entity.id); // teleport id
	pck_write_int8(packet, 0); // dismount vehicle

	ltg_send(client, packet);

}

void phd_send_unlock_recipes(ltg_client_t* client) {

	PCK_INLINE(packet, 128, io_big_endian);

	// TODO add seperate functions for different packets,
	// make this packet actually do something

	pck_write_var_int(packet, 0x39);

	pck_write_var_int(packet, 0); // action

	pck_write_int8(packet, false); // crafting recipe book open
	pck_write_int8(packet, false); // crafting recipe book filter active
	pck_write_int8(packet, false); // smelting recipe book open
	pck_write_int8(packet, false); // smelting recipe book filter active
	pck_write_int8(packet, false); // blast furnace recipe book open
	pck_write_int8(packet, false); // blast furnace recipe book filter active
	pck_write_int8(packet, false); // smoker recipe book open
	pck_write_int8(packet, false); // smoker recipe book filter active
	
	pck_write_var_int(packet, 0); // array 1

	pck_write_var_int(packet, 0); // array 2

	ltg_send(client, packet);

}

void phd_send_destroy_entity(ltg_client_t* client, ent_entity_t* entity) {

	PCK_INLINE(packet, 7, io_big_endian);

	pck_write_var_int(packet, 0x3a);
	pck_write_var_int(packet, 1);

	pck_write_var_int(packet, ent_get_id(entity));

	ltg_send(client, packet);

}

void phd_send_respawn(ltg_client_t* client, wld_world_t* world, bool keep_metadata) {

	const mat_codec_t* dimension_codec = mat_get_dimension_codec(wld_get_environment(world));

	PCK_INLINE(packet, 19 + dimension_codec->size + UTL_STRLEN(wld_get_name(world)), io_big_endian);

	pck_write_var_int(packet, 0x3d);
	pck_write_bytes(packet, dimension_codec->bytes, dimension_codec->size);
	pck_write_string(packet, UTL_STRTOARG(wld_get_name(world)));
	pck_write_int64(packet, wld_get_seed_hash(world));
	pck_write_int8(packet, ent_survival); // TODO actual gamemode
	pck_write_int8(packet, ent_survival);
	pck_write_int8(packet, wld_is_debug(world));
	pck_write_int8(packet, wld_is_flat(world));
	pck_write_int8(packet, keep_metadata);

	ltg_send(client, packet);

}

void phd_send_entity_head_look(ltg_client_t* client, ent_living_entity_t* entity) {

	PCK_INLINE(packet, 7, io_big_endian);

	pck_write_var_int(packet, 0x3e);
	pck_write_var_int(packet, ent_get_id(ent_le_get_entity(entity)));
	pck_write_int8(packet, io_angle_to_byte(ent_le_get_yaw(entity)));

	ltg_send(client, packet);

}

void phd_send_held_item_change(ltg_client_t* client) {
	
	PCK_INLINE(packet, 2, io_big_endian);

	ent_player_t* player = ltg_client_get_entity(client);

	pck_write_var_int(packet, 0x48);
	pck_write_int8(packet, ent_player_get_held_item(player));

	ltg_send(client, packet);

}

void phd_send_update_view_position(ltg_client_t* client) {
	
	PCK_INLINE(packet, 11, io_big_endian);

	ent_player_t* player = ltg_client_get_entity(client);

	wld_chunk_t* chunk = ent_get_chunk(ent_player_get_entity(player));

	assert(chunk != NULL);

	pck_write_var_int(packet, 0x49);
	pck_write_var_int(packet, wld_get_chunk_x(chunk));
	pck_write_var_int(packet, wld_get_chunk_z(chunk));

	ltg_send(client, packet);

}

void phd_send_update_view_position_to(ltg_client_t* client, int32_t x, int32_t z) {
	
	PCK_INLINE(packet, 11, io_big_endian);
	
	pck_write_var_int(packet, 0x49);
	pck_write_var_int(packet, x);
	pck_write_var_int(packet, z);

	ltg_send(client, packet);

}

void phd_send_spawn_position(ltg_client_t* client) {

	PCK_INLINE(packet, 13, io_big_endian);

	pck_write_var_int(packet, 0x4b);
	// TODO actual spawn position
	pck_write_int64(packet, 0); // position
	pck_write_float32(packet, 0); // angle

	ltg_send(client, packet);

}

void phd_send_set_experience(ltg_client_t* client) {

	PCK_INLINE(packet, 15, io_big_endian);

	pck_write_var_int(packet, 0x51);
	pck_write_float32(packet, 0);
	pck_write_var_int(packet, 0);
	pck_write_var_int(packet, 0);

	ltg_send(client, packet);

}

void phd_send_update_health(ltg_client_t* client) {

	// create 14 byte long big endian packet
	PCK_INLINE(packet, 14, io_big_endian);

	ent_player_t* player = ltg_client_get_entity(client);

	pck_write_var_int(packet, 0x52);
	pck_write_float32(packet, ent_le_get_health(ent_player_get_le(player)));
	pck_write_var_int(packet, ent_player_get_food(player));
	pck_write_float32(packet, ent_player_get_saturation(player));

	ltg_send(client, packet);

}

void phd_send_time_update(ltg_client_t* client, wld_world_t* world) {

	PCK_INLINE(packet, 17, io_big_endian);

	pck_write_var_int(packet, 0x59);
	pck_write_int64(packet, wld_get_age(world));
	if (wld_is_time_progressing(world)) {
		pck_write_int64(packet, wld_get_time(world));
	} else {
		pck_write_int64(packet, wld_get_time(world) * -1);
	}

	ltg_send(client, packet);

}

void phd_send_entity_teleport(ltg_client_t* client, ent_entity_t* entity) {
	
	PCK_INLINE(packet, 43, io_big_endian);

	pck_write_var_int(packet, 0x62);
	pck_write_var_int(packet, ent_get_id(entity));
	pck_write_float64(packet, ent_get_x(entity));
	pck_write_float64(packet, ent_get_y(entity));
	pck_write_float64(packet, ent_get_z(entity));

	pck_write_int8(packet, 0);
	pck_write_int8(packet, 0);
	pck_write_int8(packet, ent_is_on_ground(entity));

	ltg_send(client, packet);

}

void phd_send_living_entity_teleport(ltg_client_t* client, ent_living_entity_t* entity) {

	PCK_INLINE(packet, 43, io_big_endian);

	pck_write_var_int(packet, 0x62);
	pck_write_var_int(packet, ent_get_id(ent_le_get_entity(entity)));
	pck_write_float64(packet, ent_get_x(ent_le_get_entity(entity)));
	pck_write_float64(packet, ent_get_y(ent_le_get_entity(entity)));
	pck_write_float64(packet, ent_get_z(ent_le_get_entity(entity)));

	pck_write_int8(packet, io_angle_to_byte(ent_le_get_yaw(entity)));
	pck_write_int8(packet, io_angle_to_byte(ent_le_get_pitch(entity)));
	pck_write_int8(packet, ent_is_on_ground(ent_le_get_entity(entity)));

	ltg_send(client, packet);

}

void phd_send_declare_recipes(ltg_client_t* client) {

	PCK_INLINE(packet, 6 + rec_recipes.size * 128, io_big_endian);
	
	pck_write_var_int(packet, 0x66);
	pck_write_var_int(packet, rec_recipes.size);

	for (size_t i = 0; i < rec_recipes.size; ++i) {

		rec_serialize(packet, UTL_VECTOR_GET_AS(rec_recipe_t*, &rec_recipes, i));

	}

	ltg_send(client, packet);

}

void phd_send_tags(ltg_client_t* client) {

	PCK_INLINE(packet, 16384, io_big_endian);

	pck_write_var_int(packet, 0x67);
	pck_write_var_int(packet, 5);

	pck_write_string(packet, UTL_CSTRTOARG("minecraft:block"));
	pck_write_var_int(packet, mat_block_tag_count);

	for (int32_t i = 0; i < mat_block_tag_count; ++i) {
		pck_write_string(packet, UTL_STRTOARG(mat_block_tags[i]->identifier));
		pck_write_var_int(packet, mat_block_tags[i]->count);
		for (int32_t j = 0; j < mat_block_tags[i]->count; ++j) {
			pck_write_var_int(packet, mat_block_tags[i]->entries[j]);
		}
	}

	pck_write_string(packet, UTL_CSTRTOARG("minecraft:item"));
	pck_write_var_int(packet, mat_item_tag_count);

	for (int32_t i = 0; i < mat_item_tag_count; ++i) {
		pck_write_string(packet, UTL_STRTOARG(mat_item_tags[i]->identifier));
		pck_write_var_int(packet, mat_item_tags[i]->count);
		for (int32_t j = 0; j < mat_item_tags[i]->count; ++j) {
			pck_write_var_int(packet, mat_item_tags[i]->entries[j]);
		}
	}

	pck_write_string(packet, UTL_CSTRTOARG("minecraft:fluid"));
	pck_write_var_int(packet, mat_fluid_tag_count);

	for (int32_t i = 0; i < mat_fluid_tag_count; ++i) {
		pck_write_string(packet, UTL_STRTOARG(mat_fluid_tags[i]->identifier));
		pck_write_long_var_int(packet, mat_fluid_tags[i]->count);
		for (int32_t j = 0; j < mat_fluid_tags[i]->count; ++j) {
			pck_write_var_int(packet, mat_fluid_tags[i]->entries[j]);
		}
	}

	pck_write_string(packet, UTL_CSTRTOARG("minecraft:entity_type"));
	pck_write_var_int(packet, mat_entity_type_tag_count);

	for (int32_t i = 0; i < mat_entity_type_tag_count; ++i) {
		pck_write_string(packet, UTL_STRTOARG(mat_entity_type_tags[i]->identifier));
		pck_write_var_int(packet, mat_entity_type_tags[i]->count);
		for (int32_t j = 0; j < mat_entity_type_tags[i]->count; ++j) {
			pck_write_var_int(packet, mat_entity_type_tags[i]->entries[j]);
		}
	}

	pck_write_string(packet, UTL_CSTRTOARG("minecraft:game_event"));
	pck_write_var_int(packet, mat_game_event_tag_count);

	for (int32_t i = 0; i < mat_game_event_tag_count; ++i) {
		pck_write_string(packet, UTL_STRTOARG(mat_game_event_tags[i]->identifier));
		pck_write_var_int(packet, mat_game_event_tags[i]->count);
		for (int32_t j = 0; j < mat_game_event_tags[i]->count; ++j) {
			pck_write_var_int(packet, mat_game_event_tags[i]->entries[j]);
		}
	}

	ltg_send(client, packet);

}

void phd_update_sent_chunks(ltg_client_t* client) {

	const wld_chunk_t* chunk = ent_get_chunk(ent_player_get_entity(ltg_client_get_entity(client)));

	const uint8_t server_render_distance = sky_get_render_distance();
	const uint8_t client_render_distance = ltg_client_get_render_distance(client);

	const uint8_t server_simulation_distance = sky_get_simulation_distance();
	const uint8_t max_loop = UTL_MAX(server_render_distance, server_simulation_distance + 2);

	for (int16_t x = -max_loop; x <= max_loop; ++x) {
		for (int16_t z = -max_loop; z <= max_loop; ++z) {
			wld_chunk_t* v_c = wld_relative_chunk(chunk, x, z);
			const uint8_t distance = UTL_MAX(UTL_ABS(x), UTL_ABS(z));

			if (distance <= server_simulation_distance + 2) {
				if (distance <= server_simulation_distance) {
					wld_add_player_chunk(v_c, ltg_client_get_id(client), WLD_TICKET_TICK_ENTITIES);
				} else {
					wld_add_player_chunk(v_c, ltg_client_get_id(client), distance - server_simulation_distance + WLD_TICKET_TICK_ENTITIES);
				}
			}

			// subscribe to the chunk if it is in render distance
			if (distance <= client_render_distance) {
				phd_update_subscribe_chunk(client, v_c);
			}
		}
	}

}

void phd_update_sent_chunks_view_distance(ltg_client_t* client, uint8_t view_distance) {
	
	const wld_chunk_t* chunk = ent_get_chunk(ent_player_get_entity(ltg_client_get_entity(client)));

	if (ltg_client_get_render_distance(client) > view_distance) {
		for (int16_t x = -ltg_client_get_render_distance(client); x <= ltg_client_get_render_distance(client); ++x) {
			for (int16_t z = -ltg_client_get_render_distance(client); z <= ltg_client_get_render_distance(client); ++z) {
				if (x < -view_distance || x > view_distance || z < -view_distance || z > view_distance) {
					wld_chunk_t* v_c = wld_relative_chunk(chunk, x, z);
					phd_update_unsubscribe_chunk(client, v_c);
				}
			}
		}
	} else if (ltg_client_get_render_distance(client) < view_distance) {
		for (int16_t x = -view_distance; x <= view_distance; ++x) {
			for (int16_t z = -view_distance; z <= view_distance; ++z) {
				if (x < -ltg_client_get_render_distance(client) || x > ltg_client_get_render_distance(client) || z < -ltg_client_get_render_distance(client) || z > ltg_client_get_render_distance(client)) {
					wld_chunk_t* v_c = wld_relative_chunk(chunk, x, z);
					phd_update_subscribe_chunk(client, v_c);
				}
			}
		}
	}

}

void phd_update_sent_chunks_move(ltg_client_t* client, const wld_chunk_t* old_chunk) {
	
	phd_send_update_view_position(client);

	const wld_chunk_t* chunk = ent_get_chunk(ent_player_get_entity(ltg_client_get_entity(client)));

	const int32_t x = wld_get_chunk_x(chunk);
	const int32_t z = wld_get_chunk_z(chunk);

	const int32_t old_x = wld_get_chunk_x(old_chunk);
	const int32_t old_z = wld_get_chunk_z(old_chunk);

	const uint8_t client_render_distance = ltg_client_get_render_distance(client);
	
	const uint8_t server_simulation_distance = sky_get_simulation_distance();

	assert(x != old_x || z != old_z);

	if (x > old_x) {
		
		{ // render chunks
			const int32_t o_x = -client_render_distance;
			const int32_t n_x = client_render_distance + 1;

			for (int32_t c_z = -client_render_distance; c_z <= client_render_distance; ++c_z) {
				phd_update_unsubscribe_chunk(client, wld_relative_chunk(old_chunk, o_x, c_z));
				phd_update_subscribe_chunk(client, wld_relative_chunk(old_chunk, n_x, c_z));
			}
		}

		{ // ticket chunks
			const int32_t o_x = -(server_simulation_distance + 2);
			const int32_t n_x = server_simulation_distance + 3;

			for (int32_t c_z = -(server_simulation_distance + 2); c_z <= server_simulation_distance + 2; ++c_z) {
				wld_remove_player_chunk(wld_relative_chunk(old_chunk, o_x, c_z), ltg_client_get_id(client));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, o_x + 1, c_z));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, o_x + 2, c_z));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, n_x - 2, c_z));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, n_x - 1, c_z));
				wld_add_player_chunk(wld_relative_chunk(old_chunk, n_x, c_z), ltg_client_get_id(client), WLD_TICKET_BORDER);
			}
		}

	} else if (x < old_x) {

		{
			const int32_t o_x = client_render_distance;
			const int32_t n_x = -client_render_distance - 1;

			for (int32_t c_z = -client_render_distance; c_z <= client_render_distance; ++c_z) {
				phd_update_unsubscribe_chunk(client, wld_relative_chunk(old_chunk, o_x, c_z));
				phd_update_subscribe_chunk(client, wld_relative_chunk(old_chunk, n_x, c_z));
			}
		}

		{ // ticket chunks
			const int32_t o_x = server_simulation_distance + 2;
			const int32_t n_x = -(server_simulation_distance + 3);

			for (int32_t c_z = -(server_simulation_distance + 2); c_z <= server_simulation_distance + 2; ++c_z) {
				wld_remove_player_chunk(wld_relative_chunk(old_chunk, o_x, c_z), ltg_client_get_id(client));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, o_x - 1, c_z));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, o_x - 2, c_z));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, n_x + 2, c_z));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, n_x + 1, c_z));
				wld_add_player_chunk(wld_relative_chunk(old_chunk, n_x, c_z), ltg_client_get_id(client), WLD_TICKET_BORDER);
			}
		}

	}

	if (z > old_z) {

		{
			const int32_t o_z = -client_render_distance;
			const int32_t n_z = client_render_distance + 1;
			
			for (int32_t c_x = -client_render_distance; c_x <= client_render_distance; ++c_x) {
				phd_update_unsubscribe_chunk(client, wld_relative_chunk(old_chunk, c_x, o_z));
				phd_update_subscribe_chunk(client, wld_relative_chunk(old_chunk, c_x, n_z));
			}
		}

		{ // ticket chunks
			const int32_t o_z = -(server_simulation_distance + 2);
			const int32_t n_z = server_simulation_distance + 3;

			for (int32_t c_x = -(server_simulation_distance + 2); c_x <= server_simulation_distance + 2; ++c_x) {
				wld_remove_player_chunk(wld_relative_chunk(old_chunk, c_x, o_z), ltg_client_get_id(client));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, c_x, o_z + 1));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, c_x, o_z + 2));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, c_x, n_z - 2));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, c_x, n_z - 1));
				wld_add_player_chunk(wld_relative_chunk(old_chunk, c_x, n_z), ltg_client_get_id(client), WLD_TICKET_BORDER);
			}
		}

	} else if (z < old_z) {

		{
			const int32_t o_z = client_render_distance;
			const int32_t n_z = -client_render_distance - 1;
			
			for (int32_t c_x = -client_render_distance; c_x <= client_render_distance; ++c_x) {
				phd_update_unsubscribe_chunk(client, wld_relative_chunk(old_chunk, c_x, o_z));
				phd_update_subscribe_chunk(client, wld_relative_chunk(old_chunk, c_x, n_z));
			}
		}

		{ // ticket chunks
			const int32_t o_z = server_simulation_distance + 2;
			const int32_t n_z = -(server_simulation_distance + 3);

			for (int32_t c_x = -(server_simulation_distance + 2); c_x <= server_simulation_distance + 2; ++c_x) {
				wld_remove_player_chunk(wld_relative_chunk(old_chunk, c_x, o_z), ltg_client_get_id(client));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, c_x, o_z - 1));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, c_x, o_z - 2));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, c_x, n_z + 2));
				wld_recalc_chunk_ticket(wld_relative_chunk(old_chunk, c_x, n_z + 1));
				wld_add_player_chunk(wld_relative_chunk(old_chunk, c_x, n_z), ltg_client_get_id(client), WLD_TICKET_BORDER);
			}
		}

	}

}

void phd_update_sent_chunks_teleport(ltg_client_t* client, const wld_chunk_t* old_chunk) {

	phd_send_update_view_position(client);

	// we don't want to send chunks when we don't need to because it is a lot more work than just checking if we are subscribed to it or it's in range

	ent_player_t* entity = ltg_client_get_entity(client);
	wld_chunk_t* chunk = ent_get_chunk(ent_player_get_entity(entity));

	if (wld_chunk_get_world(chunk) != wld_chunk_get_world(old_chunk)) {
		phd_update_sent_chunks_remove(client, old_chunk);
		phd_update_sent_chunks(client);
		return;
	}

	const int32_t x = wld_get_chunk_x(chunk);
	const int32_t z = wld_get_chunk_z(chunk);

	const int32_t old_x = wld_get_chunk_x(old_chunk);
	const int32_t old_z = wld_get_chunk_z(old_chunk);

	const uint8_t client_render_distance = ltg_client_get_render_distance(client);

	assert(x != old_x || z != old_z);

	// check for chunks that need to be unsubscribed from
	{ // old chunk
		for (int32_t c_x = -client_render_distance; c_x <= client_render_distance; ++c_x) {
			for (int32_t c_z = -client_render_distance; c_z <= client_render_distance; ++c_z) {
				wld_chunk_t* c_c = wld_relative_chunk(old_chunk, c_x, c_z);
				// test if in render distance
				if (UTL_MAX(UTL_ABS(c_x + old_x - x), UTL_ABS(c_z + old_z - z)) > client_render_distance) {
					// no longer in view
					phd_update_unsubscribe_chunk(client, c_c);
				}
			}
		}
	}

	{ // new chunk
		for (int32_t c_x = -client_render_distance; c_x <= client_render_distance; ++c_x) {
			for (int32_t c_z = -client_render_distance; c_z <= client_render_distance; ++c_z) {
				wld_chunk_t* c_c = wld_relative_chunk(chunk, c_x, c_z);
				if (!wld_chunk_has_subscriber(c_c, ltg_client_get_id(client))) {
					phd_update_subscribe_chunk(client, c_c);
				}
			}
		}
	}

	// TODO ticket chunks

}

void phd_update_sent_chunks_remove(ltg_client_t* client, const wld_chunk_t* chunk) {

	const uint8_t server_render_distance = sky_get_render_distance();
	const uint8_t client_render_distance = ltg_client_get_render_distance(client);
	
	const uint8_t server_simulation_distance = sky_get_simulation_distance();
	const uint8_t max_loop = UTL_MAX(server_render_distance, server_simulation_distance + 2);

	// player chunks
	for (int16_t x = -max_loop; x <= max_loop; ++x) {
		for (int16_t z = -max_loop; z <= max_loop; ++z) {
			wld_chunk_t* v_c = wld_relative_chunk(chunk, x, z);

			const uint8_t distance = UTL_MAX(UTL_ABS(x), UTL_ABS(z));
			
			if (distance <= server_simulation_distance + 2) {
				wld_remove_player_chunk(v_c, ltg_client_get_id(client));
			}

			if (distance <= client_render_distance) {
				phd_update_unsubscribe_chunk(client, v_c);
			}
		}
	}

}

void phd_update_sent_chunks_leave(ltg_client_t* client) {
	
	const wld_chunk_t* chunk = ent_get_chunk(ent_player_get_entity(ltg_client_get_entity(client)));

	phd_update_sent_chunks_remove(client, chunk);

}

void phd_update_respawn(ltg_client_t* client) {

	// TODO do something here
	ent_player_t* player = ltg_client_get_entity(client);
	
	player->living_entity.health = 20;
	
	wld_world_t* world = wld_get_default();

	phd_send_respawn(client, world, false);

	ent_le_teleport_look(ent_player_get_le(player), world, wld_get_spawn_x(world), 256, wld_get_spawn_z(world), 0, 0, true);

}