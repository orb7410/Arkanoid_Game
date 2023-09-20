
#include "color.hpp"
#include <iostream>

namespace advcpp{
template<typename T>
Color<T>::Color(unsigned char a_rad, unsigned char a_green, unsigned char a_blue)
: m_rad(a_rad)
, m_green(a_green)
, m_blue(a_blue)
{}

template<typename T>
Color<T>::Color(const Color<T>& a_other)
: m_rad(a_other.m_rad)
, m_green(a_other.m_green)
, m_blue(a_other.m_blue)
{}

template<typename T>
Color<T>& Color<T>::operator=(const Color<T>& a_other){
    if (this != &a_other) {
       m_rad = a_other.m_rad;
       m_green = a_other.m_green;
       m_blue = a_other.m_blue;
    }
    return *this;
}
/*
void Color::PrintColor() const{
    std::cout<< static_cast<int>(m_rad) << "," << static_cast<int>(m_green) <<","<< static_cast<int>(m_blue)<<" ";
}*/
}/*advcpp*/
