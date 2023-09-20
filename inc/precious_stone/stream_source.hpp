#ifndef CONSOLESOURCE_H_7342
#define CONSOLESOURCE_H_7342

#include "source.hpp"

namespace precious_stone {

class StreamSource: public Source {
public:
    StreamSource() = default;
    ~StreamSource() override = default;

    Message readMessege() override;
    bool isDone() const noexcept override;

private:
    bool m_hasData = false;
};

} //precious_stone

#endif // CONSOLESOURCE_H_7342
