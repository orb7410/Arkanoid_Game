#include "mu_test.h"

#include <SFML/Graphics.hpp>

#include "opening_screen.hpp"


BEGIN_TEST(OpeningScreen_run)
    using namespace arkanoid;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    OpeningScreen screen{sf::Vector2f(1270, 710), window};

    screen.run();
END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(OpeningScreen_run)
END_SUITE
