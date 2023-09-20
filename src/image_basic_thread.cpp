#include <cmath>
#include <numeric>
#include "image_basic_thread.hpp"

namespace advcpp {

void joinAll(std::vector<std::thread>& a_tasks)
{
	for(auto& t : a_tasks) {
		t.join();
	}
} 

sf::Color gaussianBlur(sf::Image const& a_image, unsigned int a_x, unsigned int a_y, std::vector<float> const& a_kernel)
{
    auto kernelSize = a_kernel.size();
    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
    float kernelSum = 0.0f;

    unsigned int kernelIndex = 0;
    unsigned int sq = std::sqrt(kernelSize);
    unsigned int offset = (sq - 1) / 2;

    for (unsigned int i = 0; i < sq; ++i) {
        for (unsigned int j = 0; j < sq; ++j) {
        int x = a_x + i - offset;
        int y = a_y + j - offset;
        
            if (x >= 0 && x < static_cast<int>(a_image.getSize().x) &&
                y >= 0 && y < static_cast<int>(a_image.getSize().y)) {
                sf::Color color = a_image.getPixel(x, y);
                float kernelValue = a_kernel[kernelIndex];
                r += color.r * kernelValue;
                g += color.g * kernelValue;
                b += color.b * kernelValue;
                kernelSum += kernelValue;
            }
            ++kernelIndex;
        }
    }

    if (kernelSum != 0.0f) {
        r /= kernelSum;
        g /= kernelSum;
        b /= kernelSum;
    }

    return sf::Color(static_cast<sf::Uint8>(r), static_cast<sf::Uint8>(g), static_cast<sf::Uint8>(b));
}

sf::Color sharpen(sf::Image const& a_image, unsigned int a_x, unsigned int a_y, std::vector<float> const& a_kernel)
{
    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
    float kernelSum = 0.0f;

    int kernelIndex = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int x = a_x + i;
            int y = a_y + j;

            if (x >= 0 && x < static_cast<int>(a_image.getSize().x) &&
                y >= 0 && y < static_cast<int>(a_image.getSize().y)) {
                sf::Color color = a_image.getPixel(x, y);
                float kernelValue = a_kernel[kernelIndex];
                r += color.r * kernelValue;
                g += color.g * kernelValue;
                b += color.b * kernelValue;
                kernelSum += kernelValue;
            }
            ++kernelIndex;
        }
    }

    if (kernelSum != 0.0f) {
        r /= kernelSum;
        g /= kernelSum;
        b /= kernelSum;
    }
    //color values within the range of 0-255
    r = std::min(255.f, std::max(0.f, r));
    g = std::min(255.f, std::max(0.f, g));
    b = std::min(255.f, std::max(0.f, b));

    return sf::Color(static_cast<sf::Uint8>(r), static_cast<sf::Uint8>(g), static_cast<sf::Uint8>(b));
}
}//advcpp
