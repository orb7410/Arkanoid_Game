#include "mu_test.h"


#include <thread>
#include <climits>

#include "timer.hpp"
#include "player.hpp"

BEGIN_TEST(timer_get_total_time)
    using namespace arkanoid;
    Player p(15, sf::Vector2f(125, 20), sf::Vector2f(635, 690));
    p.startTheTimer();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    p.stopTheTimer();
    double elapsed_time = p.getTotalTime();
    ASSERT_THAT(elapsed_time >= 5);
END_TEST

TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(timer_get_total_time)
END_SUITE
