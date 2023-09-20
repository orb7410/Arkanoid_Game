#include "mu_test.h"

#include <string>
#include <SFML/Graphics.hpp>

#include "top_10_screen.hpp"

// BEGIN_TEST(top_10_screen_check_if_in_top10)
// using namespace arkanoid;
// 	Top10Screen screen{sf::Vector2f(1270, 710)};
// 	Winner w1("yael", 5000, 69);
// 	Winner w2("tom", 6000, 69);
// 	screen.loadTop10ToFile();
// 	ASSERT_EQUAL(screen.checkIfTop10(w1), false);
// 	ASSERT_EQUAL(screen.checkIfTop10(w2), true);
// END_TEST

// BEGIN_TEST(top_10_screen_add_to_top10)
// using namespace arkanoid;
// 	Top10Screen screen{sf::Vector2f(1270, 710)};
// 	Winner w1("yael", 200, 69);
// 	Winner w2("tom", 600, 69);
// 	screen.addToTop10(w1);
// 	//screen.addToTop10(w2);
// 	ASSERT_EQUAL(checkIfVectorContains(screen.getTop10(), w1), false);
// 	ASSERT_EQUAL(checkIfVectorContains(screen.getTop10(), w2), true);
// END_TEST

BEGIN_TEST(top10_screen_enter_string)
    using namespace arkanoid;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    Top10Screen screen{sf::Vector2f(1270, 710), window};

    screen.run();
END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(top10_screen_enter_string)
END_SUITE
