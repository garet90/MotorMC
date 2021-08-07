#include <stdarg.h>
#include "../../motor.h"
#include "../../util/util.h"
#include "../logger/logger.h"
#include "chat.h"

cht_component_t* cht_alloc() {

	cht_component_t* alloc = calloc(1, sizeof(cht_component_t));

	utl_set_bit(alloc->format, cht_heap);
	alloc->color = CHT_NOCOLOR;

	return alloc;

}

cht_component_t* cht_from_json(yyjson_val* obj) {

	cht_component_t* component = cht_alloc();

	size_t i, i_max;
	yyjson_val *obj_key, *obj_val;
	yyjson_obj_foreach(obj, i, i_max, obj_key, obj_val) {
		switch (utl_hash(yyjson_get_str(obj_key))) {
		case 0x7c9e690a: { // "text"
			size_t text_len = yyjson_get_len(obj_val);
			component->text = malloc(text_len + 1);
			memcpy(component->text, yyjson_get_str(obj_val), text_len);
			component->text[text_len] = '\0';
			break;
		}
		case 0x7c94b326: // "bold"
			utl_set_bit(component->format, cht_bold_set);
			if (yyjson_get_bool(obj_val))
				utl_set_bit(component->format, cht_bold);
			break;
		case 0x0536d35b: // "italic"
			utl_set_bit(component->format, cht_italic_set);
			if (yyjson_get_bool(obj_val))
				utl_set_bit(component->format, cht_italic);
			break;
		case 0xd635c50f: // "underlined"
			utl_set_bit(component->format, cht_underlined_set);
			if (yyjson_get_bool(obj_val))
				utl_set_bit(component->format, cht_underlined);
			break;
		case 0x10d72f78: // "strikethrough"
			utl_set_bit(component->format, cht_strikethrough_set);
			if (yyjson_get_bool(obj_val))
				utl_set_bit(component->format, cht_strikethrough);
			break;
		case 0xf1f68aa5: // "obfuscated"
			utl_set_bit(component->format, cht_obfuscated_set);
			if (yyjson_get_bool(obj_val))
				utl_set_bit(component->format, cht_obfuscated);
			break;
		case 0x0f3d3244: // "color"
			switch (utl_hash(yyjson_get_str(obj_val))) {
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
				utl_read_hex_bytes((byte_t*) &component->color, yyjson_get_str(obj_val), yyjson_get_len(obj_val) >> 1);
				break;
			}
			break;
		case 0x94c4816d: { // "clickEvent"

			size_t j, j_max;
			yyjson_val *event_key, *event_val;
			yyjson_obj_foreach(obj_val, j, j_max, event_key, event_val) {
				switch (utl_hash(yyjson_get_str(event_key))) {
				case 0xf1644d03: // "action"
					switch (utl_hash(yyjson_get_str(event_val))) {
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
					size_t value_len = yyjson_get_len(event_val);
					component->click_event.value = malloc(value_len + 1);
					memcpy(component->click_event.value, yyjson_get_str(event_val), value_len);
					component->click_event.value[value_len] = '\0';
					break;
				}
				}
			}

			break;
		}
		case 0xb00f0f6b: { // "hoverEvent"

			size_t j, j_max;
			yyjson_val *event_key, *event_val;
			yyjson_obj_foreach(obj_val, j, j_max, event_key, event_val) {
				switch (utl_hash(yyjson_get_str(event_key))) {
				case 0xf1644d03: // "action"
					switch (utl_hash(yyjson_get_str(event_val))) {
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
					size_t value_len = yyjson_get_len(event_val);
					component->hover_event.value = malloc(value_len + 1);
					memcpy(component->hover_event.value, yyjson_get_str(event_val), value_len);
					component->hover_event.value[value_len] = '\0';
					break;
				}
				}
			}

			break;
		}
		case 0x0f667509: { // extra
			size_t j, j_max;
			yyjson_val *extra_val;
			yyjson_arr_foreach(obj_val, j, j_max, extra_val) {
				cht_component_t* extra = cht_from_json(extra_val);
				cht_add_extra(component, extra);
			}
			break;
		}
		}
	}

	return component;

}

cht_component_t* cht_from_string(const char* str, size_t len) {

	yyjson_doc* doc = yyjson_read(str, len, 0);

	cht_component_t* component = cht_from_json(yyjson_doc_get_root(doc));

	yyjson_doc_free(doc);

	return component;
	
}

