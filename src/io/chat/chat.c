#include <stdarg.h>
#include "../../motor.h"
#include "../../util/util.h"
#include "../../util/str_util.h"
#include "../logger/logger.h"
#include "chat.h"

cht_component_t* cht_alloc() {

	cht_component_t* alloc = malloc(sizeof(cht_component_t));
	memcpy(alloc, &cht_new, sizeof(cht_component_t));
	alloc->heap = true;

	return alloc;

}

cht_component_t* cht_from_json(mjson_val* obj) {

	cht_component_t* component = cht_alloc();

	const uint32_t obj_size = mjson_get_size(obj);
	for (uint32_t i = 0; i < obj_size; ++i) {
		mjson_property obj_property = mjson_obj_get(obj, i);
		switch (utl_hash(mjson_get_string(obj_property.label))) {
			case 0x7c9e690a: { // "text"
				const size_t text_len = mjson_get_size(obj_property.value);
				UTL_STRTOCSTR(component->text) = malloc(text_len + 1);
				component->text_heap = true;
				memcpy(UTL_STRTOCSTR(component->text), mjson_get_string(obj_property.value), text_len);
				UTL_STRTOCSTR(component->text)[text_len] = '\0';
				component->text.length = text_len;
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
				const uint32_t obj_property_size = mjson_get_size(obj_property.value);
				for (uint32_t j = 0; j < obj_property_size; ++j) {
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
							const size_t value_len = mjson_get_size(click_event.value);
							UTL_STRTOCSTR(component->click_event.value) = malloc(value_len + 1);
							component->click_event_heap = true;
							memcpy(UTL_STRTOCSTR(component->click_event.value), mjson_get_string(click_event.value), value_len);
							UTL_STRTOCSTR(component->click_event.value)[value_len] = '\0';
							component->click_event.value.length = value_len;
						} break;
					}
				}
			} break;
			case 0xb00f0f6b: { // "hoverEvent"
				const uint32_t obj_property_size = mjson_get_size(obj_property.value);
				for (uint32_t j = 0; j < obj_property_size; ++j) {
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
							UTL_STRTOCSTR(component->hover_event.value) = malloc(value_len + 1);
							component->hover_event_heap = true;
							memcpy(UTL_STRTOCSTR(component->hover_event.value), mjson_get_string(hover_event.value), value_len);
							UTL_STRTOCSTR(component->hover_event.value)[value_len] = '\0';
						} break;
					}
				}
			} break;
			case 0x0f667509: { // extra
				const uint32_t obj_property_size = mjson_get_size(obj_property.value);
				for (uint32_t j = 0; j < obj_property_size; ++j) {
					cht_component_t* extra = cht_from_json(mjson_arr_get(obj_property.value, j));
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

	if (UTL_STRTOCSTR(component->text) != NULL)
		mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("text")), mjson_string(doc, UTL_STRTOARG(component->text)));

	if (component->bold != UNSET)
		mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("bold")), mjson_boolean(doc, component->bold));

	if (component->italic != UNSET)
		mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("italic")), mjson_boolean(doc, component->italic));

	if (component->underlined != UNSET)
		mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("underlined")), mjson_boolean(doc, component->underlined));

	if (component->strikethrough != UNSET)
		mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("strikethrough")), mjson_boolean(doc, component->strikethrough));
		
	if (component->obfuscated != UNSET)
		mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("obfuscated")), mjson_boolean(doc, component->obfuscated));

	if (component->color != cht_no_color) {
		if (component->color <= 0xF) {
			const string_t colors[] = {
				UTL_CSTRTOSTR("black"),
				UTL_CSTRTOSTR("dark_blue"),
				UTL_CSTRTOSTR("dark_green"),
				UTL_CSTRTOSTR("dark_aqua"),
				UTL_CSTRTOSTR("dark_red"),
				UTL_CSTRTOSTR("dark_purple"),
				UTL_CSTRTOSTR("gold"),
				UTL_CSTRTOSTR("gray"),
				UTL_CSTRTOSTR("dark_gray"),
				UTL_CSTRTOSTR("blue"),
				UTL_CSTRTOSTR("green"),
				UTL_CSTRTOSTR("aqua"),
				UTL_CSTRTOSTR("red"),
				UTL_CSTRTOSTR("light_purple"),
				UTL_CSTRTOSTR("yellow"),
				UTL_CSTRTOSTR("white")
			};

			mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("color")), mjson_string(doc, UTL_STRTOARG(colors[component->color])));
		} else {
			char color[8];
			// convert int to hex
			utl_write_byte_hex(color, ((byte_t*) &component->color)[0]);
			utl_write_byte_hex(color + 2, ((byte_t*) &component->color)[1]);
			utl_write_byte_hex(color + 4, ((byte_t*) &component->color)[2]);
			utl_write_byte_hex(color + 6, ((byte_t*) &component->color)[3]);

			mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("color")), mjson_string(doc, color, sizeof(color)));
		}
	}

	if (UTL_STRTOCSTR(component->click_event.value) != NULL) {

		const string_t click_events[] = {
			UTL_CSTRTOSTR("open_url"),
			UTL_CSTRTOSTR("run_command"),
			UTL_CSTRTOSTR("suggest_command"),
			UTL_CSTRTOSTR("change_page"),
			UTL_CSTRTOSTR("copy_to_clipboard")
		};

		mjson_val* click_event = mjson_obj(doc);

		mjson_obj_add(click_event, mjson_string(doc, UTL_CSTRTOARG("action")), mjson_string(doc, UTL_STRTOARG(click_events[component->click_event.action])));
		mjson_obj_add(click_event, mjson_string(doc, UTL_CSTRTOARG("value")), mjson_string(doc, UTL_STRTOARG(component->click_event.value)));

		mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("clickEvent")), click_event);

	}

	if (UTL_STRTOCSTR(component->hover_event.value) != NULL) {

		const string_t hover_events[] = {
			UTL_CSTRTOSTR("show_text"),
			UTL_CSTRTOSTR("show_item"),
			UTL_CSTRTOSTR("show_entity")
		};

		mjson_val* hover_event = mjson_obj(doc);

		mjson_obj_add(hover_event, mjson_string(doc, UTL_CSTRTOARG("action")), mjson_string(doc, UTL_STRTOARG(hover_events[component->hover_event.action])));
		mjson_obj_add(hover_event, mjson_string(doc, UTL_CSTRTOARG("value")), mjson_string(doc, UTL_STRTOARG(component->hover_event.value)));
		
		mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("hoverEvent")), hover_event);

	}

	if (component->extra.size != 0) {

		mjson_val* extra = mjson_arr(doc);

		for (size_t i = 0; i < component->extra.size; ++i) {

			mjson_val* extra_obj = mjson_obj(doc);

			cht_jsonify(doc, extra_obj, UTL_VECTOR_GET_AS(cht_component_t*, &component->extra, i));

			mjson_arr_append(extra, extra_obj);

		}

		mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("extra")), extra);

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

