#pragma once
#include <SFML/Graphics.hpp>
#include "game_object.hpp"
namespace arkanoid {

class Ball : public GameObject{
public:
    Ball() = delete;
    explicit Ball(float a_xVel, float a_yVel, float a_radious, sf::Vector2f a_initPos);
    Ball(Ball const& a_other) = delete;
    Ball& operator=(Ball const& a_other) = delete;
    ~Ball() = default;

    void draw(sf::RenderTarget& a_target) const noexcept override;
    sf::FloatRect getBounding() const noexcept override;
    sf::CircleShape const& getBall();
    float getXVal() const noexcept;
    float getYVal() const noexcept;
    sf::Vector2f getPos() const noexcept;
    void setPos(float a_xVal, float a_yVal) noexcept;
    void setXVal(float a_val) noexcept;
    void setYVal(float a_val) noexcept;
    sf::Vector2f getInitPos() const noexcept;
private:
    sf::Vector2f m_initPos;
    sf::CircleShape m_ball;
    float m_xVelocity = 5;
    float m_yVelocity = 5;
    

};

} //arkanoid
