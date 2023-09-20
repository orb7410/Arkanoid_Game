#include "mu_test.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <cstddef>
#include <climits>
#include <cassert>
#include "matrix.hpp"
#include "color.hpp"
#include "colorImage.hpp"
#include "draw_primitives.hpp"
#include "point.hpp"
BEGIN_TEST(LoadSave)
	advcpp::ColorImage newImage = advcpp::LoadImageFromFile("cat.ppm");
	advcpp::SaveImageToFile("mycat.ppm", newImage);
	//newImage.Clear();
	advcpp::DrawHorizontalLine(newImage, 50,250, 100, advcpp::ColorRGB{0, 0, 0});
	advcpp::DrawVerticalLine(newImage, 50, 250, 100, advcpp::ColorRGB{0, 0, 0});
	advcpp::DrawLine(newImage, advcpp::ColorRGB{0, 0, 0}, advcpp::Point{ 50, 200}, advcpp::Point{ 250, 250});
	advcpp::DrawCircle(newImage, 300, 300, 250, advcpp::ColorRGB{0, 0, 0});
	advcpp::SaveImageToFile("mycat.ppm", newImage);

END_TEST



BEGIN_TEST(createImage)
	advcpp::ColorImage newImage{10,10};

	ASSERT_EQUAL(newImage.Height(), 10);
	ASSERT_EQUAL(newImage.Width(), 10);
	ASSERT_EQUAL(newImage.Saturation(), 255);

	unsigned int rows = newImage.Height();
	unsigned int columns = newImage.Width();

	for (unsigned int i = 0; i < rows; ++i){
		for (unsigned int j = 0; j < columns; ++j){
            ASSERT_EQUAL(newImage.ReadColor(i,j).m_red, 255);
        }
    }
END_TEST

BEGIN_TEST(CopyImage)
	advcpp::ColorImage newImage1{10,10};
	advcpp::ColorImage newImage2 = newImage1;

	ASSERT_EQUAL(newImage2.Height(), 10);
	ASSERT_EQUAL(newImage2.Width(), 10);
	ASSERT_EQUAL(newImage2.Saturation(), 255);

	unsigned int rows = newImage2.Height();
	unsigned int columns = newImage2.Width();

	for (unsigned int i = 0; i < rows; ++i){
		for (unsigned int j = 0; j < columns; ++j){
            ASSERT_EQUAL(newImage2.ReadColor(i,j).m_red, 255);
        }
    }
END_TEST

BEGIN_TEST(CopyAssiImage)
	advcpp::ColorImage newImage1{10,10};
	advcpp::ColorImage newImage2 {5,5};

	ASSERT_EQUAL(newImage2.Height(), 5);
	ASSERT_EQUAL(newImage2.Width(), 5);

	newImage2 = newImage1;
	ASSERT_EQUAL(newImage2.Height(), 10);
	ASSERT_EQUAL(newImage2.Width(), 10);
	ASSERT_EQUAL(newImage2.Saturation(), 255);

	unsigned int rows = newImage2.Height();
	unsigned int columns = newImage2.Width();

	for (unsigned int i = 0; i < rows; ++i){
		for (unsigned int j = 0; j < columns; ++j){
            ASSERT_EQUAL(newImage2.ReadColor(i,j).m_red, 255);
        }
    }
END_TEST

BEGIN_TEST(ReadWriteImage)
	advcpp::ColorImage newImage{10,10,250};

	unsigned int rows = newImage.Height();
	unsigned int columns = newImage.Width();

	for (unsigned int i = 0; i < rows; ++i){
		for (unsigned int j = 0; j < columns; ++j){
			newImage.WriteColor(i, j,advcpp::ColorRGB{i+j, i+j, i+j});
			ASSERT_EQUAL(newImage.ReadColor(i,j).m_blue, i+j);
			ASSERT_EQUAL(newImage.ReadColor(i,j).m_green, i+j);
			ASSERT_EQUAL(newImage.ReadColor(i,j).m_red, i+j);
		}
	}
END_TEST


BEGIN_TEST(clearImage)
	advcpp::ColorImage newImage{10,10,250};
	newImage.Clear(advcpp::ColorRGB{0, 0, 0});

	unsigned int rows = newImage.Height();
	unsigned int columns = newImage.Width();

	for (unsigned int i = 0; i < rows; ++i){
		for (unsigned int j = 0; j < columns; ++j){
			ASSERT_EQUAL(newImage.ReadColor(i,j).m_red, 0);
			ASSERT_EQUAL(newImage.ReadColor(i,j).m_green, 0);
			ASSERT_EQUAL(newImage.ReadColor(i,j).m_blue, 0);
		}
	}
END_TEST





TEST_SUITE(因果応報 [inga ōhō: bad causes bring bad results])
	TEST(createImage)
	TEST(CopyImage)
	TEST(CopyAssiImage)
	TEST(ReadWriteImage)
	TEST(clearImage)
	TEST(LoadSave)
END_SUITE
