#pragma once
#include <tuple>
#include <optional>
#include <SFML/Graphics.hpp>
#include "brick.hpp"
#include "screen.hpp"
#include "board.hpp"
#include "font.hpp"
#include "player.hpp"
#include "ball.hpp"
#include "text.hpp"
#include "audio.hpp"

namespace arkanoid {

class LevelScreen: public Screen {
public:
    LevelScreen() = delete;
    explicit LevelScreen(sf::Vector2f a_size, sf::RenderWindow& a_window, const std::string& a_levelFile);
    LevelScreen(LevelScreen const& a_other) = default;
    LevelScreen& operator=(LevelScreen const& a_other) = default;
    ~LevelScreen() = default;

    std::optional<std::tuple<bool, size_t, double, std::string>> run() override;
    void resetLevel(std::string const& a_levelFile);

private:
    void readFromJson(const std::string& a_levelFile);
    void handleEvents(bool& a_start, bool& a_exit);
    void drawScreen();
    void moveTheBall();
    void gameOver(bool& a_start, bool& a_exit, bool a_win);
    void handleBrickHitting(Brick a_brick, size_t a_index);
    bool isWin() noexcept;
    size_t getTotalScore() const noexcept;
    std::tuple<bool, size_t, double, std::string> getSummary();
    
private:
    sf::RenderWindow& m_window;
    Board m_board;
    std::vector<Brick> m_bricks;
    Ball m_ball;
    Player m_player;
    Font m_font;
    Text m_gameOverText;
    Text m_winText;
    size_t m_level = 1;
    bool m_isWin;
    std::string m_audioFile;
};
} //arkanoid 