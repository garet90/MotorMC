#pragma once
#include "../../main.h"

#define SCK_OK 0
#define SCK_FAILED -1

#ifdef __WINDOWS__
#include <winsock2.h>
#else
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#endif

extern int32_t sck_init();
extern int32_t sck_create();
extern int32_t sck_bind(int32_t, struct sockaddr*, int32_t);
extern int32_t sck_listen(int32_t);
extern int32_t sck_accept(int32_t, struct sockaddr*, int*);
extern int32_t sck_send(int32_t, char*, int32_t);
extern int32_t sck_recv(int32_t, char*, int32_t);
extern int32_t sck_shutdown(int32_t);
extern int32_t sck_close(int32_t);

extern void sck_term();
