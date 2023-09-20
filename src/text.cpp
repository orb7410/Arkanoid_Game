#include "text.hpp"

namespace arkanoid {

Text::Text(std::string const& a_text, Font const& a_font, sf::Vector2f const& a_position, unsigned int a_characterSize, sf::Color const& a_color)
: m_text(a_text, a_font.get())
{
    m_text.setPosition(a_position);
	m_text.setFillColor(a_color);
    m_text.setCharacterSize(a_characterSize);
}

void Text::setText(std::string const& a_text) 
{
    m_text.setString(a_text);
}

void Text::setOrigin(sf::Vector2f const& a_origin)
{
    m_text.setOrigin(a_origin);
}

void Text::setPosition(sf::Vector2f const& a_position) 
{
    m_text.setPosition(a_position);
}

void Text::setFillColor(sf::Color const& a_color) 
{
    m_text.setFillColor(a_color);
}

void Text::setOutlineColor(sf::Color const& a_color) 
{
    m_text.setOutlineColor(a_color);
}

void Text::setOutlineThickness(float a_thickness) 
{
    m_text.setOutlineThickness(a_thickness);
}

void Text::setCharacterSize(unsigned int a_charSize) 
{
    m_text.setCharacterSize(a_charSize);
}

sf::Text const& Text::get() const noexcept 
{
    return m_text;
}

std::string Text::getString() const 
{
    return m_text.getString();
}

void Text::draw(sf::RenderTarget& a_target) const noexcept
{
    a_target.draw(m_text);
}

sf::Vector2f Text::getPosition() const noexcept
{
    return m_text.getPosition();
}

} //arkanoid