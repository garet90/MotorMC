#include "filesystem.h"
#include <stdio.h>
#include <string.h>
#include "../logger/logger.h"

#ifdef __WINDOWS__
#include <windows.h>
#else
// POSIX file system
#include <sys/stat.h>
#include <dirent.h>
#endif


bool_t fs_mkdir(const char* path) {

#ifdef __WINDOWS__
	return CreateDirectoryA((LPCSTR) path, NULL) ? true : false;
#else
	return mkdir(path, 0777) != -1 ? true : false;
#endif

}

bool_t fs_dir_exists(const char* path) {

#ifdef __WINDOWS__
	DWORD dwAttrib = GetFileAttributes((LPCSTR) path);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY)) ? true : false;
#else
	struct stat sb;

	return (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)) ? true : false;
#endif

}

bool_t fs_get_dir_contents(const char* path, const char* extension, void (*handler) (const char*)) {

#ifdef __WINDOWS__
	WIN32_FIND_DATA find;
	HANDLE file;

	char searchPath[MAX_PATH];

	sprintf(searchPath, "%s\\*.%s", path, extension);

	if ((file = FindFirstFile(searchPath, &find)) == INVALID_HANDLE_VALUE) {
		return false;
	}

	do {

		if(!(find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			handler(find.cFileName);
		}

	} while (FindNextFile(file, &find));

	FindClose(file);
#else
	DIR *d;
	d = opendir(path);
	if (d) {
		struct dirent *dir;
		size_t extension_len = strlen(extension);

		while ((dir = readdir(d)) != NULL) {
			if (strcmp(dir->d_name + (strlen(dir->d_name) - extension_len), extension) == 0) {
				handler(dir->d_name);
			}
		}
		closedir(d);
	}
#endif

	return true;

}

bool_t fs_file_exists(const char* path) {

	FILE* file = fopen(path, "r");

	if (file != NULL) {
		fclose(file);
		return true;
	}

	return false;

}