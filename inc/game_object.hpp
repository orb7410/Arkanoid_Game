#pragma once
#include <SFML/Graphics.hpp>

namespace arkanoid {

class GameObject {
public:
    virtual ~GameObject() = default;

    virtual sf::FloatRect getBounding() const noexcept = 0;
    virtual void draw(sf::RenderTarget& a_target) const noexcept = 0;
};

} // arkanoid
