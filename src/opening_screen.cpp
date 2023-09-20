#include <iostream>
#include "opening_screen.hpp"

namespace arkanoid {
namespace {
sf::RectangleShape createStartButton(sf::Vector2f a_boardSize) 
{
    sf::RectangleShape rectangle(sf::Vector2f(a_boardSize.x * 0.4f, a_boardSize.y * 0.15f));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOrigin(rectangle.getLocalBounds().width / 2, rectangle.getLocalBounds().height / 2);
    rectangle.setPosition(a_boardSize.x / 2, a_boardSize.y / 2 - a_boardSize.y * 0.01f);
    return rectangle; 
}    

sf::RectangleShape createExitButton(sf::Vector2f a_boardSize) 
{
    sf::RectangleShape rectangle(sf::Vector2f(a_boardSize.x * 0.4f, a_boardSize.y * 0.15f));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOrigin(rectangle.getLocalBounds().width / 2, rectangle.getLocalBounds().height / 2);
    rectangle.setPosition(a_boardSize.x / 2, a_boardSize.y / 2 + a_boardSize.y * 0.15f);
    return rectangle; 
}
} //namespace

OpeningScreen::OpeningScreen(sf::Vector2f a_size, sf::RenderWindow& a_window)
: m_window(a_window)
, m_font("../static/Alkatra-Regular.ttf")
, m_board(a_size)
, m_startButton(createStartButton(a_size))
, m_startButtonText("START", m_font.get(), 30)
, m_exitButton(createExitButton(a_size))
, m_exitButtonText("EXIT", m_font.get(), 30)
, m_title("WELCOME TO ARKANOID GAME!", m_font, sf::Vector2f(m_board.getBoard().getPosition().x + m_board.getBoard().getSize().x / 2, m_board.getBoard().getPosition().y + m_board.getBoard().getSize().y / 4), 45, sf::Color::Black)  
{
    m_startButtonText.setFillColor(sf::Color::Black);
    m_startButtonText.setStyle(sf::Text::Bold);
    m_startButtonText.setOrigin(m_startButtonText.getLocalBounds().width / 2, m_startButtonText.getLocalBounds().height / 2);
    m_startButtonText.setPosition(m_startButton.getPosition());
    
    m_exitButtonText.setFillColor(sf::Color::White);
    m_exitButtonText.setStyle(sf::Text::Bold);
    m_exitButtonText.setOrigin(m_startButtonText.getLocalBounds().width / 2, m_startButtonText.getLocalBounds().height / 2);
    m_exitButtonText.setPosition(m_exitButton.getPosition());

    m_title.setOrigin(sf::Vector2f(m_title.get().getLocalBounds().width / 2, m_title.get().getLocalBounds().height / 2));
}

std::optional<std::tuple<bool, size_t, double, std::string>> OpeningScreen::run()
{
	sf::Event event;
    while (m_window.isOpen()) {
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // return a status from this function
                m_window.close();
                return std::make_tuple(false, 0, 0.0, "");
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                        sf::FloatRect startButtonBounds = getStartBounding();
                        sf::FloatRect exitButtonBounds = getExitBounding();
                        
                        if (startButtonBounds.contains(mousePos.x, mousePos.y)) {
                            return std::make_tuple(true, 0, 0.0, "");
                        }
                        else if (exitButtonBounds.contains(mousePos.x, mousePos.y)) {
                            m_window.close();
                            return std::make_tuple(false, 0, 0.0, "");
                        }
                    }
            }
            drawScreen(); 
        }
    }
    return std::make_tuple(true, 0, 0.0, "");
}

void OpeningScreen::drawScreen() 
{
    m_window.clear();
    m_window.draw(m_board.getBoard());
    m_window.draw(m_startButton);
    m_window.draw(m_exitButton);
    m_title.draw(m_window);
    m_window.draw(m_startButtonText);
    m_window.draw(m_exitButtonText);
    m_window.display();
}

sf::FloatRect OpeningScreen::getStartBounding() const noexcept 
{
    return m_startButton.getGlobalBounds();
}

sf::FloatRect OpeningScreen::getExitBounding() const noexcept 
{
    return m_exitButton.getGlobalBounds();
}

} //namespace arkanoid 