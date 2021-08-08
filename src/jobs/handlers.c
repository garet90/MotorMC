#include "handlers.h"
#include "../listening/phd/play.h"
#include "../io/chat/translation.h"
#include "../motor.h"

bool_t job_handle_keep_alive(sky_worker_t* worker, job_keep_alive_t* work) {

    phd_send_keep_alive(work->client, 0); // TODO use another value than 0 here
    return true;

}

bool_t job_handle_global_chat_message(sky_worker_t* worker, job_global_chat_message_t* work) {

    // TODO notify all client in play state of chat message
    cht_translation_t translation = cht_translation_new;
    translation.translate = cht_translation_cht_type_text;
    cht_component_t name = cht_new;
    name.text = work->sender->username.value;
    cht_component_t message = cht_new;
    message.text = work->message.value;
    cht_add_with(&translation, &name);
    cht_add_with(&translation, &message);

    char out[8096];
    size_t out_len = cht_write_translation(&translation, out);
    // lock client vector
    pthread_mutex_lock(&sky_main.listener.online.lock);
    utl_doubly_linked_node_t* node = sky_main.listener.online.list.first;
    while (node != NULL) {
        ltg_client_t* client = node->element;
        phd_send_chat_message(client, out, out_len, 0, work->sender->uuid);
        node = node->next;
    }
    pthread_mutex_unlock(&sky_main.listener.online.lock);
    return true;

}