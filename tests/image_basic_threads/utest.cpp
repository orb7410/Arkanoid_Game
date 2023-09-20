#include "mu_test.h"

#include <vector>
#include <iostream>
#include <cassert>
#include <iterator>
#include <functional>

#include <SFML/Graphics.hpp>

#include "image_basic_thread.hpp"

void test(const char* input, const char* out, unsigned int n, std::function<sf::Color(sf::Color&)> filter)
{
	sf::Image image;
    if (!image.loadFromFile(input)) {
        std::cerr << "failed to load image";
    }
    advcpp::changePixelFilter(image, n, filter);

    if (!image.saveToFile(out)) {
        std::cerr << "failed to save image";
    }
}


BEGIN_TEST(prep_load_image)
	sf::Image image;
    if (!image.loadFromFile("img/tiger.jpeg")) {
        ASSERT_FAIL("failed to load");
    }else{
		ASSERT_PASS();
	}
END_TEST

BEGIN_TEST(chage_to_gray_scale)
test("img/tiger.jpeg", "tiger_gray.jpg", 2, [](sf::Color& pixel){
		float ave = ( pixel.r +  pixel.g +  pixel.b)/3;
        sf::Color color;
        color.r = ave;
        color.g = ave;
        color.b = ave;
        return color;
	});
    ASSERT_PASS();
END_TEST


BEGIN_TEST(reduce_blue_8)
   test("img/tiger.jpeg", "tiger_reduce_blue8.jpg", 8, [](sf::Color& pixel) -> sf::Color {
    return sf::Color(pixel.g, pixel.b, pixel.b/2);
    });

    ASSERT_PASS();
END_TEST

BEGIN_TEST(reduce_blue_2)
   test("img/tiger.jpeg", "tiger_reduce_blue2.jpg", 2, [](sf::Color& pixel) -> sf::Color {
    return sf::Color(pixel.g, pixel.b, pixel.b/2);
    });

    ASSERT_PASS();
END_TEST

BEGIN_TEST(reduce_blue_16)
   test("img/tiger.jpeg", "tiger_reduce_blue2.jpg", 16,[](sf::Color& pixel) -> sf::Color {
    return sf::Color(pixel.g, pixel.b, pixel.b/2);
    });


    ASSERT_PASS();
END_TEST

BEGIN_TEST(reduce_clor)
test("img/tiger.jpeg", "tiger_reduce_color.jpg", 2, [](sf::Color& pixel){
		sf::Color color;
        color.r = pixel.r / 2;
        color.g = pixel.g / 2;
        color.b = pixel.b / 2;
        return color;
	});
    ASSERT_PASS();
END_TEST

TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(prep_load_image)
    TEST(chage_to_gray_scale)
    TEST(reduce_blue_2)
	TEST(reduce_blue_8)
	TEST(reduce_blue_16)
    TEST(reduce_clor)
END_SUITE
