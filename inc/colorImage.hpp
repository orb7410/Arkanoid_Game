#ifndef COLORIMAGE_H_
#define COLORIMAGE_H_
#include <iostream>
#include <fstream>
#include <ostream>
#include "matrix.hpp"
#include "color.hpp"

namespace advcpp{
class ColorImage {
public:
    explicit ColorImage(unsigned int a_rows, unsigned int a_columns, unsigned int a_saturation = 255);
    
    ColorImage(const ColorImage& a_other);
    ColorImage& operator=(const ColorImage& a_other);
    ~ColorImage() = default;

    ColorRGB& ReadColor(unsigned int a_rows, unsigned int a_columns);
    ColorRGB const& ReadColor(unsigned int a_rows, unsigned int a_columns) const;
    void WriteColor(unsigned int a_rows, unsigned int a_columns, const ColorRGB& a_color);
    void Clear(ColorRGB const& backgroundColor = ColorRGB(255,255,255));
    
    //void ReducedColor(unsigned int a_factor);
    //void ScaleDown(unsigned int a_factor);
    unsigned int Width() const ;
    unsigned int Height() const ;
    unsigned int Saturation() const;

private:
    unsigned int m_saturation;
    Matrix<ColorRGB> m_imageMatrix;

};

    ColorImage LoadImageFromFile(const std::string& a_filename);
    void SaveImageToFile(const std::string& a_filename, ColorImage const& a_image);

}/* advcpp*/

#endif/*COLORIMAGE_H_*/