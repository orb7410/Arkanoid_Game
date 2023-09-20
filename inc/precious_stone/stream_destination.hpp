#ifndef CONSOLEDESTINATION_H_73
#define CONSOLEDESTINATION_H_73

#include <ostream>
#include "destination.hpp"
#include "message.hpp"

namespace precious_stone{

class StreamDestination : public Destination{
public:
    explicit StreamDestination(std::ostream& a_os);
    ~StreamDestination() override = default;

    void sendMessege(Message const& a_message) override;
private:
    std::ostream& m_os;
	bool flag;
};

}//precious_stone

#endif /*CONSOLEDESTINATION_H_73*/
