#pragma once
#include "../../main.h"
#include "../material/material.h"
#include "../../io/nbt/mnbt.h"
#include "../../io/packet/packet.h"

typedef struct {

	mat_item_type_t type: 1;
	uint8_t count: 7;

} itm_item_t;

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

	item->count = count & 0x3F;

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

extern void itm_from_packet(pck_packet_t* packet, itm_item_t* item);

/*
Serialize an item into a packet
Equivalent to 'slot' type on wiki.vg
*/
extern void itm_serialize(pck_packet_t* packet, const itm_item_t* item);
