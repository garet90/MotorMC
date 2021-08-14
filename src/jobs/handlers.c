#include <time.h>
#include "handlers.h"
#include "../listening/phd/play.h"
#include "../io/chat/translation.h"
#include "../io/logger/logger.h"
#include "../motor.h"

bool_t job_handle_keep_alive(job_keep_alive_t* work) {

	struct timespec time;
	clock_gettime(CLOCK_REALTIME, &time);
	const int64_t out_ms = time.tv_sec * 1000 + time.tv_nsec / 0xF4240;

	if (out_ms - work->client->last_recv >= 30000) {
		ltg_disconnect(work->client);
		return false;
	} else {
		phd_send_keep_alive(work->client, out_ms);
		return true;
	}

}

bool_t job_handle_global_chat_message(job_global_chat_message_t* work) {

	log_info("<%s> %s", work->sender->username.value, work->message.value);

	cht_translation_t translation = cht_translation_new; // todo terminate
	translation.translate = cht_translation_chat_type_text;
	cht_component_t name = cht_new;
	name.text = work->sender->username.value;
	cht_component_t message = cht_new;
	message.text = work->message.value;
	cht_add_with(&translation, &name);
	cht_add_with(&translation, &message);

	char out[1536];
	const size_t out_len = cht_write_translation(&translation, out);
	// lock client vector
	pthread_mutex_lock(&sky_main.listener.online.lock);
	utl_doubly_linked_node_t* node = sky_main.listener.online.list.first;
	while (node != NULL) {
		ltg_client_t* client = node->element;
		phd_send_chat_message(client, out, out_len, work->sender->uuid);
		node = node->next;
	}
	pthread_mutex_unlock(&sky_main.listener.online.lock);
	cht_term_translation(&translation);
	return true;

}

bool_t job_handle_player_join(job_player_join_t* work) {

	log_info("%s joined the game", work->player->username.value);

	cht_translation_t translation = cht_translation_new;
	translation.translate = cht_translation_multiplayer_player_joined;
	translation.color = cht_yellow;
	cht_component_t name = cht_new;
	name.text = work->player->username.value;
	cht_add_with(&translation, &name);

	char out[128];
	const size_t out_len = cht_write_translation(&translation, out);
	// lock client vector
	pthread_mutex_lock(&sky_main.listener.online.lock);
	utl_doubly_linked_node_t* node = sky_main.listener.online.list.first;
	while (node != NULL) {
		ltg_client_t* client = node->element;
		phd_send_player_info_add_player(client, work->player);
		phd_send_system_chat_message(client, out, out_len);
		node = node->next;
	}
	pthread_mutex_unlock(&sky_main.listener.online.lock);

	cht_term_translation(&translation);

	return true;

}

bool_t job_handle_player_leave(job_player_leave_t* work) {

	log_info("%s left the game", work->username);

	cht_translation_t translation = cht_translation_new;
	translation.translate = cht_translation_multiplayer_player_left;
	translation.color = cht_yellow;
	cht_component_t name = cht_new;
	name.text = work->username;
	cht_add_with(&translation, &name);

	char out[128];
	const size_t out_len = cht_write_translation(&translation, out);
	
	pthread_mutex_lock(&sky_main.listener.online.lock);
	utl_doubly_linked_node_t* node = sky_main.listener.online.list.first;
	while (node != NULL) {
		ltg_client_t* client = node->element;
		phd_send_player_info_remove_player(client, work->uuid);
		phd_send_system_chat_message(client, out, out_len);
		node = node->next;
	}
	pthread_mutex_unlock(&sky_main.listener.online.lock);

	cht_term_translation(&translation);

	return true;

}

bool_t job_handle_send_update_pings(__attribute__((unused)) job_send_update_pings_t* work) {

	pthread_mutex_lock(&sky_main.listener.online.lock);
	utl_doubly_linked_node_t* node = sky_main.listener.online.list.first;
	while (node != NULL) {
		ltg_client_t* client = node->element;
		phd_send_player_info_update_latency(client);
		node = node->next;
	}
	pthread_mutex_unlock(&sky_main.listener.online.lock);

	return true;

}