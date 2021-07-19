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

	message[log_toString(message, chat)] = '\0';
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

uint32_t log_toString(char* message, const cht_component_t* chat) {

	uint32_t offset = 0;

	if (chat->color <= 0xF) {
		switch (chat->color) {
		case CHT_BLACK:
			offset += sprintf(message + offset, UTL_CONSOLE_BLACK);
			break;
		case CHT_DARK_BLUE:
			offset += sprintf(message + offset, UTL_CONSOLE_BLUE);
			break;
		case CHT_DARK_GREEN:
			offset += sprintf(message + offset, UTL_CONSOLE_GREEN);
			break;
		case CHT_DARK_CYAN:
			offset += sprintf(message + offset, UTL_CONSOLE_CYAN);
			break;
		case CHT_DARK_RED:
			offset += sprintf(message + offset, UTL_CONSOLE_RED);
			break;
		case CHT_PURPLE:
			offset += sprintf(message + offset, UTL_CONSOLE_MAGENTA);
			break;
		case CHT_GOLD:
			offset += sprintf(message + offset, UTL_CONSOLE_YELLOW);
			break;
		case CHT_GRAY:
			offset += sprintf(message + offset, UTL_CONSOLE_WHITE);
			break;
		case CHT_DARK_GRAY:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_BLACK);
			break;
		case CHT_BLUE:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_BLUE);
			break;
		case CHT_BRIGHT_GREEN:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_GREEN);
			break;
		case CHT_CYAN:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_CYAN);
			break;
		case CHT_RED:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_RED);
			break;
		case CHT_PINK:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_MAGENTA);
			break;
		case CHT_YELLOW:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_YELLOW);
			break;
		case CHT_WHITE:
			offset += sprintf(message + offset, UTL_CONSOLE_BRIGHT_WHITE);
			break;
		case CHT_NOCOLOR:
			break;
		}
	}

	offset += sprintf(message + offset, "%s", chat->text);

	if (chat->extra != NULL) {

		for (uint32_t i = 0; i < chat->extra->size; ++i) {
			offset += log_toString(message + offset, utl_vectorGetAs(cht_component_t*, chat->extra, i));
		}

	}

	return offset;

}
