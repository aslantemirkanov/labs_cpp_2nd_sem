#include "6_trapezoid.h"

Trapezoid::Trapezoid(const std::initializer_list<Point> &other_point_array)
        : Polygon(other_point_array) {
    is_trapezoid = trapezoid_check();
    if (!is_trapezoid) {
        std::cout << "Object isn't trapezoid";
        exit(-1);
    }
}

Trapezoid::Trapezoid(const Trapezoid &other_trapezoid)
        : Polygon(other_trapezoid) {
}

bool Trapezoid::trapezoid_check() {
    if (size != 4) return false;
    Point A = point_array[0];
    Point B = point_array[1];
    Point C = point_array[2];
    Point D = point_array[3];
    bool is = false;
    Point vector_1(B.get_x() - A.get_x(), B.get_y() - A.get_y());
    Point vector_2(C.get_x() - B.get_x(), C.get_y() - B.get_y());
    Point vector_3(D.get_x() - C.get_x(), D.get_y() - C.get_y());
    Point vector_4(A.get_x() - D.get_x(), A.get_y() - D.get_y());
    if (vector_1.get_x() * vector_3.get_y() == vector_1.get_y() * vector_3.get_x() &&
        vector_1.get_y() * vector_3.get_x() != 0 &&
        vector_2.get_x() * vector_4.get_y() != vector_2.get_y() * vector_4.get_x())
        is = true;
    if (vector_2.get_x() * vector_4.get_y() == vector_2.get_y() * vector_4.get_x() &&
        vector_2.get_y() * vector_4.get_x() != 0 &&
        vector_1.get_x() * vector_3.get_y() != vector_1.get_y() * vector_3.get_x())
        is = true;
    return is;
};

Trapezoid::~Trapezoid() {
    delete[] point_array;

}
