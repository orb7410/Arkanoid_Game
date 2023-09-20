#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <optional>
#include <tuple>
#include <jsoncpp/json/json.h>
#include "game.hpp"
#include "winner.hpp"

namespace arkanoid {

namespace {

void handleEvents(sf::RenderWindow& a_window) {
    sf::Event event;
    while (a_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
           a_window.close();
        }  
    }
}

} //namespace

Game::Game() 
: m_window(sf::VideoMode(1280, 720), "SFML works!")
, m_levelFileName("../static/level-1.json")
, m_openScreen(sf::Vector2f(1270, 710), m_window)
, m_levelScreen(sf::Vector2f(1270, 710), m_window, m_levelFileName)
, m_top10Screen(sf::Vector2f(1270, 710), m_window)
, m_inputScreen(sf::Vector2f(1270, 710), m_window)
, m_level(1)
, m_maxLevel(3) {   
}

void Game::run() 
{
    size_t score = 0;
    double time = 0;
    bool next = true;
    std::string input = "";
    std::optional<std::tuple<bool, size_t, double, std::string>> summary;
    m_openScreen.run();
    while (m_window.isOpen()) {
        handleEvents(m_window);
        if (next == true) {
            while(m_level <= m_maxLevel && true == next) {
                summary = m_levelScreen.run();
                next = std::get<0>(summary.value());
                score += std::get<1>(summary.value());
                time += std::get<2>(summary.value());
                resetLevelScreen(false);
            }
            Winner w(input, score, time);
            if (m_top10Screen.checkIfTop10(w) == true && true == next) {
                summary = m_inputScreen.run();
                input = std::get<3>(summary.value());
                m_top10Screen.addToTop10(Winner(input, score, time));
            }
            
            summary = m_top10Screen.run();
            next = std::get<0>(summary.value());
        }
        if (next == false) {
            summary = m_openScreen.run();
            resetLevelScreen(true);
            next = std::get<0>(summary.value());
        }
    }
}

void Game::resetLevelScreen(bool a_startOver) {
    if(a_startOver) {
       m_level = 0; 
    } 
    ++m_level;
    m_levelScreen.resetLevel("../static/level-" + std::to_string(m_level) + ".json");
}

}//arkanoid
