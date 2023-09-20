#ifndef BlackBox_H_73
#define BlackBox_H_73

#include "message.hpp"
#include "destination.hpp"
#include "source.hpp"
#include "encoder.hpp"
namespace precious_stone{

class BlackBox{
public:
    BlackBox() = delete;
    explicit BlackBox(Source& a_sorurce, Destination& a_destination, Encoder& a_encoder);
    void execut() const;
    
private:
    Source& m_sorurce;
    Destination& m_destination;
    Encoder& m_encoder;
};


}//precious_stone

#endif /*BlackBox_H_73*/

