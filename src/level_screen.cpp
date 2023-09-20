#include <fstream>
#include <jsoncpp/json/json.h>
#include "level_screen.hpp"

namespace arkanoid {
std::unordered_map<std::string, Brick::Color> colorMap {
    {"red", Brick::Color::RED},
    {"green", Brick::Color::GREEN},
    {"blue", Brick::Color::BLUE},
    {"yellow", Brick::Color::YELLOW},
    {"orange", Brick::Color::ORANGE},
    {"peach", Brick::Color::PEACH},
    {"cyan", Brick::Color::CYAN},
    {"white", Brick::Color::WHITE},
    {"gray", Brick::Color::GRAY},
    {"pink", Brick::Color::PINK}
};

LevelScreen::LevelScreen(sf::Vector2f a_size, sf::RenderWindow& a_window, const std::string& a_levelFile)
: m_window(a_window)
, m_board(a_size)
, m_bricks()
, m_ball(2, 2, 15.f, sf::Vector2f(670, 650))
, m_player(15,sf::Vector2f(125, 20), sf::Vector2f(635, 690)) 
, m_font("../static/Alkatra-Regular.ttf")
, m_gameOverText("GAME OVER", m_font, sf::Vector2f(m_window.getSize().x / 4.0f, m_window.getSize().y / 3.0f), 120, sf::Color::Red)
, m_winText("YOU WON", m_font, sf::Vector2f(m_window.getSize().x / 4.0f, m_window.getSize().y / 3.0f), 120, sf::Color::Green)
, m_level()
, m_isWin(false)
, m_audioFile()
{
    readFromJson(a_levelFile);
}

std::optional<std::tuple<bool, size_t, double, std::string>> LevelScreen::run()
{
	bool start = false;
    bool exit = false;
    Audio audio(m_audioFile);
    audio.play();
    while (m_window.isOpen()) {
        handleEvents(start, exit);
        if (start) {
            moveTheBall();
        }
        if (m_player.getLives() <= 0) {
            gameOver(start, exit, false);
            return std::make_tuple(false, 0, 0, std::to_string(m_level));
        }
        if (exit) {
            return std::make_tuple(false, 0, 0, std::to_string(m_level));
        }
        drawScreen(); 
        if (m_player.getLives() > 0 && isWin() == true) {
            gameOver(start, exit, true);
            return getSummary();
        }
    }
    return getSummary();
}

void LevelScreen::resetLevel(std::string const& a_levelFile)
{
    readFromJson(a_levelFile);
    m_ball.setPos(m_ball.getInitPos().x, m_ball.getInitPos().y);
    m_player.setPaddlePos(m_player.getInitPos().x, m_player.getInitPos().y);
    m_player.resetPoints();
    m_player.resetLives();
}

void LevelScreen::readFromJson(const std::string& a_levelFile) 
{
    if (!m_bricks.empty()) {
        for (size_t i = 0; i < m_bricks.size(); ++i) {
            m_bricks.erase(m_bricks.begin() + i);
        }
    }
    
    std::ifstream file(a_levelFile);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }
    Json::Value json;
    file >> json;
    m_audioFile = json["sound"].asString();

    sf::Vector2f brickSize = sf::Vector2f(json["brickSize"][0].asFloat(), json["brickSize"][1].asFloat());
    const size_t bricksInLine = json["numBricksInLine"].asUInt();
    m_level = json["level"].asUInt();
    float startX = (m_window.getSize().x - (bricksInLine * brickSize.x + (bricksInLine - 1) * 10.f)) / 2.f;
 
    for (auto const& brick : json["bricks"]) {
        float x = brick["x"].asFloat();
        float y = brick["y"].asFloat();
        sf::Vector2f position = sf::Vector2f(startX + y * (brickSize.x + 10.f), 50.f + x * (brickSize.y + 10.f));
        std::string colorString = brick["color"].asString();
        if (colorMap.find(colorString) == colorMap.end()) {
            throw std::runtime_error("Invalid brick color");
        }
        Brick::Color color = colorMap[colorString];
        m_bricks.emplace_back(position, color, brickSize, m_level);
    }
}

