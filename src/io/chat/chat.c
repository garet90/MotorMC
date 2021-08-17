#include <stdarg.h>
#include "../../motor.h"
#include "../../util/util.h"
#include "../logger/logger.h"
#include "chat.h"

cht_component_t* cht_alloc() {

	cht_component_t* alloc = calloc(1, sizeof(cht_component_t));

	alloc->bold = UNSET;
	alloc->italic = UNSET;
	alloc->underlined = UNSET;
	alloc->strikethrough = UNSET;
	alloc->obfuscated = UNSET;
	alloc->heap = true;
	alloc->color = cht_no_color;

	return alloc;

}

cht_component_t* cht_from_json(mjson_val* obj) {

	cht_component_t* component = cht_alloc();

	for (uint32_t i = 0; i < mjson_get_size(obj); ++i) {
		mjson_property obj_property = mjson_obj_get(obj, i);
		switch (utl_hash(mjson_get_string(obj_property.label))) {
			case 0x7c9e690a: { // "text"
				size_t text_len = mjson_get_size(obj_property.value);
				component->text = malloc(text_len + 1);
				memcpy(component->text, mjson_get_string(obj_property.value), text_len);
				component->text[text_len] = '\0';
			} break;
			case 0x7c94b326: // "bold"
				if (mjson_get_boolean(obj_property.value)) {
					component->bold = true;
				} else {
					component->bold = false;
				}
				break;
			case 0x0536d35b: // "italic"
				if (mjson_get_boolean(obj_property.value)) {
					component->italic = true;
				} else {
					component->italic = false;
				}
				break;
			case 0xd635c50f: // "underlined"
				if (mjson_get_boolean(obj_property.value)) {
					component->underlined = true;
				} else {
					component->underlined = false;
				}
				break;
			case 0x10d72f78: // "strikethrough"
				if (mjson_get_boolean(obj_property.value)) {
					component->strikethrough = true;
				} else {
					component->strikethrough = false;
				}
				break;
			case 0xf1f68aa5: // "obfuscated"
				if (mjson_get_boolean(obj_property.value)) {
					component->obfuscated = true;
				} else {
					component->obfuscated = false;
				}
				break;
			case 0x0f3d3244: // "color"
				switch (utl_hash(mjson_get_string(obj_property.value))) {
					case 0x0f294442: // "black"
						component->color = cht_black;
						break;
					case 0x3fa0116e: // "dark_blue"
						component->color = cht_dark_blue;
						break;
					case 0x33ffc057: // "dark_green"
						component->color = cht_dark_green;
						break;
					case 0x3f9f9a4e: // "dark_aqua"
						component->color = cht_dark_cyan;
						break;
					case 0x01edd701: // "dark_red"
						component->color = cht_dark_red;
						break;
					case 0xc933d23e: // "dark_purple"
						component->color = cht_purple;
						break;
					case 0x7c97710b: // "gold"
						component->color = cht_gold;
						break;
					case 0x7c977c78: // "gray"
						component->color = cht_gray;
						break;
					case 0x3fa2e659: // "dark_gray"
						component->color = cht_dark_gray;
						break;
					case 0x7c94a78d: // "blue"
						component->color = cht_blue;
						break;
					case 0x0f871a56: // "green"
						component->color = cht_bright_green;
						break;
					case 0x7c94306d: // "aqua"
						component->color = cht_cyan;
						break;
					case 0x0b88a540: // "red"
						component->color = cht_red;
						break;
					case 0x519b36b4: // "light_purple"
						component->color = cht_pink;
						break;
					case 0x297ff6e1: // "yellow"
						component->color = cht_yellow;
						break;
					case 0x10a33986: // "white"
						component->color = cht_white;
						break;
					default:
						utl_read_hex_bytes((byte_t*) &component->color, mjson_get_string(obj_property.value), mjson_get_size(obj_property.value) >> 1);
						break;
				}
				break;
			case 0x94c4816d: { // "clickEvent"
				for (uint32_t j = 0; j < mjson_get_size(obj_property.value); ++j) {
					mjson_property click_event = mjson_obj_get(obj_property.value, j);
					switch (utl_hash(mjson_get_string(click_event.label))) {
						case 0xf1644d03: // "action"
							switch (utl_hash(mjson_get_string(click_event.value))) {
								case 0x8d4ed3c9: // "open_url"
									component->click_event.action = cht_open_url;
									break;
								case 0xb1115cb8: // "run_command"
									component->click_event.action = cht_run_command;
									break;
								case 0x5a851fe5: // "suggest_command"
									component->click_event.action = cht_suggest_command;
									break;
								case 0xb53cc547: // "change_page"
									component->click_event.action = cht_change_page;
									break;
								case 0x49c3dc71: // "copy_to_clipboard"
									component->click_event.action = cht_copy_to_clipboard;
									break;
							}
							break;
						case 0x108d5742: { // "value"
							size_t value_len = mjson_get_size(click_event.value);
							component->click_event.value = malloc(value_len + 1);
							memcpy(component->click_event.value, mjson_get_string(click_event.value), value_len);
							component->click_event.value[value_len] = '\0';
						} break;
					}
				}
			} break;
			case 0xb00f0f6b: { // "hoverEvent"
				for (uint32_t j = 0; j < mjson_get_size(obj_property.value); ++j) {
					mjson_property hover_event = mjson_obj_get(obj_property.value, j);
					switch (utl_hash(mjson_get_string(hover_event.label))) {
						case 0xf1644d03: // "action"
							switch (utl_hash(mjson_get_string(hover_event.value))) {
								case 0xbdd0756a: // "show_text"
									component->hover_event.action = cht_show_text;
									break;
								case 0xbdcaaa94: // "show_item"
									component->hover_event.action = cht_show_item;
									break;
								case 0x5166a222: // "show_entity"
									component->hover_event.action = cht_show_entity;
									break;
							}
							break;
						case 0x108d5742: { // "value"
							size_t value_len = mjson_get_size(hover_event.value);
							component->hover_event.value = malloc(value_len + 1);
							memcpy(component->hover_event.value, mjson_get_string(hover_event.value), value_len);
							component->hover_event.value[value_len] = '\0';
						} break;
					}
				}
			} break;
			case 0x0f667509: { // extra
				for (uint32_t i = 0; i < mjson_get_size(obj_property.value); ++i) {
					cht_component_t* extra = cht_from_json(mjson_arr_get(obj_property.value, i));
					cht_add_extra(component, extra);
				}
			} break;
		}
	}

	return component;

}

