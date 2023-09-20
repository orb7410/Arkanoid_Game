#pragma once
#include <SFML/Graphics.hpp>
#include "game_object.hpp"

namespace arkanoid {

class Paddle : public GameObject{
public:
    Paddle() = delete;
    explicit Paddle(float a_xVel, sf::Vector2f a_size, sf::Vector2f a_initPos);
    Paddle(Paddle const& a_other) = delete;
    Paddle& operator=(Paddle const& a_other) = delete;
    ~Paddle() = default;

    void draw(sf::RenderTarget& a_target) const noexcept override;
    void move(float a_xVel, float a_yVel);
    sf::Vector2f getPos() const noexcept;
    sf::RectangleShape const& getPaddle() noexcept;
    sf::FloatRect getBounding() const noexcept override;
    sf::Vector2f getInitPos() const noexcept;
    void setPos(float a_xVel, float a_yVel);
private:
    sf::Vector2f m_initPos;
    sf::RectangleShape m_paddle;
    float m_xVelocity = 5;
};

} //arkanoid

