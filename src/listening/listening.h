#pragma once
#include <pthread.h>
#include "../main.h"
#include "../util/id_vector.h"
#include "../util/doubly_linked_list.h"
#include "../util/util.h"
#include "../io/packet/packet.h"
#include "../crypt/rsa.h"
#include "../crypt/cfb8.h"
#include "../world/entity/entity.h"
#include "socket/socket.h"

#define LTG_MAX_RECIEVE 32767

typedef enum {
	ltg_handshake = 0,
	ltg_status = 1,
	ltg_login = 2,
	ltg_play = 3
} ltg_state_t;

typedef enum {

	ltg_chat_enabled = 0,
	ltg_chat_commands_only = 1,
	ltg_chat_hidden = 2

} ltg_chat_mode_t;

typedef enum {

	ltg_af_za = 0x0f13dbe6,
	ltg_ar_sa = 0x0f1a6f8b,
	ltg_ast_es = 0xf285a944,
	ltg_az_az = 0x0f1ed05a,
	ltg_ba_ru = 0x0f23358e,
	ltg_bar = 0x0b8860ba,
	ltg_be_by = 0x0f256506,
	ltg_bg_bg = 0x0f267db6,
	ltg_br_fr = 0x0f2c8670,
	ltg_brb = 0x0b8862db,
	ltg_bs_ba = 0x0f2d123c,
	ltg_ca_es = 0x0f354c60,
	ltg_cy_gb = 0x0f4275a9,
	ltg_da_dk = 0x0f4764b8,
	ltg_de_at = 0x0f4995e2,
	ltg_de_ch = 0x0f499618,
	ltg_de_de = 0x0f499636,
	ltg_el_gr = 0x0f5f85ce,
	ltg_en_au = 0x0f609dcd,
	ltg_en_ca = 0x0f609dfb,
	ltg_en_gb = 0x0f609e80,
	ltg_en_nz = 0x0f609f7f,
	ltg_en_pt = 0x0f609fbb,
	ltg_en_ud = 0x0f60a050,
	ltg_en_us = 0x0f60a05f,
	ltg_enp = 0x0b886f28,
	ltg_enws = 0x7c965582,
	ltg_eo_uy = 0x0f612cc6,
	ltg_es_ar = 0x0f635baf,
	ltg_es_cl = 0x0f635beb,
	ltg_es_ec = 0x0f635c24,
	ltg_es_es = 0x0f635c34,
	ltg_es_mx = 0x0f635d41,
	ltg_es_uy = 0x0f635e4a,
	ltg_es_ve = 0x0f635e57,
	ltg_esan = 0x7c9667ec,
	ltg_et_ee = 0x0f63e887,
	ltg_eu_es = 0x0f6474f6,
	ltg_fa_ir = 0x0f6b9666,
	ltg_fi_fi = 0x0f6ff902,
	ltg_fo_fo = 0x0f73434e,
	ltg_fr_ca = 0x0f74e800,
	ltg_fr_fr = 0x0f74e874,
	ltg_fra_de = 0xfe12f086,
	ltg_fy_nl = 0x0f78c01d,
	ltg_ga_ie = 0x0f7daeda,
	ltg_gd_gb = 0x0f7f53b8,
	ltg_gl_es = 0x0f83b68f,
	ltg_haw_us = 0x0195b3cc,
	ltg_he_il = 0x0f91f8e6,
	ltg_hi_in = 0x0f942a6c,
	ltg_hu_hu = 0x0f9abede,
	ltg_hy_am = 0x0f9cef73,
	ltg_id_id = 0x0fa384fe,
	ltg_ig_ng = 0x0fa52ac9,
	ltg_io_en = 0x0fa98caf,
	ltg_is_is = 0x0fabbebc,
	ltg_isv = 0x0b8880d7,
	ltg_it_it = 0x0fac4b1e,
	ltg_ja_jp = 0x0fb3f889,
	ltg_jbo_en = 0x064db872,
	ltg_ka_ge = 0x0fc6109c,
	ltg_kk_kz = 0x0fcb8cff,
	ltg_kn_in = 0x0fcd31d4,
	ltg_ko_kr = 0x0fcdbe7b,
	ltg_ksh = 0x0b88894b,
	ltg_kw_gb = 0x0fd220ef,
	ltg_la_la = 0x0fd829be,
	ltg_lb_lu = 0x0fd8b633,
	ltg_li_li = 0x0fdc8cce,
	ltg_lol_us = 0x0be1a533,
	ltg_lt_lt = 0x0fe29504,
	ltg_lv_lv = 0x0fe3adc8,
	ltg_lzh = 0x0b888e73,
	ltg_mk_mk = 0x0fefbe34,
	ltg_mn_mn = 0x0ff1635a,
	ltg_ms_my = 0x0ff4214a,
	ltg_mt_mt = 0x0ff4ada6,
	ltg_nds_de = 0x0fc8bd52,
	ltg_nl_be = 0x100261a5,
	ltg_nl_nl = 0x10026338,
	ltg_nn_no = 0x10037bfd,
	ltg_no_no = 0x1004085e,
	ltg_oc_fr = 0x100f8b4e,
	ltg_ovd = 0x0b889aae,
	ltg_pl_pl = 0x1026947c,
	ltg_pt_br = 0x102af5bc,
	ltg_pt_pt = 0x102af78c,
	ltg_qya_aa = 0x183a5a91,
	ltg_ro_ro = 0x104c6ae6,
	ltg_rpr = 0x0b88a6b9,
	ltg_ru_ru = 0x104fb532,
	ltg_se_no = 0x10590719,
	ltg_sk_sk = 0x105c5200,
	ltg_sl_si = 0x105cde5f,
	ltg_so_so = 0x105e8388,
	ltg_sq_al = 0x105f99f5,
	ltg_sr_sp = 0x106028ac,
	ltg_sv_se = 0x10625a25,
	ltg_sxu = 0x0b88ac05,
	ltg_szl = 0x0b88ac3e,
	ltg_ta_in = 0x1068ed70,
	ltg_th_th = 0x106cc57c,
	ltg_tl_ph = 0x106ef67c,
	ltg_tlh_aa = 0x1e526c8e,
	ltg_tr_tr = 0x10724150,
	ltg_tt_ru = 0x107359d3,
	ltg_uk_ua = 0x1080833a,
	ltg_val_es = 0x2237e25f,
	ltg_vec_it = 0x227b557f,
	ltg_vi_vn = 0x10918327,
	ltg_yi_de = 0x10c7ca4f,
	ltg_yo_ng = 0x10cb15e1,
	ltg_zh_cn = 0x10d95657,
	ltg_zh_hk = 0x10d956f9,
	ltg_zh_tw = 0x10d95891

} ltg_locale_t;

