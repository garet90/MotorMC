#pragma once
#include "../../main.h"
#include "../chat/chat.h"

#define LOG_P1 "\r\033[2K\033["
#define LOG_P2 "m[%02u:%02u:%02u "
#define LOG_P3 "]: "
#define LOG_S1 "\033[0m\n"

/*
#define LOG_PUT(color, sender, format, ...) ({ time_t now = time(NULL); struct tm *tm_struct = localtime(&now); log_put(LOG_P1 color LOG_P2 sender LOG_P3 format LOG_S1, tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec, ##__VA_ARGS__); })

#define log_info(format, ...) LOG_PUT("0", "INFO", format, ##__VA_ARGS__)
#define log_warn(format, ...) LOG_PUT("93", "WARN", format, ##__VA_ARGS__)
#define log_error(format, ...) LOG_PUT("91", "ERROR", format, ##__VA_ARGS__)
*/

extern void log_command(const cht_component_t*);

extern void log_info(const char*, ...);
extern void log_warn(const char*, ...);
extern void log_error(const char*, ...);

extern size_t log_to_string(char*, const cht_component_t*);
