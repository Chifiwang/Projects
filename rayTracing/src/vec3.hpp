#ifndef VEC3_HPP
#define VEC3_HPP
// #include <iostream>
#include "constants.hpp"
#include <fstream>
#include <assert.h>
#include <cmath>

class Vec3 {
    double m_x;
    double m_y;
    double m_z;
public:
    Vec3(double x = 0.0, double y = 0.0, double z = 0.0) : m_x{x}, m_y{y}, m_z{z}{}
    double operator[](const int i) const;
    double &operator[](const int i);

    Vec3 &operator-();

    Vec3 &operator+=(Vec3 v);
    Vec3 &operator*=(double d); //scalar mult
    Vec3 &operator/=(double d);
    Vec3 &operator-=(Vec3 v);
    Vec3 &operator=(Vec3 v);

    friend Vec3 operator+(Vec3 u, Vec3 v);
    friend Vec3 cross(Vec3 &u, Vec3 &v); //cross prod
    Vec3 operator*(double d); //scalar mult
    friend Vec3 operator*(double d, Vec3 v); //scalar mult
    Vec3 operator/(double d); //scalar mult
    friend Vec3 operator/(double d, Vec3 &v); //scalar mult
    Vec3 operator-(Vec3 v);
    // friend Vec3 operator-(Vec3 u, Vec3 v);
    friend double dot(const Vec3 &u, const Vec3 &v); //dot prod

    Vec3 &norm();
    Vec3 get_norm();
    double magnitude();
    Vec3 to_colour();
    friend std::ostream &operator<<(std::ostream &out, Vec3 v);

    static Vec3 get_random();
    static Vec3 get_random_unit();
    static Vec3 get_random_hemisphere(Vec3 &norm);

    bool near_zero() const;
};

#endif