size_t cht_write_old(const cht_component_t* component, char* message) {

	size_t len = 0;

	if (component->color <= 0xF) {
		len += sprintf(message, "\xa7%01x", component->color);
	}

	if (component->obfuscated == true) {
		len += sprintf(message, "\xa7k");
	}

	if (component->bold == true) {
		len += sprintf(message, "\xa7l");
	}

	if (component->strikethrough == true) {
		len += sprintf(message, "\xa7m");
	}

	if (component->underlined == true) {
		len += sprintf(message, "\xa7n");
	}

	if (component->italic == true) {
		len += sprintf(message, "\xa7o");
	}

	len += sprintf(message, "%s", UTL_STRTOCSTR(component->text));

	if (component->extra.size != 0) {

		for (size_t i = 0; i < component->extra.size; ++i) {

			len += cht_write_old(UTL_VECTOR_GET_AS(cht_component_t*, &component->extra, i), message + len);

		}

	}

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

	if (component->text_heap)
		free(component->text.value);

	if (component->insertion_heap)
		free(component->insertion.value);

	if (component->click_event_heap)
		free(component->click_event.value.value);
	
	if (component->hover_event_heap)
		free(component->hover_event.value.value);

	if (component->heap)
		free(component);

}

size_t cht_server_list_ping(char* message) {

	mjson_doc* doc = mjson_new();
	mjson_val* obj = mjson_obj(doc);
	mjson_set_root(doc, obj);

	mjson_val* version = mjson_obj(doc);

	mjson_obj_add(version, mjson_string(doc, UTL_CSTRTOARG("name")), mjson_string(doc, UTL_CSTRTOARG("MotorMC " __MC_VER__)));
	mjson_obj_add(version, mjson_string(doc, UTL_CSTRTOARG("protocol")), mjson_int(doc, sky_main.protocol));

	mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("version")), version);

	mjson_val* players = mjson_obj(doc);

	with_lock (&sky_main.listener.online.lock) {

		mjson_obj_add(players, mjson_string(doc, UTL_CSTRTOARG("max")), mjson_int(doc, sky_main.listener.online.max));

		mjson_obj_add(players, mjson_string(doc, UTL_CSTRTOARG("online")), mjson_int(doc, sky_main.listener.online.list.length));
		
		if (sky_main.listener.online.list.length > 0) {
			mjson_val* sample = mjson_arr(doc);
			utl_doubly_linked_node_t* node = sky_main.listener.online.list.first;
			while (node != NULL) {
				ltg_client_t* player = node->element;
				mjson_val* val = mjson_obj(doc);
				mjson_obj_add(val, mjson_string(doc, UTL_CSTRTOARG("name")), mjson_string(doc, player->username.value, player->username.length));
				char uuid[37];
				ltg_uuid_to_string(player->uuid, uuid);
				mjson_obj_add(val, mjson_string(doc, UTL_CSTRTOARG("id")), mjson_string(doc, uuid, 36));
				mjson_arr_append(sample, val);
				node = node->next;
			}
			mjson_obj_add(players, mjson_string(doc, UTL_CSTRTOARG("sample")), sample);
		}

	}

	mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("players")), players);

	mjson_val* description = mjson_obj(doc);

	cht_jsonify(doc, description, sky_main.motd);

	mjson_obj_add(obj, mjson_string(doc, UTL_CSTRTOARG("description")), description);

	size_t len = mjson_write(doc, message);

	mjson_free(doc);

	return len;

}

