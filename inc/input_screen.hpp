#pragma once
#include <tuple>
#include <optional>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "board.hpp"
#include "screen.hpp"
#include "font.hpp"
#include "text.hpp"

namespace arkanoid {

class InputScreen : public Screen{
public:
    InputScreen() = delete;
    explicit InputScreen(sf::Vector2f a_size, sf::RenderWindow& a_window);
    InputScreen(InputScreen const& a_other) = delete;
    InputScreen& operator=(InputScreen const& a_other) = delete;
    ~InputScreen() = default;

	std::optional<std::tuple<bool, size_t, double, std::string>> run() override;

    std::string const& getInput() const noexcept;
private:
	bool drawScreen();

private:
	sf::RenderWindow& m_window;
	Font m_font;
	Board m_board;
	sf::Text m_text;
    std::string m_input;
    Text m_title;
    sf::RectangleShape m_textBox;
};

} //arkanoid
