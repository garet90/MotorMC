#pragma once
#include "../main.h"

#define UTL_STRTOCSTR(str) str.value
#define UTL_CSTRTOSTR(str) (string_t) { .value = str, .length = sizeof(str) - 1 }
#define UTL_ARRTOSTR(arr, len) (string_t) { .value = arr, .length = len }

#define UTL_STRTOARG(str) str.value, str.length
#define UTL_CSTRTOARG(str) str, sizeof(str) - 1 