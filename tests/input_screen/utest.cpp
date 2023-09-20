#include "mu_test.h"
#include <tuple>
#include <optional>
#include <string>
#include <SFML/Graphics.hpp>

#include "input_screen.hpp"


BEGIN_TEST(input_screen_enter_string)
    using namespace arkanoid;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    InputScreen screen{sf::Vector2f(1270, 710), window};

    std::optional<std::tuple<bool, size_t, double, std::string>> summary = screen.run();
    std::string input = std::get<3>(summary.value());
    ASSERT_EQUAL(input, "or");
END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(input_screen_enter_string)
END_SUITE
