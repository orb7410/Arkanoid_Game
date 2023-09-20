#pragma once

#include <vector>
#include <cstdint>
#include <thread>
#include <cmath>
#include <numeric>

namespace advcpp{

template<typename Iterator>
double calcExp(Iterator a_begin, Iterator a_end)
{
    double result = 0.;

    while(a_begin != a_end) {
		auto x = *a_begin;
        double s = 0.0;

		auto sinc = 1;
		if ( x != 0.0 ){
			s = sin(x);
			sinc = s / x;
		}

        result += s*s + sinc;
		++a_begin;
    }

    return result;
}



void join_all(std::vector<std::thread>& a_tasks);

template<typename UnaryFunc>
double parallel_compute(std::vector<double> const& a_vector, uint64_t a_number_ofthreads, UnaryFunc func)
{
	std::vector<std::thread> tasks;
	tasks.reserve(a_number_ofthreads - 1);

	std::vector<double> partial_results(a_number_ofthreads*16);
	auto f = [&partial_results, func](auto begin, auto end, auto i){
		double result = 0.;
		while(begin != end) {
			auto x = *begin;
			result += func(x);
			++begin;
		}
		partial_results[i] = result;
	};

	auto segment = a_vector.size() / a_number_ofthreads;
	auto start = a_vector.begin();

	auto i = 0;
    while(a_number_ofthreads-- > 1) {
		auto end = start + segment;
		auto slot = i++ * 16;
		tasks.emplace_back(f, start, end, slot);
		start = end;
    }
	// last segment on me!
	f(start, a_vector.end(), i*16);
    join_all(tasks);

    return std::accumulate(partial_results.begin(), partial_results.end(), 0.0);
}


double calcExp(std::vector<double> const& a_vec);

double multyThreadCalcExp(const std::vector<double>& a_vec, uint64_t a_threads = 2);

} //advcpp
