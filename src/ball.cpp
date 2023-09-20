#include "ball.hpp"
#include <SFML/Graphics.hpp>

namespace arkanoid {


Ball::Ball(float a_xVel, float a_yVel, float a_radious, sf::Vector2f a_initPos)
: m_initPos(a_initPos)
, m_ball(sf::CircleShape(a_radious))
, m_xVelocity(a_xVel)
, m_yVelocity(a_yVel) 
{   
    sf::Vector2f circlePosition(50.f, 50.f);
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
    m_ball.setPosition(m_initPos);
	m_ball.setOutlineThickness(1.f);
	m_ball.setOutlineColor(sf::Color(255, 0, 102));
    m_ball.setFillColor(sf::Color(255, 153, 255));
}

sf::CircleShape const& Ball::getBall() 
{
    return m_ball;
}

sf::FloatRect Ball::getBounding() const noexcept 
{
    return m_ball.getGlobalBounds();
}

float Ball::getXVal() const noexcept 
{
    return m_xVelocity;
}

void Ball::setXVal(float a_val) noexcept 
{
    m_xVelocity = a_val;
}

void Ball::setYVal(float a_val) noexcept 
{
    m_yVelocity = a_val;
}

float Ball::getYVal() const noexcept 
{
    return m_yVelocity;
}

void Ball::setPos(float a_xVal, float a_yVal) noexcept{
    m_ball.setPosition(a_xVal, a_yVal);
}


sf::Vector2f Ball::getPos() const noexcept {
    return m_ball.getPosition();
}

sf::Vector2f Ball::getInitPos() const noexcept {
    return m_initPos;
}

void Ball::draw(sf::RenderTarget& a_target) const noexcept{
    a_target.draw(m_ball);
}

} //arkanoid
