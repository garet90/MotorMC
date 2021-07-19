#include "socket.h"
#include "../../io/logger/logger.h"


#ifdef __WINDOWS__
	WSADATA sck_wsa;
#endif

int32_t sck_init() {

#ifdef __WINDOWS__
	if (WSAStartup(MAKEWORD(2,2), &sck_wsa) != 0) {
		log_error("Error starting WinSock : %d", WSAGetLastError());
		return 1;
	}
#endif

	return 0;

}

int32_t sck_create() {

	uint64_t s = socket(AF_INET, SOCK_STREAM, 0);

#ifdef __WINDOWS__
	if (s == INVALID_SOCKET) {
		log_error("Error creating socket : %d", WSAGetLastError());
	}
#endif

	return s;

}

int32_t sck_bind(int32_t s, struct sockaddr* addr, int32_t addrSize) {

	int32_t b = bind(s, addr, addrSize);

#ifdef __WINDOWS__
	if (b != 0) {
		log_error("Failed to bind to port! Is another server already running on that port? : %d", WSAGetLastError());
	}
#endif

	return b;

}

int32_t sck_listen(int32_t s) {

	int32_t l = listen(s, 3);

	if (l != 0) {
		log_error("Failed to listen on socket!");
	}

	return l;

}

int32_t sck_accept(int32_t l, struct sockaddr* addr, int* addrSize) {

#ifdef __WINDOWS__
	return accept(l, addr, addrSize);
#else
	return accept(l, addr, (unsigned int*) addrSize);
#endif

}

int32_t sck_send(int32_t s, char* message, int32_t len) {

	return send(s, message, len, 0);

}

int32_t sck_recv(int32_t s, char* message, int32_t maxlen) {

	int32_t r = recv(s, message, maxlen, 0);

	return r;

}

void sck_close(int32_t s) {

#ifdef __WINDOWS__
	closesocket(s);
#else
	shutdown(s, SHUT_RDWR);
#endif

}

void sck_term() {
#ifdef __WINDOWS__
	WSACleanup();
#endif
}
