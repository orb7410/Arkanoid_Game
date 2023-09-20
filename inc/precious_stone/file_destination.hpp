#ifndef FILE_DESTINATION_H_734
#define FILE_DESTINATION_H_734

#include "destination.hpp"
#include "message.hpp"

namespace precious_stone {

class TextFileDestination: public Destination {
public:
    explicit TextFileDestination(std::string a_fileName);
    ~TextFileDestination() override = default;

    void sendMessege(Message const& a_message) override;

private:
    std::string m_fileName;
};


}//precious_stone



#endif //FILE_DESTINATION_H_734