void cht_jsonify(yyjson_mut_doc* doc, yyjson_mut_val* obj, const cht_component_t* component) {

	if (component->text != NULL)
		yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "text"), yyjson_mut_str(doc, component->text));

	if (utl_test_bit(component->format, cht_bold_set))
		yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "bold"), utl_test_bit(component->format, cht_bold) ? yyjson_mut_true(doc) : yyjson_mut_false(doc));

	if (utl_test_bit(component->format, cht_italic_set))
		yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "italic"), utl_test_bit(component->format, cht_italic) ? yyjson_mut_true(doc) : yyjson_mut_false(doc));

	if (utl_test_bit(component->format, cht_underlined_set))
		yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "underlined"), utl_test_bit(component->format, cht_underlined) ? yyjson_mut_true(doc) : yyjson_mut_false(doc));

	if (utl_test_bit(component->format, cht_strikethrough_set))
		yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "strikethrough"), utl_test_bit(component->format, cht_strikethrough) ? yyjson_mut_true(doc) : yyjson_mut_false(doc));
		
	if (utl_test_bit(component->format, cht_obfuscated_set))
		yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "obfuscated"), utl_test_bit(component->format, cht_obfuscated) ? yyjson_mut_true(doc) : yyjson_mut_false(doc));

	if (component->color != CHT_NOCOLOR) {
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

			yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "color"), yyjson_mut_str(doc, colors[component->color]));
		} else {
			char color[9];
			sprintf(color, "%x", component->color);
			yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "color"), yyjson_mut_str(doc, color));
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

		yyjson_mut_val* click_event = yyjson_mut_obj(doc);

		yyjson_mut_obj_add(click_event, yyjson_mut_str(doc, "action"), yyjson_mut_str(doc, click_events[component->click_event.action]));
		yyjson_mut_obj_add(click_event, yyjson_mut_str(doc, "value"), yyjson_mut_str(doc, component->click_event.value));

		yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "clickEvent"), click_event);

	}

	if (component->hover_event.value != NULL) {

		const char* hover_events[] = {
			"show_text",
			"show_item",
			"show_entity"
		};

		yyjson_mut_val* hover_event = yyjson_mut_obj(doc);

		yyjson_mut_obj_add(hover_event, yyjson_mut_str(doc, "action"), yyjson_mut_str(doc, hover_events[component->hover_event.action]));
		yyjson_mut_obj_add(hover_event, yyjson_mut_str(doc, "value"), yyjson_mut_str(doc, component->hover_event.value));
		
		yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "hoverEvent"), hover_event);

	}

	if (component->extra.size != 0) {

		yyjson_mut_val* extra = yyjson_mut_arr(doc);

		for (size_t i = 0; i < component->extra.size; ++i) {

			yyjson_mut_val* extra_obj = yyjson_mut_obj(doc);

			cht_jsonify(doc, extra_obj, UTL_VECTOR_GET_AS(cht_component_t*, &component->extra, i));

			yyjson_mut_arr_append(extra, extra_obj);

		}

		yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "extra"), extra);

	}

}

size_t cht_write(const cht_component_t* component, char* message) {
	
	yyjson_mut_doc* doc = yyjson_mut_doc_new(NULL);
	yyjson_mut_val* obj = yyjson_mut_obj(doc);
	yyjson_mut_doc_set_root(doc, obj);

	cht_jsonify(doc, obj, component);

	size_t str_len;
	char* str = yyjson_mut_write(doc, YYJSON_WRITE_NOFLAG, &str_len);
	memcpy(message, str, str_len);

	free(str);

	yyjson_mut_doc_free(doc);

	return str_len;

}

void cht_free(cht_component_t* component) {

	if (component->extra.size != 0) {
		for (uint32_t i = 0; i < component->extra.size; ++i) {
			cht_component_t* extra = UTL_VECTOR_GET_AS(cht_component_t*, &component->extra, i);
			cht_free(extra);
		}
		utl_vector_term(&component->extra);
	}

	if (utl_test_bit(component->format, cht_heap)) {
		
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

	yyjson_mut_doc* doc = yyjson_mut_doc_new(NULL);
	yyjson_mut_val* obj = yyjson_mut_obj(doc);
	yyjson_mut_doc_set_root(doc, obj);

	yyjson_mut_val* version = yyjson_mut_obj(doc);

	char version_name[9 + sizeof(__MC_VER__)];
	sprintf(version_name, "MotorMC %s", sky_main.mcver);
	yyjson_mut_obj_add(version, yyjson_mut_str(doc, "name"), yyjson_mut_str(doc, version_name));
	yyjson_mut_obj_add(version, yyjson_mut_str(doc, "protocol"), yyjson_mut_uint(doc, sky_main.protocol));

	yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "version"), version);

	yyjson_mut_val* players = yyjson_mut_obj(doc);

	yyjson_mut_obj_add(players, yyjson_mut_str(doc, "max"), yyjson_mut_uint(doc, sky_main.listener.online.max));
	yyjson_mut_obj_add(players, yyjson_mut_str(doc, "online"), yyjson_mut_uint(doc, sky_main.listener.online.count));

	yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "players"), players);

	yyjson_mut_val* description = yyjson_mut_obj(doc);

	cht_jsonify(doc, description, sky_main.motd);

	yyjson_mut_obj_add(obj, yyjson_mut_str(doc, "description"), description);

	char* str = yyjson_mut_write(doc, YYJSON_WRITE_NOFLAG, NULL);
	size_t size = sprintf(message, "%s", str);

	free(str);

	yyjson_mut_doc_free(doc);

	return size;

}
