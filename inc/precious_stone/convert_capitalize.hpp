#ifndef CONVERT_CAPITALIZE_H_734
#define CONVERT_CAPITALIZE_H_734

#include "encoder.hpp"

namespace precious_stone {

class ConvertCapitalize : public Encoder {
public:
    ConvertCapitalize() = default;
    explicit ConvertCapitalize(const ConvertCapitalize& a_other) = default;
    ConvertCapitalize& operator = (const ConvertCapitalize& a_other) = default;
    ~ConvertCapitalize() = default;
    
    Message messageEncoder(Message& a_message) override;
};

} //precious_stone

#endif //CONVERT_CAPITALIZE_H_734
