#include "handlers.h"
#include "../listening/phd/play.h"

bool_t job_handle_keep_alive(sky_worker_t* worker, job_keep_alive_t* work) {

    phd_send_keep_alive(work->client, 0);
    return true;

}