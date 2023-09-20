#pragma once
#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include "timer.hpp"

namespace arkanoid {

class Player {
public:
    Player() = delete;
    explicit Player(float a_xVel, sf::Vector2f a_size, sf::Vector2f a_initPos);
    Player(Player const& a_other) = delete;
    Player& operator=(Player const& a_other) = delete;
    ~Player() = default;

    sf::Vector2f getInitPos() const noexcept;
    void draw(sf::RenderTarget& a_target) const;

    void movePaddle(float a_xVel, float a_yVel);
    sf::Vector2f getPaddlePos() const noexcept;
    sf::RectangleShape const& getPaddle() noexcept;
    sf::FloatRect getPaddleBounding() const noexcept;
    void setPaddlePos(float a_xVel, float a_yVel);

    void setLives();
    void resetLives() noexcept;
    size_t getLives() const noexcept;
    size_t getScore() const noexcept;
    void addPoints(size_t a_points) noexcept;
    void resetPoints() noexcept;

    void startTheTimer() noexcept;
    void stopTheTimer() noexcept;
    double getTotalTime() const noexcept;
    double getTimeTillNow () const noexcept;

private:
    size_t m_lives;
    size_t m_score;
    Paddle m_paddle;
    Timer m_timer;
};

} //arkanoid