#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <string>

class Socket{
private:
    int socketfd;
    struct addrinfo *res;

public:
    Socket(std::string port,const struct addrinfo *hints ){
        int status;

        std::cout<<"Creating the socket"<<std::endl;
        if ((status = ::getaddrinfo(NULL, port.data(), hints, &res )) != 0){
            std::cout<<stderr<<"gai error:\n"<<gai_strerror(status);
            exit(1);
        }
        
        socketfd = ::socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if(socketfd == -1){
            std::cout<<"Creation has been failed\n";
            std::exit(1);
        }else{
            std::cout<<"Creation of socket was a success\n";
            std::cout<<"This is the socketfd: "<<socketfd<<std::endl;
        }

    };
    
    // ::~Socket();
    
    int getSocketfd() const{
        return socketfd;
    }

    void bind(){
        std::cout<<"Binding the socket\n";
        int bindValue = ::bind(socketfd, res->ai_addr, res->ai_addrlen);
        if(bindValue<0){
            std::cout<<"Binding process was a failure\n";
            std::exit(1);
        }else{
            std::cout<<"Binding process was a success\n";
        }
    };


    void listen(){
        std::cout<<"Listening is initialized\n";
        int listenValue = ::listen(socketfd, 5);
        if(listenValue<0){
            std::cout<<"Listening was failure\n";
            std::exit(1);
        }else{
            std::cout<<"Listening was sucessfull\n";
        }
    };
    void accept();
    void send();
    void receive();

};