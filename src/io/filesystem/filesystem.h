#pragma once
#include "../../main.h"

extern bool_t fs_makeDir(const char*);
extern bool_t fs_dirExists(const char*);

extern bool_t fs_getDirContents(const char*, const char*, void (*) (const char*));

extern bool_t fs_fileExists(const char*);