#ifndef RAY_HPP
#define RAY_HPP
#include "vec3.hpp"
// #include "colour.hpp"

using Point3 = Vec3;
using Colour = Vec3;

class Ray {
public:
private:
    Point3 m_a;
    Vec3 m_b;
    Vec3 m_colour;
public:
    Ray(Point3 a, Vec3 b) : m_a{a}, m_b{b}{}
    Point3 at(double t);
    void set_colour(int r, int g, int b);
    void set_colour(Colour c);
    const Colour get_colour() const;
    void set_direct(Vec3 v);
    Vec3 get_direct();
    Vec3 get_point();
};

#endif