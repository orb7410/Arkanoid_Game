#ifndef UDP_H_73
#define UDP_H_73

#include <sys/types.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>
#include "message.hpp"
namespace precious_stone {

class Udp{
public:
    Udp() = delete;
    explicit Udp(int a_port, std::string const& a_ip);
    Udp(Udp const& a_other) = delete;
    ~Udp();

    void send(Message const& a_message) const;
    
private:
    int m_socket; 
    struct sockaddr_in m_sin;
};

} //precious_stone

#endif //UDP_H_73
