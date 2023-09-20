#include "mu_test.h"

#include <string>
#include <SFML/Graphics.hpp>

#include "font.hpp"
#include "text.hpp"

BEGIN_TEST(text_string_ok_and_draw)
    using namespace arkanoid;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    Font font("../static/Alkatra-Regular.ttf");
    Text text("GAME OVER", font, sf::Vector2f(window.getSize().x / 4.0f, window.getSize().y / 3.0f), 120, sf::Color::Red);

    ASSERT_EQUAL(text.getString(), "GAME OVER");

    window.clear();
    text.draw(window);
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
	TEST(text_string_ok_and_draw)
END_SUITE
