#include "vf_sock.h"

/**
 * socket constructor
 * 
 * domain: The ip protocol that socket uses like AF_INET and AFINET6.
 * type: The data transfer type that socket uses like SOCK_STREAM and SOCK_DGRAM.
 * protocl: The transfer protocol that socket uses like IPPROTO_TCP and IPPROTO_UDP.
 * ipaddress: The ip address.
 * port: The port number.
 */
vf_sock::vf_sock(
    int domain, 
    int type, 
    int protocol,
    char* ipaddress,
    int port
)
{
    this->fd = socket(domain, type, protocol);

    this->domain = domain;
    this->type = type;
    this->protocol = protocol;
    this->ipaddress = ipaddress;
    this->port = port;

    memset(&this->server_sock, 0, sizeof(this->server_sock));
    this->server_sock.sin_family = domain;
    this->server_sock.sin_addr.s_addr = inet_addr(ipaddress);
    this->server_sock.sin_port = htons(port);
}


/**
 * Bind file descriptor to socket.
 */
void vf_sock::bind_socket() {
    bind(fd, (sockaddr*)&server_sock, sizeof(server_sock));
}

/**
 * Just start listen socket, don't block the process.
 */
void vf_sock::start_listen() {
    listen(fd, 20);
}

/**
 * Wait for client and block the process.
 */
void vf_sock::start_accept() {

    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(fd, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
}

vf_sock::~vf_sock()
{
}
