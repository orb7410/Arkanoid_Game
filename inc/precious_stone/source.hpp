#ifndef SOURCE_H_73
#define SOURCE_H_73


#include "message.hpp"

namespace precious_stone {

class Source{
public:
    virtual ~Source() = default;
    virtual Message readMessege() = 0;
    virtual bool isDone() const noexcept = 0;

protected:
    Source() = default;
    Source(Source const& a_other) = default;
    Source& operator=(Source const& a_other) = default;
};


} // precious_stone

#endif /*SOURCE_H_73*/
