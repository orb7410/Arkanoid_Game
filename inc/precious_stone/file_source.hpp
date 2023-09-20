#ifndef FILE_SOURCE_H_734
#define FILE_SOURCE_H_734

#include "source.hpp"

namespace precious_stone {

class TextFileSource: public Source {
public:
    explicit TextFileSource(const std::string a_fileName);
    ~TextFileSource() override = default;

    Message readMessege() override;
    bool isDone() const noexcept override;

private:
    std::string m_fileName;
};


}//precious_stone



#endif //FILE_SOURCE_H_734
