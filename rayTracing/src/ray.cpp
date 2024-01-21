#include "ray.hpp"

Point3 Ray::at(double t) {
    return m_a + t*m_b;
}
void Ray::set_colour(int r, int g, int b) {
    m_colour = Colour{static_cast<double>(r), static_cast<double>(g), static_cast<double>(b)};
}
void Ray::set_colour(Colour c) {
    m_colour = c;
}
const Colour Ray::get_colour() const {
    return m_colour;
}
Vec3 Ray::get_direct() {
    return m_b;
}
void Ray::set_direct(Vec3 v) {
    m_b = v;
}
Vec3 Ray::get_point() {
    return m_a;
}