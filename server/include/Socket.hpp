#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <string>

class Socket{
private:
    int fd;

public:
    Socket(std::string port,const struct addrinfo *hints, struct addrinfo *res ){
        int s;
        int status;

        std::cout<<"Creating the socket"<<std::endl;
        if ((status = ::getaddrinfo(NULL, port.data(), hints, &res )) != 0){
            std::cout<<stderr<<"gai error:\n"<<gai_strerror(status);
            exit(1);
        }
        
        s = ::socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        
    };
    
    // ::~Socket();

    int getaddrinfo(const char *node, 
                    const char *port,
                    const struct addrinfo *hints,
                    struct addrinfo **res);

    int socket(int domain, int type, int protocol);
    
    void bind();
    void listen();
    void accept();
    void send();
    void receive();

};