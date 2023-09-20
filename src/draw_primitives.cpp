
#include <algorithm> // swap

#include "draw_primitives.hpp"
#include "point.hpp"

namespace advcpp {
bool IsPointInPicture(ColorImage& a_image, int a_x, int a_y);
void DrawLine(ColorImage& a_image, const ColorRGB& a_color, const Point& a_start, const Point& a_end){

    // horizontal line
    if (a_start.m_yAxis == a_end.m_yAxis){
        DrawHorizontalLine(a_image, a_start.m_xAxis, a_end.m_xAxis, a_start.m_yAxis, a_color);
    }
    // vertical line
    else if (a_start.m_xAxis == a_end.m_xAxis){
        DrawVerticalLine(a_image, a_start.m_yAxis, a_end.m_yAxis, a_start.m_xAxis, a_color);
    }
    else{
        DrawLineAlgorithm(a_image, a_color, a_start, a_end);
    }
}

void DrawHorizontalLine(ColorImage& a_image, int a_startX, int a_endX, int a_y, ColorRGB const& a_color){
    if (a_startX > a_endX) {
        std::swap(a_startX, a_endX);
    }
    for (int x = a_startX; x <= a_endX; ++x){
        if (IsPointInPicture(a_image, x, a_y)){
            a_image.WriteColor( a_y, x, a_color);
        } 
    }
}

void DrawVerticalLine(ColorImage& a_image, size_t a_startY, size_t a_endY, size_t a_x, ColorRGB const& a_color){
    if (a_startY > a_endY) {
        std::swap(a_startY, a_endY);
    }
    for (size_t y = a_startY; y <= a_endY; ++y){
        if (IsPointInPicture(a_image, a_x, y)){
            a_image.WriteColor(y, a_x, a_color);
        }
    }
}

void DrawLineAlgorithm(ColorImage& a_image, const ColorRGB& a_color, const Point& a_start, const Point& a_end){

    int x0 = a_start.m_xAxis;
    int x1 = a_end.m_xAxis;
    int y0 = a_start.m_yAxis;
    int y1 = a_end.m_yAxis;

    int dx = x1 - x0;
    int dy = y1 - y0;

    // Check if the points are the same
    if (x0 == x1 && y0 == y1) {
        a_image.WriteColor( x0, y0, a_color);
        return;
    }

    if (x1 < x0) {
        std::swap(x0, x1);
    }

    //diff - the difference between points
    int diff = 2 * dy - dx;
    int y = y0;

    for(int x = x0; x < x1; x++){
        if (IsPointInPicture(a_image, x, y)){
            a_image.WriteColor( x, y, a_color);
            if(diff > 0){
                y = y + 1;
                diff = diff - 2 * dx;
            }
            else{
                diff = diff + 2 * dy;
            }
        }
    }
}

void DrawCircle(ColorImage& a_image, unsigned int a_row, unsigned int a_column, unsigned int a_radius, const ColorRGB& a_color) { 
    int xLocation = a_radius;
    int radiusError = 1 - xLocation;
    
    for(int yLocation = 0;  xLocation >= yLocation; ++yLocation) {
        a_image.WriteColor(a_row + yLocation, a_column - xLocation, a_color);
        a_image.WriteColor(a_row - yLocation, a_column - xLocation, a_color);
        a_image.WriteColor(a_row + xLocation, a_column - yLocation, a_color);
        a_image.WriteColor(a_row - xLocation, a_column - yLocation, a_color);
        a_image.WriteColor(a_row + yLocation, a_column + xLocation, a_color);
        a_image.WriteColor(a_row - yLocation, a_column + xLocation, a_color);
        a_image.WriteColor(a_row + xLocation, a_column + yLocation, a_color);
        a_image.WriteColor(a_row - xLocation, a_column + yLocation, a_color);
        if (radiusError < 0) {
            radiusError += 2 * yLocation + 1;
        }
        else {
            --xLocation;
            radiusError += 2 * (yLocation - xLocation) + 1;
        }

    }
}

bool IsPointInPicture(ColorImage& a_image, int a_x, int a_y){
    if (a_x < 0 || a_y < 0 ){
        return false;
    }
    return (a_x < static_cast<int>(a_image.Width()) && a_y < static_cast<int>(a_image.Height()));
}

} // namespace advcpp
