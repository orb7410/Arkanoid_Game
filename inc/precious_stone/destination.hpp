#ifndef DESTINATION_H_73
#define DESTINATION_H_73

#include "message.hpp"

namespace precious_stone {

class Destination{
public:
    virtual ~Destination() = default;

    virtual void sendMessege(Message const& a_message) = 0;

protected:
    Destination() = default;
    Destination(Destination const& a_other) = default;
    Destination& operator=(Destination const& a_other) = default;
};


}//precious_stone

#endif /*DESTINATION_H_73*/
