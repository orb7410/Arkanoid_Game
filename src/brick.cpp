#include <SFML/Graphics.hpp>

#include "brick.hpp"

namespace arkanoid {
const std::unordered_map<Brick::Color, std::pair<size_t, sf::Color>> bricksMap {
    {Brick::RED, {90, sf::Color::Red}},
    {Brick::BLUE, {100, sf::Color::Blue}},
    {Brick::PINK, {110, sf::Color(255, 192, 203)}},
    {Brick::GREEN, {80, sf::Color::Green}},
    {Brick::ORANGE, {120, sf::Color(255, 165, 0)}},
    {Brick::PEACH, {60, sf::Color(255, 218, 185)}},
    {Brick::CYAN, {70, sf::Color::Cyan}},
    {Brick::WHITE, {50, sf::Color::White}},
    {Brick::GRAY, {50, sf::Color(128, 128, 128)}},
    {Brick::YELLOW, {0, sf::Color::Yellow}},
};

Brick::Brick(sf::Vector2f a_position, Color a_color, sf::Vector2f a_size, size_t a_level)
: m_brick(a_size) 
, m_color(a_color)
, m_level(a_level)
, m_destructuble(true)
{
    if(m_color == Brick::Color::YELLOW) {
        m_destructuble = false;
    }
    m_brick.setPosition(a_position);
    auto brickDetails = bricksMap.at(a_color);
    m_points = brickDetails.first;
    m_brick.setFillColor(brickDetails.second);
}

sf::RectangleShape const& Brick::getBrick() noexcept 
{
    return m_brick;
}

sf::FloatRect Brick::getBounding() const noexcept 
{
    return m_brick.getGlobalBounds();
}

void Brick::draw(sf::RenderTarget& a_target) const noexcept
{
    a_target.draw(m_brick);
}

sf::Color Brick::getColor() const noexcept
{
    auto brickDetails = bricksMap.at(m_color);
    return brickDetails.second;
}

size_t Brick::getPoints() const noexcept
{
    auto brickDetails = bricksMap.at(m_color);
    if (m_color == Brick::Color::GRAY) {
        return (m_level * brickDetails.first);
    }
    return brickDetails.first;
}

bool Brick::getIsdestructuble() const noexcept 
{
    return m_destructuble;
}

sf::Transform Brick::getTransform() const noexcept 
{
    return m_brick.getTransform();
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    states.transform *= getTransform();
    target.draw(m_brick, states);
}


} //arkanoid