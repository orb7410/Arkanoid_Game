#include "mu_test.h"

#include <vector>
#include <iostream>
#include <cassert>
#include <iterator>
#include <random>

#include "basic_threads.hpp"

void initRandVec(std::vector<double>& a_vec,size_t a_size)
{
    for (size_t i=0; i < a_size; ++i) {
        double d = static_cast<double>(std::rand() % 101) / 100.0;
        a_vec.push_back(d);
    }
}


std::vector<double> rVec;
// size_t size = 10'000'000;
size_t size = 100'000'000;
//auto v = generateRandom(size);
double expected_result;

double epsilon = 1e-2;

#undef TRACE
#define TRACE(x)

BEGIN_TEST(prep_vector)
    initRandVec(rVec, size);
    ASSERT_PASS();
END_TEST

BEGIN_TEST(calc_mono_thread)
    expected_result = advcpp::calcExp(rVec);
	// test for randmoness?
    ASSERT_PASS();
END_TEST

BEGIN_TEST(calc_mono_thread_iter)
    auto result = advcpp::calcExp(rVec.rbegin(), rVec.rend());
    auto delta = std::abs(expected_result - result);
	TRACE(delta);
    ASSERT_THAT(delta < epsilon);
END_TEST

BEGIN_TEST(calc_threaded_sin_1)
    double result = advcpp::multyThreadCalcExp(rVec, 1);

	auto delta = std::abs(expected_result - result);
	TRACE(delta);
    ASSERT_THAT(delta < epsilon);
END_TEST

BEGIN_TEST(calc_threaded_sin_2)
    double result = advcpp::multyThreadCalcExp(rVec, 2);

	auto delta = std::abs(expected_result - result);
	TRACE(delta);
    ASSERT_THAT(delta < epsilon);
END_TEST

BEGIN_TEST(calc_threaded_sin_4)
    double result = advcpp::multyThreadCalcExp(rVec, 4);

	auto delta = std::abs(expected_result - result);
	TRACE(delta);
    ASSERT_THAT(delta < epsilon);
END_TEST

BEGIN_TEST(calc_threaded_sin_8)
    double result = advcpp::multyThreadCalcExp(rVec, 8);

	auto delta = std::abs(expected_result - result);
	TRACE(delta);
    ASSERT_THAT(delta < epsilon);
END_TEST


BEGIN_TEST(calc_with_generic_function_4)
	auto result = advcpp::parallel_compute(rVec, 4, [](double x){
		double s = 0.0;
		auto sinc = 1;
		if ( x != 0.0 ){
			s = sin(x);
			sinc = s / x;
		}
        return s*s + sinc;
	});

	auto delta = std::abs(expected_result - result);
	TRACE(delta);
    ASSERT_THAT(delta < epsilon);
END_TEST


TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
    TEST(prep_vector)
	TEST(calc_mono_thread)
	TEST(calc_mono_thread_iter)
	TEST(calc_threaded_sin_1)
    TEST(calc_threaded_sin_2)
	TEST(calc_threaded_sin_4)
	TEST(calc_threaded_sin_8)

	TEST(calc_with_generic_function_4)
END_SUITE

