#ifndef CONVERT_CAESAR_H_734
#define CONVERT_CAESAR_H_734

#include "encoder.hpp"
#include "message.hpp"

namespace precious_stone {

class ConvertCaesar : public Encoder {
public:
    ConvertCaesar() = default;
    explicit ConvertCaesar(const ConvertCaesar& a_other) = default;
    ConvertCaesar& operator = (const ConvertCaesar& a_other) = default;
    ~ConvertCaesar() = default;
    
    Message messageEncoder(Message& a_message) override;
};

} //precious_stone

#endif //CONVERT_CAESAR_H_734





