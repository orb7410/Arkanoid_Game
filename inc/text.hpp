#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "font.hpp"

namespace arkanoid {

class Text {
    public:
    explicit Text(std::string const& a_text, Font const& a_font, sf::Vector2f const& a_position, unsigned int a_characterSize, sf::Color const& a_color);

    ~Text() = default;

    void setText(std::string const& a_text);
    void setPosition(sf::Vector2f const& a_position);
    void setOrigin(sf::Vector2f const& a_origin);
    void setCharacterSize(unsigned int a_size);
    void setFillColor(sf::Color const& a_color);
    void setOutlineThickness(float a_thickness);
    void setOutlineColor(sf::Color const& a_color);
    sf::Vector2f getPosition() const noexcept;

    sf::Text const& get() const noexcept;
    void draw(sf::RenderTarget& a_target) const noexcept;
    std::string getString() const;

private:
    sf::Text m_text;
};

} //arkanoid