#include <include/Socket.hpp>
#include <cstring>
#include <string>

#define PORT "8000"

int main(){
    int status;
    struct addrinfo hints;
    struct addrindfo *res;
    
    memset(&hints,0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    
    Socket socket(std::string(PORT), hints, res);
}