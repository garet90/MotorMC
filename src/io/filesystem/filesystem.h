#pragma once
#include "../../main.h"

extern bool_t fs_mkdir(const char*);
extern bool_t fs_dir_exists(const char*);

extern bool_t fs_get_dir_contents(const char*, const char*, void (*) (const char*));

extern bool_t fs_file_exists(const char*);