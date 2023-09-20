#ifndef CONVERT_VOWEL_H_734
#define CONVERT_VOWEL_H_734

#include "encoder.hpp"
#include "message.hpp"

namespace precious_stone {

class ConvertVowel : public Encoder {
public:
    ConvertVowel() = default;
    explicit ConvertVowel(const ConvertVowel& a_other) = default;
    ConvertVowel& operator = (const ConvertVowel& a_other) = default;
    ~ConvertVowel() = default;
    
    Message messageEncoder(Message& a_message) override;
};

} //precious_stone

#endif //CONVERT_VOWEL_H_734