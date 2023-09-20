#pragma once
#include <SFML/Graphics.hpp>

namespace arkanoid {
    
class Board {
public:
    Board() = delete;
    explicit Board(sf::Vector2f a_size);
    Board(Board const& a_other) = delete;
    Board& operator=(Board const& a_other) = delete;
    ~Board() = default;

    sf::RectangleShape const& getBoard() const;
    sf::FloatRect getBounding() const noexcept;
    
private:
    sf::RectangleShape m_board;
};

} //arkanoid
