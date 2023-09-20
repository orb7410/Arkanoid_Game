#pragma once
#include <thread>
#include <vector>
#include <SFML/Graphics.hpp>

namespace advcpp {
    
void joinAll(std::vector<std::thread>& a_tasks);

template<typename F>
void changePixelFilter(sf::Image& a_image, uint64_t a_number_ofthreads, F a_func);

template<typename Iterator, typename F>
void changePixel(sf::Image& a_image, Iterator a_start, Iterator a_end, F a_func);

sf::Color gaussianBlur(sf::Color const& a_color);

template<typename UnaryFunc>
sf::Image applyFilter(sf::Image const& a_image, uint64_t a_number_ofthreads, UnaryFunc a_func, std::vector<float> const& a_kernel);

template<typename Iterator, typename UnaryFunc>
void filterPixel(sf::Image const& a_inputImage, sf::Image& a_outputImage, Iterator a_start, Iterator a_end, UnaryFunc a_func, std::vector<float> const& a_kernel);

sf::Color gaussianBlur(sf::Image const& a_image, unsigned int a_x, unsigned int a_y, std::vector<float> const& a_kernel);

sf::Color sharpen(sf::Image const& a_image, unsigned int a_x, unsigned int a_y, std::vector<float> const& a_kernel);
} // namespace advcpp
#include "inl/image_basic_thread.hxx"
