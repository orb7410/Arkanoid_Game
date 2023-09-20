#ifndef ENCODER_H_73
#define ENCODER_H_73

#include "message.hpp"
namespace precious_stone {

class Encoder {
public:
    virtual ~Encoder() = default;
    
    virtual Message messageEncoder(Message& a_message) = 0;

protected:
    Encoder() = default;
    Encoder(Encoder const& a_other) = default;
    Encoder& operator=(Encoder const& a_other) = default;
};

}//precious_stone

#endif /*ENCODER_H_73*/

