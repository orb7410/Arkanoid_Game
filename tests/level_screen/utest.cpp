#include "mu_test.h"

#include <string>
#include <SFML/Graphics.hpp>

#include "level_screen.hpp"


BEGIN_TEST(level_screen)
    using namespace arkanoid;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    LevelScreen screen{sf::Vector2f(1270, 710), window, "../static/level-1.json"};
    while (window.isOpen()) {
        sf::Event event;
        screen.run();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            }  
        }
        screen.resetLevel("../static/level-1.json");
    }
    ASSERT_PASS();
END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(level_screen)
END_SUITE
