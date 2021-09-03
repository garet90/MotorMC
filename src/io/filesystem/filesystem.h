#pragma once
#include "../../main.h"

extern bool fs_mkdir(const char*);
extern bool fs_dir_exists(const char*);

extern bool fs_get_dir_contents(const char*, const char*, void (*) (const char*));

extern bool fs_file_exists(const char*);