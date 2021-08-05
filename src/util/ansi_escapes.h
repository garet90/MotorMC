#pragma once
#include "../main.h"

#define UTL_CONSOLE_BUFFER_SIZE 4096

#define UTL_CONSOLE_RESET    "\033[0m"

#define UTL_CONSOLE_BLACK    "\033[30m"
#define UTL_CONSOLE_RED      "\033[31m"
#define UTL_CONSOLE_GREEN    "\033[32m"
#define UTL_CONSOLE_YELLOW   "\033[33m"
#define UTL_CONSOLE_BLUE     "\033[34m"
#define UTL_CONSOLE_MAGENTA  "\033[35m"
#define UTL_CONSOLE_CYAN     "\033[36m"
#define UTL_CONSOLE_WHITE    "\033[37m"

#define UTL_CONSOLE_BRIGHT_BLACK    "\033[30;1m"
#define UTL_CONSOLE_BRIGHT_RED      "\033[31;1m"
#define UTL_CONSOLE_BRIGHT_GREEN    "\033[32;1m"
#define UTL_CONSOLE_BRIGHT_YELLOW   "\033[33;1m"
#define UTL_CONSOLE_BRIGHT_BLUE     "\033[34;1m"
#define UTL_CONSOLE_BRIGHT_MAGENTA  "\033[35;1m"
#define UTL_CONSOLE_BRIGHT_CYAN     "\033[36;1m"
#define UTL_CONSOLE_BRIGHT_WHITE    "\033[37;1m"

extern void utl_setup_console();
extern void utl_restore_console();
