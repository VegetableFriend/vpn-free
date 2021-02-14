#include <stdio.h>
#include "vf_sock.h"

int main(void) {

    vf_sock sock = vf_sock(
        AF_INET,
        SOCK_STREAM,
        IPPROTO_TCP,
        "127.0.0.1",
        9999
    );

    printf("----- Start listen -----\n");

    sock.bind_socket();

    sock.start_listen();

    sock.start_accept();

    printf("----- End listen -----\n");

}