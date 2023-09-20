#include "paddle.hpp"
#include <SFML/Graphics.hpp>

namespace arkanoid {

namespace {
sf::RectangleShape initPaddle(sf::Vector2f a_pos, sf::Vector2f a_size) {
   sf::RectangleShape rectangl(a_size);
    rectangl.setFillColor(sf::Color(0, 204, 153));
    rectangl.setPosition(a_pos);
    return rectangl; 
}    
} //namespace

Paddle::Paddle(float a_xVel, sf::Vector2f a_size, sf::Vector2f a_initPos) 
: m_initPos(a_initPos)
, m_paddle(initPaddle(m_initPos, a_size))
, m_xVelocity(a_xVel) {   
}

void Paddle::draw(sf::RenderTarget& a_target) const noexcept{
    a_target.draw(m_paddle);
}

void Paddle::move(float a_xVel, float a_yVel) {
    m_paddle.move(a_xVel, a_yVel);
}

sf::Vector2f Paddle::getPos() const noexcept {
    return m_paddle.getPosition();
}

sf::Vector2f Paddle::getInitPos() const noexcept {
    return m_initPos;
}

sf::RectangleShape const& Paddle::getPaddle() noexcept {
    return m_paddle;
}

sf::FloatRect Paddle::getBounding() const noexcept {
    return m_paddle.getGlobalBounds();
}

void Paddle::setPos(float a_xVel, float a_yVel) {
    m_paddle.setPosition(a_xVel, a_yVel);
}
} //arkanoid
