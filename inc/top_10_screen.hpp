#pragma once
#include <SFML/Graphics.hpp>
#include <tuple>
#include <optional>
#include <iostream>
#include <string>
#include "board.hpp"
#include "screen.hpp"
#include "winner.hpp"
#include "font.hpp"
#include "text.hpp"

namespace arkanoid {
    
class Top10Screen : public Screen{
public:
    Top10Screen() = delete;
    explicit Top10Screen(sf::Vector2f a_size, sf::RenderWindow& a_window);
    Top10Screen(Top10Screen const& a_other) = delete;
    Top10Screen& operator=(Top10Screen const& a_other) = delete;
    ~Top10Screen() = default;

    std::optional<std::tuple<bool, size_t, double, std::string>> run() override;
    std::vector<Winner> const& getTop10() noexcept;
    void loadTop10ToFile() const noexcept;
    bool checkIfTop10(Winner a_winner) const noexcept;
    void addToTop10(Winner a_winner) noexcept; 
    
private:
    void drawScreen();
    void drawTexts(sf::Vector2f a_top10Pos);

private:
    sf::RenderWindow& m_window;
    Board m_board;
    Font m_font;
    std::string m_fileName;
    std::vector<Winner> m_top10;
    Text m_title;   
};

} //arkanoid
