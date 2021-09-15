#include "item.h"

void itm_from_packet(pck_packet_t* packet, itm_item_t* item) {

	bool present = pck_read_int8(packet);

	if (present) {
		mat_item_type_t type = pck_read_var_int(packet);
		int8_t count = pck_read_int8(packet);
		mnbt_doc* doc = mnbt_read(pck_cursor(packet), 1, MNBT_NONE);

		itm_set_type(item, type);
		itm_set_count(item, count);

		mnbt_free(doc);
	} else {
		itm_set_type(item, mat_item_air);
	}

}

void itm_serialize(pck_packet_t* packet, const itm_item_t* item) {

	if (item->type == mat_item_air) {

		pck_write_int8(packet, false);

	} else {

		pck_write_int8(packet, true);
		pck_write_var_int(packet, item->type);
		pck_write_int8(packet, item->count);
		
		pck_write_int8(packet, 0); // TODO nbt

	}

}