bool LevelScreen::isWin() noexcept
{
    for (auto& brick : m_bricks) {
        if (brick.getIsdestructuble()) {
            return false;
        }
    }
    m_isWin = true;
    return true;
}

void LevelScreen::handleEvents(bool& a_start, bool& a_exit)
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            m_player.stopTheTimer();
            a_exit = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_player.getPaddlePos().x > 20) {
            m_player.movePaddle(-10, 0);
            if (!a_start) {
                m_ball.setPos(m_ball.getPos().x - 10, m_ball.getPos().y);
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_player.getPaddlePos().x < 1110) {
            m_player.movePaddle(10, 0);
            if (!a_start) {
                m_ball.setPos(m_ball.getPos().x + 10, m_ball.getPos().y);
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            m_player.startTheTimer();
            a_start = true;
        }
    }
}

void LevelScreen::drawScreen()
{
    sf::Text text;
    text.setFont(m_font.get());
    text.setString("SCORE: " + std::to_string(m_player.getScore()) + "   LIVES: " + std::to_string(m_player.getLives()) + "   TIME: " + std::to_string(m_player.getTimeTillNow()).substr(0, 5) + "    LEVEL: "+ std::to_string(m_level));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    
    m_window.clear();
    m_window.draw(m_board.getBoard());
    m_player.draw(m_window);
    m_ball.draw(m_window);
    m_window.draw(text);
    for (size_t i = 0; i < m_bricks.size(); ++i) {
        m_bricks[i].draw(m_window);
    }
    m_window.display();
}

void LevelScreen::moveTheBall() 
{
    m_ball.setPos(m_ball.getPos().x + m_ball.getXVal(), m_ball.getPos().y + m_ball.getYVal());
    sf::Vector2f ballPosition = m_ball.getPos();

    if(ballPosition.x < 0 || ballPosition.x > m_window.getSize().x - 50) {
        m_ball.setXVal(m_ball.getXVal() * -1);
    }
    if(ballPosition.y < 0 || m_player.getPaddleBounding().intersects(m_ball.getBounding())) {
        m_ball.setYVal(m_ball.getYVal() * -1);
    }
    if(ballPosition.y > m_window.getSize().y - 50) {
        m_player.setLives();
        m_ball.setYVal(m_ball.getYVal() * -1);
    }
     for (size_t i = 0; i < m_bricks.size(); ++i) {
        if (m_bricks[i].getBounding().intersects(m_ball.getBounding())) {
            handleBrickHitting(m_bricks[i], i);
            m_ball.setYVal(m_ball.getYVal() * -1);
            break;
        }
    }
}

void LevelScreen::handleBrickHitting(Brick a_brick, size_t a_index)
{
    m_player.addPoints(a_brick.getPoints());
    if (a_brick.getIsdestructuble() == true) {
        m_bricks.erase(m_bricks.begin() + a_index);
    }
}

void LevelScreen::gameOver(bool& a_start, bool& a_exit, bool a_win)
{
    a_start = false;
    a_exit = true;
    m_player.stopTheTimer();
    if (a_win) {
       m_winText.draw(m_window); 
    }
    else {
        m_gameOverText.draw(m_window);
    }
    m_window.display();
    sf::sleep(sf::seconds(2));
}

size_t LevelScreen::getTotalScore() const noexcept
{
   return m_player.getScore();
}

std::tuple<bool, size_t, double, std::string> LevelScreen::getSummary() {
    bool won = m_isWin;
    size_t score = m_player.getScore();
    double time = m_player.getTotalTime();
    return std::make_tuple(won, score, time, std::to_string(m_level));
}


} //arkanoid