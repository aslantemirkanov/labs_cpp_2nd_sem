#include "5_triangle.h"


Triangle::Triangle(const std::initializer_list<Point> &other_point_array)
    : Polygon(other_point_array){}

Triangle::Triangle(const Triangle &other_triangle)
    : Polygon(other_triangle) {}

Triangle::~Triangle() {
    delete[] point_array;
}

