#ifndef MESSAGE_H_7354
#define MESSAGE_H_7354

#include <string>
namespace precious_stone {

class Message{
public:
    Message() = delete;
    explicit Message(std::string const& a_msg);

    const std::string&  get() const;

private:
    std::string m_message;
};

} //precious_stone



#endif //MESSAGE_H_7354
