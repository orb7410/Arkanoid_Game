#include <thread>
#include <cmath>
#include <numeric>

#include "basic_threads.hpp"

namespace advcpp{

double calcExp(std::vector<double> const& a_vec)
{
    return calcExp(a_vec.begin(), a_vec.end());
}

void join_all(std::vector<std::thread>& a_tasks)
{
	for(auto& t : a_tasks){
		t.join();
	}
}

double multyThreadCalcExp(std::vector<double> const& a_vector, uint64_t a_number_ofthreads)
{
	std::vector<std::thread> tasks;
	tasks.reserve(a_number_ofthreads - 1);

	std::vector<double> partial_results(a_number_ofthreads*16);
	auto f = [&partial_results](auto begin, auto end, auto i){
		partial_results[i] = calcExp(begin, end);
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

}//advcpp