cht_component_t* cht_from_string(const char* str, size_t len) {

	mjson_doc* doc = mjson_read(str, len);

	cht_component_t* component = cht_from_json(mjson_get_root(doc));

	mjson_free(doc);

	return component;
	
}

void cht_jsonify(mjson_doc* doc, mjson_val* obj, const cht_component_t* component) {

	if (component->text != NULL)
		mjson_obj_add(obj, mjson_string(doc, "text", 4), mjson_string(doc, component->text, strlen(component->text)));

	if (component->bold != UNSET)
		mjson_obj_add(obj, mjson_string(doc, "bold", 4), mjson_boolean(doc, component->bold));

	if (component->italic != UNSET)
		mjson_obj_add(obj, mjson_string(doc, "italic", 6), mjson_boolean(doc, component->italic));

	if (component->underlined != UNSET)
		mjson_obj_add(obj, mjson_string(doc, "underlined", 10), mjson_boolean(doc, component->underlined));

	if (component->strikethrough != UNSET)
		mjson_obj_add(obj, mjson_string(doc, "strikethrough", 13), mjson_boolean(doc, component->strikethrough));
		
	if (component->obfuscated != UNSET)
		mjson_obj_add(obj, mjson_string(doc, "obfuscated", 10), mjson_boolean(doc, component->obfuscated));

	if (component->color != cht_no_color) {
		if (component->color <= 0xF) {
			const char* colors[] = {
				"black",
				"dark_blue",
				"dark_green",
				"dark_aqua",
				"dark_red",
				"dark_purple",
				"gold",
				"gray",
				"dark_gray",
				"blue",
				"green",
				"aqua",
				"red",
				"light_purple",
				"yellow",
				"white"
			};

			mjson_obj_add(obj, mjson_string(doc, "color", 5), mjson_string(doc, colors[component->color], strlen(colors[component->color])));
		} else {
			char color[8];
			// convert int to hex
			utl_write_byte_hex(color, ((byte_t*) &component->color)[0]);
			utl_write_byte_hex(color + 2, ((byte_t*) &component->color)[1]);
			utl_write_byte_hex(color + 4, ((byte_t*) &component->color)[2]);
			utl_write_byte_hex(color + 6, ((byte_t*) &component->color)[3]);

			mjson_obj_add(obj, mjson_string(doc, "color", 5), mjson_string(doc, color, 8));
		}
	}

	if (component->click_event.value != NULL) {

		const char* click_events[] = {
			"open_url",
			"run_command",
			"suggest_command",
			"change_page",
			"copy_to_clipboard"
		};

		mjson_val* click_event = mjson_obj(doc);

		mjson_obj_add(click_event, mjson_string(doc, "action", 6), mjson_string(doc, click_events[component->click_event.action], strlen(click_events[component->click_event.action])));
		mjson_obj_add(click_event, mjson_string(doc, "value", 5), mjson_string(doc, component->click_event.value, strlen(component->click_event.value)));

		mjson_obj_add(obj, mjson_string(doc, "clickEvent", 10), click_event);

	}

	if (component->hover_event.value != NULL) {

		const char* hover_events[] = {
			"show_text",
			"show_item",
			"show_entity"
		};

		mjson_val* hover_event = mjson_obj(doc);

		mjson_obj_add(hover_event, mjson_string(doc, "action", 6), mjson_string(doc, hover_events[component->hover_event.action], strlen(hover_events[component->hover_event.action])));
		mjson_obj_add(hover_event, mjson_string(doc, "value", 5), mjson_string(doc, component->hover_event.value, strlen(component->hover_event.value)));
		
		mjson_obj_add(obj, mjson_string(doc, "hoverEvent", 10), hover_event);

	}

	if (component->extra.size != 0) {

		mjson_val* extra = mjson_arr(doc);

		for (size_t i = 0; i < component->extra.size; ++i) {

			mjson_val* extra_obj = mjson_obj(doc);

			cht_jsonify(doc, extra_obj, UTL_VECTOR_GET_AS(cht_component_t*, &component->extra, i));

			mjson_arr_append(extra, extra_obj);

		}

		mjson_obj_add(obj, mjson_string(doc, "extra", 5), extra);

	}

}

