#ifndef NONCODED_ENCODER_H_73
#define NONCODED_ENCODER_H_73
#include <iostream>
#include "message.hpp"
#include "encoder.hpp"

namespace precious_stone{

class NonCodedEncoder:public Encoder{
public:
    NonCodedEncoder() = default;
    ~NonCodedEncoder() override = default;
    
    Message messageEncoder(Message& a_message) override;
};

inline Message NonCodedEncoder::messageEncoder(Message& a_message){
    return a_message;
}
}//precious_stone

#endif /*NONCODED_ENCODER_H_73*/

