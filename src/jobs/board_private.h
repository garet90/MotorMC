#pragma once
#include <pthread.h>
#include "board.h"
#include "../util/linked_list.h"

typedef struct {
	pthread_mutex_t lock;
	pthread_cond_t wait;
	utl_list_t list;
} job_board_t;

extern job_board_t job_board;