size_t cht_write(const cht_component_t* component, char* message) {
	
	mjson_doc* doc = mjson_new();
	mjson_val* obj = mjson_obj(doc);
	mjson_set_root(doc, obj);

	cht_jsonify(doc, obj, component);

	size_t len = mjson_write(doc, message);

	mjson_free(doc);

	return len;

}

void cht_free(cht_component_t* component) {

	if (component->extra.size != 0) {
		for (uint32_t i = 0; i < component->extra.size; ++i) {
			cht_component_t* extra = UTL_VECTOR_GET_AS(cht_component_t*, &component->extra, i);
			cht_free(extra);
		}
		utl_vector_term(&component->extra);
	}

	if (component->heap) {
		
		if (component->text != NULL) {
			free(component->text);
		}

		if (component->click_event.value != NULL) {
			free(component->click_event.value);
		}

		if (component->hover_event.value != NULL) {
			free(component->hover_event.value);
		}

		free(component);

	}

}

size_t cht_server_list_ping(char* message) {

	mjson_doc* doc = mjson_new();
	mjson_val* obj = mjson_obj(doc);
	mjson_set_root(doc, obj);

	mjson_val* version = mjson_obj(doc);

	mjson_obj_add(version, mjson_string(doc, "name", 4), mjson_string(doc, "MotorMC " __MC_VER__, sizeof("MotorMC" __MC_VER__) - 1));
	mjson_obj_add(version, mjson_string(doc, "protocol", 8), mjson_int(doc, sky_main.protocol));

	mjson_obj_add(obj, mjson_string(doc, "version", 7), version);

	mjson_val* players = mjson_obj(doc);

	mjson_obj_add(players, mjson_string(doc, "max", 3), mjson_int(doc, sky_main.listener.online.max));
	
	pthread_mutex_lock(&sky_main.listener.online.lock);
	mjson_obj_add(players, mjson_string(doc, "online", 6), mjson_int(doc, sky_main.listener.online.list.length));
	
	// TODO limit sample to however long it's supposed to be
	if (sky_main.listener.online.list.length > 0) {
		mjson_val* sample = mjson_arr(doc);
		utl_doubly_linked_node_t* node = sky_main.listener.online.list.first;
		while (node != NULL) {
			ltg_client_t* player = node->element;
			mjson_val* val = mjson_obj(doc);
			mjson_obj_add(val, mjson_string(doc, "name", 4), mjson_string(doc, player->username.value, player->username.length));
			char uuid[37];
			ltg_uuid_to_string(player->uuid, uuid);
			mjson_obj_add(val, mjson_string(doc, "id", 2), mjson_string(doc, uuid, 36));
			mjson_arr_append(sample, val);
			node = node->next;
		}
		mjson_obj_add(players, mjson_string(doc, "sample", 6), sample);
	}
	pthread_mutex_unlock(&sky_main.listener.online.lock);

	mjson_obj_add(obj, mjson_string(doc, "players", 7), players);

	mjson_val* description = mjson_obj(doc);

	cht_jsonify(doc, description, sky_main.motd);

	mjson_obj_add(obj, mjson_string(doc, "description", 11), description);

	size_t len = mjson_write(doc, message);

	mjson_free(doc);

	return len;

}
