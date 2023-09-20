#include "mu_test.h"

#include <string>
#include <SFML/Graphics.hpp>

#include "brick.hpp"


BEGIN_TEST(brick)
    using namespace arkanoid;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    Brick grayBrick(sf::Vector2f(100, 100), Brick::GRAY, sf::Vector2f(50, 20), 3);
    Brick yellowBrick(sf::Vector2f(100, 100), Brick::YELLOW, sf::Vector2f(50, 20), 3);
    ASSERT_EQUAL(grayBrick.getPoints(), 150);
    ASSERT_EQUAL(grayBrick.getIsdestructuble(), true);
    ASSERT_EQUAL(yellowBrick.getIsdestructuble(), false);

    window.clear();
    grayBrick.draw(window);
    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(brick)
END_SUITE
