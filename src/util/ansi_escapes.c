#include <stdio.h>
#include "ansi_escapes.h"
#include "../io/logger/logger.h"

#ifdef __WINDOWS__
#include <windows.h>
#endif

/*
 * Shamelessly stolen from https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/
 */

char utl_stdoutBuffer[UTL_CONSOLE_BUFFER_SIZE];

#ifdef __WINDOWS__
// Some old MinGW/CYGWIN distributions don't define this:
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif

static HANDLE utl_stdoutHandle;
static DWORD utl_outModeInit;

void utl_setup_console(void) {
	setvbuf(stdout, utl_stdoutBuffer, _IOLBF, UTL_CONSOLE_BUFFER_SIZE);

	DWORD outMode = 0;
	utl_stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if(utl_stdoutHandle == INVALID_HANDLE_VALUE) {
		log_error("Error setting up console: %d", GetLastError());
	}

	if(!GetConsoleMode(utl_stdoutHandle, &outMode)) {
		log_error("Error setting up console: %d", GetLastError());
	}

	utl_outModeInit = outMode;

	// Enable ANSI escape codes
	outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	if(!SetConsoleMode(utl_stdoutHandle, outMode)) {
		log_error("Error setting up console: %d", GetLastError());
	}
}

void utl_restore_console(void) {
	// Reset colors
	printf("\x1b[0m\n");
	fflush(stdout);

	// Reset console mode
	if(!SetConsoleMode(utl_stdoutHandle, utl_outModeInit)) {
		exit(GetLastError());
	}
}
#else
void utl_setup_console(void) {
	setvbuf(stdout, utl_stdoutBuffer, _IOLBF, UTL_CONSOLE_BUFFER_SIZE);
}

void utl_restore_console(void) {
	// Reset colors
	printf("\x1b[0m\n");
	fflush(stdout);
}
#endif
