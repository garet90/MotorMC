#pragma once

#include "item.d.h"

#include "../../main.h"
#include "../material/material.h"
#include "../../io/nbt/mnbt.h"
#include "../../io/packet/packet.h"

struct itm_item {

	mat_item_type_t type: 11;
	uint8_t count: 7;

};

static const itm_item_t itm_new = {
	.type = mat_item_air,
	.count = 0
};

/*
Safe method to set the count of an item
Will set to a max of 64
and will reset the type to air if count is 0
*/
static inline void itm_set_count(itm_item_t* item, uint8_t count) {

	item->count = (count > 64 ? count = 64 : count);

	if (count == 0) {
		item->type = mat_item_air;
	}

}

/*
Set type of an item
If the item is air, the type will be changed to 'type' and count to 1
If 'type' is air, it has the same effect as itm_set_count(item, 0)
Otherwise, the type is changed and other data is kept (enchantments and everything)
*/
static inline void itm_set_type(itm_item_t* item, mat_item_type_t type) {

	if (type == mat_item_air) {
		itm_set_count(item, 0);
	} else if (item->type == mat_item_air) {
		item->type = type;
		item->count = 1;
	} else {
		item->type = type;
	}

}

static inline bool itm_is_similar(itm_item_t* a, itm_item_t* b) {

	if (a->type != b->type) return false;

	return true;

}

static inline void itm_from_packet(pck_packet_t* packet, itm_item_t* item) {

	bool present = pck_read_int8(packet);

	if (present) {
		mat_item_type_t type = pck_read_var_int(packet);
		int8_t count = pck_read_int8(packet);
		size_t len = 0;
		mnbt_doc* doc = mnbt_read(pck_cursor(packet), 1, &len, MNBT_NONE);

		packet->cursor += len;

		itm_set_type(item, type);
		itm_set_count(item, count);

		mnbt_free(doc);
	} else {
		itm_set_type(item, mat_item_air);
	}

}

/*
Serialize an item into a packet
Equivalent to 'slot' type on wiki.vg
*/
static inline void itm_serialize(pck_packet_t* packet, const itm_item_t* item) {

	if (item->type == mat_item_air) {

		pck_write_int8(packet, false);

	} else {

		pck_write_int8(packet, true);
		pck_write_var_int(packet, item->type);
		pck_write_int8(packet, item->count);
		
		pck_write_int8(packet, 0); // TODO nbt

	}

}
