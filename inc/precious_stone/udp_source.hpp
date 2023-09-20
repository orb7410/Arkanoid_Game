#ifndef UDP_SOURCE_H_73
#define UDP_SOURCE_H_73

#include "source.hpp"
#include "udp.hpp"

namespace precious_stone {

class UdpSource : public Source {
public:
    UdpSource() = delete;
    explicit UdpSource(int a_port, const std::string& a_ip);
    UdpSource(UdpSource const& a_other) = delete;
    ~UdpSource() override = default;

    Message readMessege() override;
    bool isDone() const noexcept override;
    
private:
    Udp m_udp;
};

} //precious_stone

#endif //UDP_SOURCE_H_73
