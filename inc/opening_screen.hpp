#pragma once
#include <tuple>
#include <optional>
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "screen.hpp"
#include "font.hpp"
#include "text.hpp"

namespace arkanoid {
    
class OpeningScreen : public Screen{
public:
    OpeningScreen() = delete;
    explicit OpeningScreen(sf::Vector2f a_size, sf::RenderWindow& a_window);
    OpeningScreen(OpeningScreen const& a_other) = delete;
    OpeningScreen& operator=(OpeningScreen const& a_other) = delete;
    ~OpeningScreen() = default;

    std::optional<std::tuple<bool, size_t, double, std::string>> run() override;

private:
    void drawScreen();
    sf::FloatRect getStartBounding() const noexcept;
    sf::FloatRect getExitBounding() const noexcept;
    
private:
    sf::RenderWindow& m_window;
    Font m_font;
    Board m_board;
    sf::RectangleShape m_startButton;
    sf::Text m_startButtonText;
    sf::RectangleShape m_exitButton;
    sf::Text m_exitButtonText;
    Text m_title;
};

} //arkanoid
