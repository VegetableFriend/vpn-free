#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>

class vf_sock
{
private:
    int fd;
    sockaddr_in server_sock;
    sockaddr_in client_sock;

    int domain;
    int type;
    int protocol;
    char* ipaddress;
    int port;
public:
    vf_sock(int domain, int type, int protocol, char* ipaddress, int port);
    ~vf_sock();

    void bind_socket();
    void start_listen();
    void start_accept();
};