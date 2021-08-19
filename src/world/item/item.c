#include "item.h"

void itm_serialize(pck_packet_t* packet, const itm_item_t* item) {

	if (item->type == mat_item_air) {

		pck_write_int8(packet, false);

	} else {

		pck_write_int8(packet, true);
		pck_write_var_int(packet, item->type);
		pck_write_int8(packet, item->count);
		
		if (item->nbt == NULL) {
			pck_write_int8(packet, 0);
		} else {
			packet->cursor += mnbt_write(item->nbt, pck_cursor(packet), MNBT_NONE);
		}

	}

}