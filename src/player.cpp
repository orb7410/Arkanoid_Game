#include <SFML/Graphics.hpp>
#include "player.hpp"

namespace arkanoid {
 
Player::Player(float a_xVel, sf::Vector2f a_size, sf::Vector2f a_initPos) 
: m_lives(1)
, m_score(0)
, m_paddle(Paddle(a_xVel, a_size, a_initPos))
, m_timer() {   
}

void Player::startTheTimer() noexcept {
    m_timer.start();
}

void Player::stopTheTimer() noexcept {
    m_timer.stop();
}

double Player::getTotalTime() const noexcept {
    return m_timer.getTotalTimeInSeconds();
}

double Player::getTimeTillNow() const noexcept {
    return m_timer.getTimeTillNow();
}

sf::Vector2f Player::getInitPos() const noexcept {
    return m_paddle.getInitPos();
}

void Player::draw(sf::RenderTarget& a_target) const {
    m_paddle.draw(a_target);
}

void Player::movePaddle(float a_xVel, float a_yVel) {
    m_paddle.move(a_xVel, a_yVel);
}

sf::Vector2f Player::getPaddlePos() const noexcept {
    return m_paddle.getPos();
}

void Player::setPaddlePos(float a_xVel, float a_yVel) {
    m_paddle.setPos(a_xVel, a_yVel);
}

sf::RectangleShape const& Player::getPaddle() noexcept{
    return m_paddle.getPaddle();
}

sf::FloatRect Player::getPaddleBounding() const noexcept {
    return m_paddle.getBounding();
}

size_t Player::getScore() const noexcept {
    return m_score;
}

size_t Player::getLives() const noexcept {
    return m_lives;
}
void Player::setLives() {
    if(m_lives > 0) {
        --m_lives;
    }
}
void Player::addPoints(size_t a_points) noexcept {
    m_score += a_points;
}

void Player::resetPoints() noexcept {
    m_score = 0;
}

void Player::resetLives() noexcept {
    m_lives = 3;
}
}