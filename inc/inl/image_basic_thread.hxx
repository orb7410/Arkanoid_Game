#include "image_basic_thread.hpp"


namespace advcpp {

template<typename F>
void changePixelFilter(sf::Image& a_image, uint64_t a_number_ofthreads, F a_func)
{
    sf::Vector2u size = a_image.getSize();
    size_t segment = size.y / a_number_ofthreads;

    std::vector<std::thread> tasks;

    auto f = [&a_image, a_func](size_t start, size_t end){
        changePixel(a_image, start, end, a_func);
    };

    auto start = 0;
    while(a_number_ofthreads-- > 1) {
        size_t end = start + segment;
        tasks.emplace_back(f, start, end);
        start = end;
    };

    // last segment on me!
	f(start, size.y);
    joinAll(tasks);
}

template<typename Iterator, typename F>
void changePixel(sf::Image& a_image, Iterator a_start, Iterator a_end, F a_func)
{
    sf::Vector2u size = a_image.getSize();
    auto line = size.x;

    for (size_t y = a_start; y < a_end; ++y) {
        for (size_t x = 0; x < line; ++x) {
            sf::Color color = a_image.getPixel(x, y);
            sf::Color newColor = a_func(color);
            a_image.setPixel(x, y, newColor);
        }
    }
}

template<typename UnaryFunc>
sf::Image applyFilter(sf::Image const& a_image, uint64_t a_number_ofthreads, UnaryFunc a_func, std::vector<float> const& a_kernel)
{
    if (a_number_ofthreads > a_image.getSize().y) {
        a_number_ofthreads = a_image.getSize().y;
    }

    if (a_kernel.size() % 2 == 0) { // Kernel size must be odd
        return a_image;
    }
    sf::Vector2u size = a_image.getSize();
    sf::Image filteredImg;
    filteredImg.create(size.x, size.y);

    size_t segment = size.y / a_number_ofthreads;

    std::vector<std::thread> tasks;
    auto f = [&a_image, &filteredImg ,a_func, &a_kernel](size_t start, size_t end){
        filterPixel(a_image, filteredImg, start, end, a_func, a_kernel);
    };

    auto start = 0;
    while(a_number_ofthreads-- > 1) {
        size_t end = start + segment;
        tasks.emplace_back(f, start, end);
        start = end;
    }

    // last segment on me!
    f(start, size.y);

    joinAll(tasks);

    return filteredImg;
}

template<typename Iterator, typename UnaryFunc>
void filterPixel(sf::Image const& a_inputImage, sf::Image& a_outputImage, Iterator a_start, Iterator a_end, UnaryFunc a_func, std::vector<float> const& a_kernel)
{
    sf::Vector2u size = a_inputImage.getSize();
    auto line = size.x;

    for (size_t y = a_start; y < a_end; ++y) {
        for (size_t x = 0; x < line; ++x) {
            a_outputImage.setPixel(x, y, a_func(a_inputImage, x, y, a_kernel));
        }
    }
}
} // namespace advcp