#define LTG_AES_KEY_LENGTH 16

typedef byte_t ltg_uuid_t[16];

typedef struct {

	pthread_t thread;
	
	utl_doubly_linked_node_t* online_node;
	ent_player_t* _Atomic entity;

	uint32_t id;

	// address
	int32_t socket;

	struct {
		string_t value;
		string_t signature;
	} textures;

	string_t username;

	ltg_locale_t locale;

	ltg_uuid_t uuid;

	uint32_t verify;

	atomic_int_least64_t last_recv;
	atomic_int_least64_t ping;

	struct {
		symmetric_CFB8 encrypt;
		symmetric_CFB8 decrypt;
		bool enabled;
	} encryption;

	struct {
		struct sockaddr_in addr;
		int size;
	} address;

	void* keep_alive;

	uint16_t protocol : 10;
	uint8_t render_distance : 6;
	ltg_chat_mode_t chat_mode : 2;

	ltg_state_t state : 2;

} ltg_client_t;

typedef struct {

	pthread_t thread;

	// address
	struct {
		int32_t socket;
		struct sockaddr_in addr;
		uint16_t port;
	} address;

	struct {
		pthread_mutex_t lock;
		utl_id_vector_t vector;
	} clients;
	
	struct {
		pthread_mutex_t lock;
		utl_doubly_linked_list_t list;
		size_t max : 16;
	} online;

	uint16_t network_compression_threshold;
	bool online_mode : 1;
	bool prevent_proxy_connections : 1;

	cry_rsa_keypair_t keypair;

} ltg_main_t;

