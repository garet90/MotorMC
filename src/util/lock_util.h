#pragma once
#include "../main.h"
#include <pthread.h>

#define with_lock(lock) for (int mutex_locked = pthread_mutex_lock(lock); mutex_locked == 0; mutex_locked = 1, pthread_mutex_unlock(lock))
