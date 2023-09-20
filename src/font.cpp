#include "font.hpp"

namespace arkanoid {


Font::Font(std::string const& a_fontName)
: m_font{}
{
	if (!m_font.loadFromFile(a_fontName)) {
       throw "cant load font";
    }
}

sf::Font const& Font::get() const noexcept {
    return m_font;
}

} //arkanoid