extern void ltg_init();
extern void* t_ltg_run(void*);
extern void ltg_accept(ltg_client_t*);
extern void* t_ltg_client(void*);

extern ltg_client_t* ltg_get_client_by_id(uint32_t id);

extern bool ltg_handle_packet(ltg_client_t* client, pck_packet_t* packet);

extern void ltg_send(ltg_client_t*, pck_packet_t*);

extern void ltg_disconnect(ltg_client_t*);

extern void ltg_term();

static inline void ltg_uuid_to_string(ltg_uuid_t uuid, char* out) {
	
	out[0] = utl_hexmap[uuid[0] >> 4];
	out[1] = utl_hexmap[uuid[0] & 0xF];
	out[2] = utl_hexmap[uuid[1] >> 4];
	out[3] = utl_hexmap[uuid[1] & 0xF];
	out[4] = utl_hexmap[uuid[2] >> 4];
	out[5] = utl_hexmap[uuid[2] & 0xF];
	out[6] = utl_hexmap[uuid[3] >> 4];
	out[7] = utl_hexmap[uuid[3] & 0xF];
	out[8] = '-';
	out[9] = utl_hexmap[uuid[4] >> 4];
	out[10] = utl_hexmap[uuid[4] & 0xF];
	out[11] = utl_hexmap[uuid[5] >> 4];
	out[12] = utl_hexmap[uuid[5] & 0xF];
	out[13] = '-';
	out[14] = utl_hexmap[uuid[6] >> 4];
	out[15] = utl_hexmap[uuid[6] & 0xF];
	out[16] = utl_hexmap[uuid[7] >> 4];
	out[17] = utl_hexmap[uuid[7] & 0xF];
	out[18] = '-';
	out[19] = utl_hexmap[uuid[8] >> 4];
	out[20] = utl_hexmap[uuid[8] & 0xF];
	out[21] = utl_hexmap[uuid[9] >> 4];
	out[22] = utl_hexmap[uuid[9] & 0xF];
	out[23] = '-';
	out[24] = utl_hexmap[uuid[10] >> 4];
	out[25] = utl_hexmap[uuid[10] & 0xF];
	out[26] = utl_hexmap[uuid[11] >> 4];
	out[27] = utl_hexmap[uuid[11] & 0xF];
	out[28] = utl_hexmap[uuid[12] >> 4];
	out[29] = utl_hexmap[uuid[12] & 0xF];
	out[30] = utl_hexmap[uuid[13] >> 4];
	out[31] = utl_hexmap[uuid[13] & 0xF];
	out[32] = utl_hexmap[uuid[14] >> 4];
	out[33] = utl_hexmap[uuid[14] & 0xF];
	out[34] = utl_hexmap[uuid[15] >> 4];
	out[35] = utl_hexmap[uuid[15] & 0xF];
	out[36] = 0;

}

// API

extern string_t ltg_get_username(const ltg_client_t*);
extern const byte_t* ltg_get_uuid(const ltg_client_t*);
extern uint16_t ltg_get_protocol(const ltg_client_t*);
extern uint8_t ltg_get_render_distance(const ltg_client_t*);
extern int64_t ltg_get_ping(const ltg_client_t*);
extern string_t ltg_get_textures(const ltg_client_t*);
extern ltg_locale_t ltg_get_locale(const ltg_client_t*);
extern ent_player_t* ltg_get_entity(const ltg_client_t*);
