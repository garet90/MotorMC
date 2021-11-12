#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __WINDOWS__
#define export __declspec(dllexport)
#define import __declspec(dllimport)
#elif __GNUC__
#define export __attribute__((visibility("default")))
#define import
#else
#define export
#define import
#endif

// TYPES

#include <stdint.h>
#include <stddef.h>

typedef struct {

	char* value;
	size_t length;

} string_t;

#define cstr_to_str(x) (string_t) { .value = x, .length = sizeof(x) - 1 }

// COMMAND

typedef void* command_sender_t;

typedef struct {

	const string_t label;
	const string_t description;
	const string_t usage;
	const string_t permission;
	const string_t permission_message;
	bool (*const handler) (char* args, const command_sender_t sender);
	const size_t alias_count;
	const string_t aliases[];

} command_t;

typedef enum {
	
	not_op = 0,
	op_level_1 = 1,
	op_level_2 = 2,
	op_level_3 = 3,
	op_level_4 = 4

} op_level_t;

typedef enum {

	command_sender_console = 0,
	command_sender_player = 1,
	command_sender_command_block = 2

} command_sender_type_t;

// PLAYER

typedef enum {

	locale_af_za = 0x0f13dbe6,
	locale_ar_sa = 0x0f1a6f8b,
	locale_ast_es = 0xf285a944,
	locale_az_az = 0x0f1ed05a,
	locale_ba_ru = 0x0f23358e,
	locale_bar = 0x0b8860ba,
	locale_be_by = 0x0f256506,
	locale_bg_bg = 0x0f267db6,
	locale_br_fr = 0x0f2c8670,
	locale_brb = 0x0b8862db,
	locale_bs_ba = 0x0f2d123c,
	locale_ca_es = 0x0f354c60,
	locale_cy_gb = 0x0f4275a9,
	locale_da_dk = 0x0f4764b8,
	locale_de_at = 0x0f4995e2,
	locale_de_ch = 0x0f499618,
	locale_de_de = 0x0f499636,
	locale_el_gr = 0x0f5f85ce,
	locale_en_au = 0x0f609dcd,
	locale_en_ca = 0x0f609dfb,
	locale_en_gb = 0x0f609e80,
	locale_en_nz = 0x0f609f7f,
	locale_en_pt = 0x0f609fbb,
	locale_en_ud = 0x0f60a050,
	locale_en_us = 0x0f60a05f,
	locale_enp = 0x0b886f28,
	locale_enws = 0x7c965582,
	locale_eo_uy = 0x0f612cc6,
	locale_es_ar = 0x0f635baf,
	locale_es_cl = 0x0f635beb,
	locale_es_ec = 0x0f635c24,
	locale_es_es = 0x0f635c34,
	locale_es_mx = 0x0f635d41,
	locale_es_uy = 0x0f635e4a,
	locale_es_ve = 0x0f635e57,
	locale_esan = 0x7c9667ec,
	locale_et_ee = 0x0f63e887,
	locale_eu_es = 0x0f6474f6,
	locale_fa_ir = 0x0f6b9666,
	locale_fi_fi = 0x0f6ff902,
	locale_fo_fo = 0x0f73434e,
	locale_fr_ca = 0x0f74e800,
	locale_fr_fr = 0x0f74e874,
	locale_fra_de = 0xfe12f086,
	locale_fy_nl = 0x0f78c01d,
	locale_ga_ie = 0x0f7daeda,
	locale_gd_gb = 0x0f7f53b8,
	locale_gl_es = 0x0f83b68f,
	locale_haw_us = 0x0195b3cc,
	locale_he_il = 0x0f91f8e6,
	locale_hi_in = 0x0f942a6c,
	locale_hu_hu = 0x0f9abede,
	locale_hy_am = 0x0f9cef73,
	locale_id_id = 0x0fa384fe,
	locale_ig_ng = 0x0fa52ac9,
	locale_io_en = 0x0fa98caf,
	locale_is_is = 0x0fabbebc,
	locale_isv = 0x0b8880d7,
	locale_it_it = 0x0fac4b1e,
	locale_ja_jp = 0x0fb3f889,
	locale_jbo_en = 0x064db872,
	locale_ka_ge = 0x0fc6109c,
	locale_kk_kz = 0x0fcb8cff,
	locale_kn_in = 0x0fcd31d4,
	locale_ko_kr = 0x0fcdbe7b,
	locale_ksh = 0x0b88894b,
	locale_kw_gb = 0x0fd220ef,
	locale_la_la = 0x0fd829be,
	locale_lb_lu = 0x0fd8b633,
	locale_li_li = 0x0fdc8cce,
	locale_lol_us = 0x0be1a533,
	locale_lt_lt = 0x0fe29504,
	locale_lv_lv = 0x0fe3adc8,
	locale_lzh = 0x0b888e73,
	locale_mk_mk = 0x0fefbe34,
	locale_mn_mn = 0x0ff1635a,
	locale_ms_my = 0x0ff4214a,
	locale_mt_mt = 0x0ff4ada6,
	locale_nds_de = 0x0fc8bd52,
	locale_nl_be = 0x100261a5,
	locale_nl_nl = 0x10026338,
	locale_nn_no = 0x10037bfd,
	locale_no_no = 0x1004085e,
	locale_oc_fr = 0x100f8b4e,
	locale_ovd = 0x0b889aae,
	locale_pl_pl = 0x1026947c,
	locale_pt_br = 0x102af5bc,
	locale_pt_pt = 0x102af78c,
	locale_qya_aa = 0x183a5a91,
	locale_ro_ro = 0x104c6ae6,
	locale_rpr = 0x0b88a6b9,
	locale_ru_ru = 0x104fb532,
	locale_se_no = 0x10590719,
	locale_sk_sk = 0x105c5200,
	locale_sl_si = 0x105cde5f,
	locale_so_so = 0x105e8388,
	locale_sq_al = 0x105f99f5,
	locale_sr_sp = 0x106028ac,
	locale_sv_se = 0x10625a25,
	locale_sxu = 0x0b88ac05,
	locale_szl = 0x0b88ac3e,
	locale_ta_in = 0x1068ed70,
	locale_th_th = 0x106cc57c,
	locale_tl_ph = 0x106ef67c,
	locale_tlh_aa = 0x1e526c8e,
	locale_tr_tr = 0x10724150,
	locale_tt_ru = 0x107359d3,
	locale_uk_ua = 0x1080833a,
	locale_val_es = 0x2237e25f,
	locale_vec_it = 0x227b557f,
	locale_vi_vn = 0x10918327,
	locale_yi_de = 0x10c7ca4f,
	locale_yo_ng = 0x10cb15e1,
	locale_zh_cn = 0x10d95657,
	locale_zh_hk = 0x10d956f9,
	locale_zh_tw = 0x10d95891

} locale_t;

