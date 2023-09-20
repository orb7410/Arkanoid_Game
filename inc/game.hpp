#pragma once
#include <SFML/Graphics.hpp>
#include "opening_screen.hpp"
#include "top_10_screen.hpp"
#include "input_screen.hpp"
#include "level_screen.hpp"
#include <string>

namespace arkanoid {
    
class Game {
public:
    Game();
    Game(Game const& a_other) = delete;
    Game& operator=(Game const& a_other) = delete;
    ~Game() = default;

    void run();

private:
    void resetLevelScreen(bool a_startOver);

private:    
    sf::RenderWindow m_window;
    std::string m_levelFileName;
    OpeningScreen m_openScreen;
    LevelScreen m_levelScreen;
    Top10Screen m_top10Screen;
    InputScreen m_inputScreen;
    size_t m_level;
    size_t m_maxLevel;
};

} //arkanoid
