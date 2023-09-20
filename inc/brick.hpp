#pragma once
#include <SFML/Graphics.hpp>
#include "game_object.hpp"
#include <unordered_map>

namespace arkanoid {

class Brick : public GameObject {
public:
    enum Color {
        RED,
        BLUE,
        PINK,
        GREEN,
        ORANGE,
        PEACH,
        CYAN,
        WHITE,
        GRAY,
        YELLOW
    };

    Brick() = delete;
    explicit Brick(sf::Vector2f a_position, Color a_color, sf::Vector2f a_size, size_t a_level);
    Brick(Brick const& a_other) = default;
    Brick& operator=(Brick const& a_other) = default;
    ~Brick() = default;

    sf::FloatRect getBounding() const noexcept override;
    void draw(sf::RenderTarget& a_target) const noexcept override;
    sf::RectangleShape const& getBrick() noexcept;
    sf::Color getColor() const noexcept;
    size_t getPoints() const noexcept;
    sf::Transform getTransform() const noexcept;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool getIsdestructuble() const noexcept;

private:
    sf::Vector2f m_pos;
    sf::RectangleShape m_brick;
    Color m_color;
    size_t m_points;
    size_t m_level;
    bool m_destructuble;
};
} //arkanoid 