typedef void* player_t;

// ENTITIES

typedef void* entity_t;

// CHAT

typedef enum {

	chat_black = 0x0,
	chat_dark_blue = 0x1,
	chat_dark_green = 0x2,
	chat_dark_cyan = 0x3,
	chat_dark_red = 0x4,
	chat_purple = 0x5,
	chat_gold = 0x6,
	chat_gray = 0x7,
	chat_dark_gray = 0x8,
	chat_blue = 0x9,
	chat_bright_green = 0xA,
	chat_cyan = 0xB,
	chat_red = 0xC,
	chat_pink = 0xD,
	chat_yellow = 0xE,
	chat_white = 0xF,

} chat_color_t;

typedef void* chat_component_t;

// PLUGINS

typedef enum {

	plugin_postworld = 0,
	plugin_startup

} plugin_startup_t;

typedef struct {

	const string_t name;
	const string_t description;
	const string_t authors;
	const string_t version;
	const string_t website;
	const plugin_startup_t load;

} plugin_t;

// API

#define PLUGIN_API_VERSION 0

// The MotorMC API
// Useful for interfacing with the server
typedef struct {

	const uint32_t api_version;

	// All logging related commands
	struct {

		// Output a message to the console (follows the same format as printf)
		void (*const info) (const char* format, ...);

		// Output a warning to the console (follows the same format as printf)
		void (*const warn) (const char* format, ...);

		// Output an error to the console (follows the same format as printf)
		void (*const error) (const char* format, ...);

	} logger;

	// All command related functions
	struct {

		// Register a server command that can be called by players, command blocks, and the console
		void (*const add) (const command_t* command);

		// Message a command sender
		void (*const message) (const command_sender_t sender, const chat_component_t component);

		// Get the sender's OP level
		op_level_t (*const get_op_level) (const command_sender_t sender);

		// Get the sender's type
		//
		// They can be one of the following
		// - Console
		// - Player
		// - Command block
		command_sender_type_t (*const get_sender_type) (const command_sender_t sender);

		// Get the command sender as a player
		// Returns NULL if the sender is not a player
		player_t (*const get_player) (const command_sender_t sender);

	} commands;

	// All player related functions
	struct {

		// Get a player's username
		string_t (*const get_username) (const player_t player);
		
		// Get a player's UUID (array of 16 bytes)
		const uint8_t* (*const get_uuid) (const player_t player);

		// Get a player's protocol (What version of Minecraft they're playing)
		uint16_t (*const get_protocol) (const player_t player);

		// Get a player's render distance
		uint8_t (*const get_render_distance) (const player_t player);

		// Get a player's ping (in milliseconds)
		int64_t (*const get_ping) (const player_t player);

		// Get a player's textures (AKA their skin)
		string_t (*const get_textures) (const player_t player);

		// Get a player's locale (AKA language)
		locale_t (*const get_locale) (const player_t player);

		// Get a player's entity
		entity_t (*const get_entity) (const player_t player);

		// Kick a player
		void (*const kick) (const player_t player, const chat_component_t reason);

		// Ban a player
		void (*const ban) (const player_t player, const chat_component_t reason);

		// Pardon a player
		void (*const pardon) (const player_t player);

	} player;

	// All chat and chat component related functions
	struct {

		// Allocate a new chat component
		// NOTE: You MUST free all chat components you allocate
		chat_component_t (*const alloc) ();

		// Set text of a chat component
		void (*const set_text) (chat_component_t component, const string_t message);
		// Get the text of a chat component
		string_t (*const get_text) (chat_component_t component);

		// Set the bold field of a chat component
		void (*const set_bold) (chat_component_t component, bool bold);
		// Unset the bold field of a chat component
		void (*const unset_bold) (chat_component_t component);
		// Get the bold field of a chat component (returns 2 when unset)
		bool (*const get_bold) (chat_component_t component);

		// Set the italic field of a chat component
		void (*const set_italic) (chat_component_t component, bool italic);
		// Unset the italic field of a chat component
		void (*const unset_italic) (chat_component_t component);
		// Get the italic field of a chat component (returns 2 when unset)
		bool (*const get_italic) (chat_component_t component);

		// Set the underlined field of a chat component
		void (*const set_underlined) (chat_component_t component, bool underlined);
		// Unset the underlined field of a chat component
		void (*const unset_underlined) (chat_component_t component);
		// Get the underlined field of a chat component (returns 2 when unset)
		bool (*const get_underlined) (chat_component_t component);

		// Set the strikethrough field of a chat component
		void (*const set_strikethrough) (chat_component_t component, bool strikethrough);
		// Unset the strikethrough field of a chat component
		void (*const unset_strikethrough) (chat_component_t component);
		// Get the strikethrough field of a chat component (returns 2 when unset)
		bool (*const get_strikethrough) (chat_component_t component);

		// Set the obfuscated field of a chat component
		void (*const set_obfuscated) (chat_component_t component, bool obfuscated);
		// Unset the obfuscated field of a chat component
		void (*const unset_obfuscated) (chat_component_t component);
		// Get the obfuscated field of a chat component (returns 2 when unset)
		bool (*const get_obfuscated) (chat_component_t component);

		// Set the color of a chat component (Accepts hex values as well)
		void (*const set_color) (chat_component_t component, chat_color_t color);
		// Unset the color of a chat component
		void (*const unset_color) (chat_component_t component);
		// Get the color of a chat component (returns 11 when unset)
		chat_color_t (*const get_color) (chat_component_t component);

		// Add a component to an existing component
		void (*const add_extra) (chat_component_t base, const chat_component_t extra);

		// Free a component
		void (*const free) (chat_component_t component);

	} chat;

} motor_api_t;

static motor_api_t const* motor;

// register plugin

#define register_plugin(plugin) export const plugin_t* get_plugin(const motor_api_t* interface) {\
			if (interface->api_version != PLUGIN_API_VERSION) {\
				return NULL;\
			}\
			motor = interface;\
			return plugin;\
		}

#ifdef __cplusplus
}
#endif