#include <iostream>
#include "colorImage.hpp"
#include "matrix.hpp"
#include "color.hpp"


namespace advcpp{
ColorImage::ColorImage(unsigned int a_rows, unsigned int a_columns, unsigned int a_saturation)
: m_saturation(a_saturation)
, m_imageMatrix(Matrix<ColorRGB>(a_rows, a_columns))
{}

ColorImage::ColorImage(const ColorImage& a_other)
: m_saturation(a_other.m_saturation)
, m_imageMatrix(a_other.m_imageMatrix)
{}


ColorImage& ColorImage::operator=( ColorImage const& a_other) {
    if (this != &a_other) {
        m_saturation = a_other.m_saturation;
        m_imageMatrix = a_other.m_imageMatrix;
    }
    return *this;
}

ColorRGB& ColorImage::ReadColor(unsigned int a_rows, unsigned int a_columns){
    return m_imageMatrix(a_rows, a_columns);
}


ColorRGB const& ColorImage::ReadColor(unsigned int a_rows, unsigned int a_columns) const{
    return m_imageMatrix(a_rows, a_columns);
}

void ColorImage::WriteColor(unsigned int a_rows, unsigned int a_columns, const ColorRGB& a_color){
    m_imageMatrix(a_rows, a_columns) = a_color;
}

unsigned int ColorImage::Width() const {
    return m_imageMatrix.Columns();
}

unsigned int ColorImage::Height() const {
    return m_imageMatrix.Rows();
}

unsigned int ColorImage::Saturation() const {
    return m_saturation;
}

void ColorImage::Clear(ColorRGB const& backgroundColor){
    for (unsigned int i = 0; i < m_imageMatrix.Rows(); ++i) {
        for (unsigned int j = 0; j < m_imageMatrix.Columns(); ++j) {
	        m_imageMatrix(i,j) = backgroundColor;
        }
    }
}

ColorImage LoadImageFromFile(const std::string& a_filename) {
    std::ifstream file(a_filename);
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    std::string format;
    file >> format;

    unsigned int rows, columns;
    file >> columns >> rows ;

    unsigned int saturation;
    file >> saturation;

    ColorImage image(rows, columns, saturation);

    unsigned int red, green, blue;

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < columns; ++j) {
            file >> red >> green >> blue;
            image.WriteColor(i, j, ColorRGB(red, green, blue));
        }
    }

    file.close();
    return image;
}


void SaveImageToFile(const std::string& a_filename, ColorImage const& a_image){
    std::ofstream file(a_filename);
    file.exceptions(std::ofstream::failbit | std::ofstream::badbit);

    file << "P3" << std::endl;
    file << a_image.Height() << " " << a_image.Width() << std::endl;
    file << a_image.Saturation() << std::endl;

    for (unsigned int r = 0; r < a_image.Height(); ++r) {
        for (unsigned int c = 0; c < a_image.Width(); ++c) {
            file << a_image.ReadColor(r,c).m_red  << " "
                 << a_image.ReadColor(r,c).m_green << " "
                 << a_image.ReadColor(r,c).m_blue << " ";
        }
        file << std::endl;
    }
    file.close();
}


/*


void ColorImage::ReduceRangeByFactor(int a_factor) {
    assert(a_factor >= 0 && a_factor <= 255);
    for(size_t i = 0; i < m_imageMatrix.Rows(); ++i) {
        for(size_t j = 0; j < m_imageMatrix.Columns(); ++j) {
            m_imageMatrix(i,j).m_red = float(m_imageMatrix(i,j).m_red) / m_saturation * a_factor;
            m_imageMatrix(i,j).m_green = float(m_imageMatrix(i,j).m_green) / m_saturation * a_factor;
            m_imageMatrix(i,j).m_blue = float(m_imageMatrix(i,j).m_blue) / m_saturation * a_factor;
        }
    }
    m_saturation = a_factor;
}

void ColorImage::Run(){
    int num;
    unsigned int row, column, startRow, endRow;
    unsigned int red, blue, green;
    Pixel newpixel;
    Pixel RedPixel{8, 8, 8}; // red pixel
    std::string fileName;
    std::cout<<"hello, first we are going to create a white image"<<std::endl;
    row = getRowNumber();
    column = getColumnNumber();
    ColorImage whiteImage("p1", 100, row, column);
    whiteImage.m_imageMatrix.CreateWhiteImage(row, column);
    *this = whiteImage;
    while (true){
        PrintMenu();
        num = getNumber();
        switch (num){
            case 1: 
                this->Print();
                std::cout<<"\n"<<std::endl;
                break;
            case 2:
                fileName = RequestsForFileName();
                this->LoadImageFromFile(fileName);
                break;
            case 3:
                fileName = RequestsForFileName();
                this->SaveImageToFile(fileName);
                break;
            case 4:
                row = getRowNumber();
                column = getColumnNumber();
                newpixel =  this->ImageGetPixel(row, column);
                red = newpixel.GetRed();
                green = newpixel.GetGreen();
                blue = newpixel.GetBlue();
                printPixel(red, green, blue);
                break;
            case 5:
                row = getRowNumber();
                column = getColumnNumber();
                this-> ImageSetPixel(row, column, RedPixel);
                newpixel =  this->ImageGetPixel(row, column);
                red = newpixel.GetRed();
                green = newpixel.GetGreen();
                blue = newpixel.GetBlue();
                printPixel(red, green, blue);
                break;
            case 6:
                column = getColumnNumber();
                startRow = getstartRowNumber();
                endRow = getendRowNumber();
                DrawVerticalLine(column, startRow, endRow, RedPixel);
                break;
            case 0:
                return;
        }
    }

}*/

}/*advcpp*/