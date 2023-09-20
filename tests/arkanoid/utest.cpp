#include "mu_test.h"

#include <thread>
#include <iostream>
#include <cstddef>
#include <climits>
#include "game.hpp"
#include "opening_screen.hpp"
#include "top_10_screen.hpp"
#include "input_screen.hpp"
#include "level_screen.hpp"

BEGIN_TEST(run)
using namespace arkanoid;
	Game game{};
	game.run();
	ASSERT_PASS();
END_TEST

TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(run)
END_SUITE

//done the music of level in milston 4 no sounds in hitting