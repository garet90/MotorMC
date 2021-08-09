#include <stdarg.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "logger.h"
#include "../../io/commands/commands.h"
#include "../../util/ansi_escapes.h"
#include "../../motor.h"

// The log is locked so multiple messages from different threads don't interfere
pthread_mutex_t log_lock = PTHREAD_MUTEX_INITIALIZER;

void log_put(const char* format, ...) {

	pthread_mutex_lock(&log_lock);

	va_list args;
	va_start(args, format);

	vfprintf(stdout, format, args);
	va_end(args);

	fflush(stdout);

	pthread_mutex_unlock(&log_lock);

}

void log_command(cmd_sender_t* sender, const cht_component_t* chat) {

	if (sender != &sky_main.console) {
		log_error("Trying to send a command message to the console that wasn't intended for the console!");
		return;
	}

	char message[512];

	message[log_to_string(message, chat)] = '\0';
	log_info("%s", message);

}

void log_info(const char* format, ...) {

	pthread_mutex_lock(&log_lock);

	// prefix
	time_t now = time(NULL);
	struct tm *tm_struct = localtime(&now);
	fprintf(stdout, LOG_P1 "0" LOG_P2 "INFO" LOG_P3, tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec);

	// body
	va_list args;
	va_start(args, format);

	vfprintf(stdout, format, args);
	va_end(args);

	// suffix
	fprintf(stdout, LOG_S1);

	fflush(stdout);

	pthread_mutex_unlock(&log_lock);

}

void log_warn(const char* format, ...) {

	pthread_mutex_lock(&log_lock);

	// prefix
	time_t now = time(NULL);
	struct tm *tm_struct = localtime(&now);
	fprintf(stdout, LOG_P1 "93" LOG_P2 "WARN" LOG_P3, tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec);

	// body
	va_list args;
	va_start(args, format);

	vfprintf(stdout, format, args);
	va_end(args);

	// suffix
	fprintf(stdout, LOG_S1);

	fflush(stdout);

	pthread_mutex_unlock(&log_lock);

}

void log_error(const char* format, ...) {

	pthread_mutex_lock(&log_lock);

	// prefix
	time_t now = time(NULL);
	struct tm *tm_struct = localtime(&now);
	fprintf(stdout, LOG_P1 "91" LOG_P2 "ERROR" LOG_P3, tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec);

	// body
	va_list args;
	va_start(args, format);

	vfprintf(stdout, format, args);
	va_end(args);

	// suffix
	fprintf(stdout, LOG_S1);

	fflush(stdout);

	pthread_mutex_unlock(&log_lock);

}

uint32_t log_to_string(char* message, const cht_component_t* chat) {

	uint32_t offset = 0;

	if (chat->color <= 0xF) {
		switch (chat->color) {
		case cht_black:
			offset += sprintf(message + offset, UTL_CONSOLE_BLACK);
			break;
		case cht_dark_blue:
			offset += sprintf(message + offset, UTL_CONSOLE_BLUE);
			break;
		case cht_dark_green:
			offset += sprintf(message + offset, UTL_CONSOLE_GREEN);
			break;
		case cht_dark_cyan:
			offset += sprintf(message + offset, UTL_CONSOLE_CYAN);
			break;
		case cht_dark_red:
			offset += sprintf(message + offset, UTL_CONSOLE_RED);
			break;
		case cht_purple:
			offset += sprintf(message + offset, UTL_CONSOLE_MAGENTA);
			break;
		case cht_gold:
			offset += sprintf(message + offset, UTL_CONSOLE_YELLOW);
			break;
		case cht_gray:
			offset += sprintf(message + offset, UTL_CONSOLE_WHITE);
			break;
		case cht_dark_gray:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_BLACK);
			break;
		case cht_blue:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_BLUE);
			break;
		case cht_bright_green:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_GREEN);
			break;
		case cht_cyan:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_CYAN);
			break;
		case cht_red:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_RED);
			break;
		case cht_pink:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_MAGENTA);
			break;
		case cht_yellow:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_YELLOW);
			break;
		case cht_white:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_WHITE);
			break;
		case cht_nocolor:
			break;
		}
	}

	offset += sprintf(message + offset, "%s", chat->text);

	if (chat->extra.size != 0) {

		for (uint32_t i = 0; i < chat->extra.size; ++i) {
			offset += log_to_string(message + offset, UTL_VECTOR_GET_AS(cht_component_t*, &chat->extra, i));
		}

	}

	return offset;

}