void cht_set_text(cht_component_t* component, string_t text) {
	component->text = text;
}

string_t cht_get_text(cht_component_t* component) {
	return component->text;
}

void cht_set_bold(cht_component_t* component, bool bold) {
	component->bold = bold;
}

void cht_unset_bold(cht_component_t* component) {
	component->bold = UNSET;
}

bool cht_get_bold(cht_component_t* component) {
	return component->bold;
}

void cht_set_italic(cht_component_t* component, bool italic) {
	component->italic = italic;
}

void cht_unset_italic(cht_component_t* component) {
	component->italic = UNSET;
}

bool cht_get_italic(cht_component_t* component) {
	return component->italic;
}

void cht_set_underlined(cht_component_t* component, bool underlined) {
	component->underlined = underlined;
}

void cht_unset_underlined(cht_component_t* component) {
	component->underlined = UNSET;
}

bool cht_get_underlined(cht_component_t* component) {
	return component->underlined;
}

void cht_set_strikethrough(cht_component_t* component, bool strikethrough) {
	component->strikethrough = strikethrough;
}

void cht_unset_strikethrough(cht_component_t* component) {
	component->strikethrough = UNSET;
}

bool cht_get_strikethrough(cht_component_t* component) {
	return component->strikethrough;
}

void cht_set_obfuscated(cht_component_t* component, bool obfuscated) {
	component->obfuscated = obfuscated;
}

void cht_unset_obfuscated(cht_component_t* component) {
	component->obfuscated = UNSET;
}

bool cht_get_obfuscated(cht_component_t* component) {
	return component->obfuscated;
}

void cht_set_color(cht_component_t* component, cht_color_t color) {
	component->color = color;
}

void cht_unset_color(cht_component_t* component) {
	component->color = cht_no_color;
}

cht_color_t cht_get_color(cht_component_t* component) {
	return component->color;
}