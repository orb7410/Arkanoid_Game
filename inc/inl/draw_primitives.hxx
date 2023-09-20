#include "draw primitives"
#include "color.hpp"
#include "point.hpp"

void DrawVerticalLine(ColorImage& a_image, Point a_start, Point a_end, size_t a_column, ColorRGB a_color){
    if (a_startRow > a_endRow) {
        std::cerr << "end row is less than start row "<< std::endl;
    }
    if (a_startRow >= m_hight || a_endRow >= m_hight) {
        std::cerr << "row index out of range "<< std::endl;
    }
    for (unsigned int r = a_startRow; r <= a_endRow; ++r) {
            m_imageMatrix.SetPixel(r, a_column, a_pixel);
    }
}
void DrawHorizontalLine(ColorImage& a_image,Point a_start, Point a_end, size_t a_row, ColorRGB a_color){

}

void DrawLine(ColorImage& a_image, Point a_startPoint, Point a_endPoint, ColorRGB a_color){
    // horizontal line
    if (a_start.m_yAxis == a_end.m_yAxis){
        DrawHorizontalLine(a_image, a_start.m_yAxis, a_end.m_yAxis, a_end.m_xAxis - a_start.m_xAxis + 1, a_color);
    }
    // vertical line
    else if (a_start.m_xAxis == a_end.m_xAxis){
        DrawVerticalLine(a_image, a_start.m_xAxis, a_end.m_xAxis, a_end.m_yAxis - a_start.m_yAxis + 1, a_color);
    }
    else{

    }
}
