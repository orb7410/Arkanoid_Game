#include "board.hpp"
#include <SFML/Graphics.hpp>

namespace arkanoid {

namespace {
sf::RectangleShape initBoard(sf::Vector2f a_size) 
{
    sf::RectangleShape rectangl(a_size);
    rectangl.setFillColor(sf::Color(204, 255, 255));
    rectangl.setOutlineThickness(10.f);
    rectangl.setOutlineColor(sf::Color(0, 204, 153));
    rectangl.setPosition(5.f, 5.f);
    return rectangl; 
}   
} //namespace 

Board::Board(sf::Vector2f a_size) 
: m_board(initBoard(a_size))
{   
}

sf::RectangleShape const& Board::getBoard() const
{
    return m_board;
}

sf::FloatRect Board::getBounding() const noexcept 
{
    return m_board.getGlobalBounds();
}

} //arkanoid

