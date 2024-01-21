#include "./vec3.hpp"

double Vec3::operator[](const int i) const {
    assert((i < 3 && i > -1) && "index out of bounds i must be within 0 <= i <= 3");

    switch (i) {
    case 0:
        return m_x;
    case 1:
        return m_y;
    case 2:
        return m_z;
    default:
        return 0;
    }
}
double &Vec3::operator[](const int i) {
    assert((i < 3 && i > -1) && "index out of bounds i must be within 0 <= i <= 3");

    switch (i) {
    case 0:
        return m_x;
    case 1:
        return m_y;
    case 2:
        return m_z;
    default:
        return m_x;
    }
}

Vec3 &Vec3::operator-() {
    m_x = -m_x;
    m_y = -m_y;
    m_z = -m_z;

    return *this;
}

Vec3 &Vec3::operator+=(Vec3 v) {
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;

    return *this;
}
Vec3 &Vec3::operator*=(double d) { //scalar mult
    m_x *= d;
    m_y *= d;
    m_z *= d;
    
    return *this;
}
Vec3 &Vec3::operator/=(double d) { //scalar mult
    m_x /= d;
    m_y /= d;
    m_z /= d;
    
    return *this;
}
Vec3 &Vec3::operator-=(Vec3 v) {
    m_x -= v.m_x;
    m_y -= v.m_y;
    m_z -= v.m_z;

    return *this;
}
Vec3 &Vec3::operator=(Vec3 v) {
    m_x = v.m_x;
    m_y = v.m_y;
    m_z = v.m_z;

    return *this;
}

Vec3 operator+(Vec3 u, Vec3 v) {
    return Vec3{u.m_x + v.m_x, u.m_y + v.m_y, u.m_z + v.m_z};
}
Vec3 cross(Vec3 &u, Vec3 &v) { //cross prod
    return Vec3{u.m_y*v.m_z - u.m_z*v.m_y, u.m_z*v.m_x - u.m_x*v.m_z, u.m_x*v.m_y - u.m_y*v.m_x};
}
Vec3 Vec3::operator*(double d) { //scalar mult
    return Vec3{d*m_x, d*m_y, d*m_z};
}
Vec3 operator*(double d, Vec3 v) {
    return Vec3{d*v.m_x, d*v.m_y, d*v.m_z};
}
Vec3 Vec3::operator/(double d) { //scalar mult
    return Vec3{m_x/d, m_y/d, m_z/d};
}
Vec3 operator/(double d, Vec3 &v) {
    return Vec3{v.m_x/d, v.m_y/d, v.m_z/d};
}
Vec3 Vec3::operator-(Vec3 v) {
    return Vec3{m_x - v.m_x, m_y - v.m_y, m_z - v.m_z};
}
// Vec3 operator-(Vec3 u, Vec3 v) {
//     return Vec3{u.m_x - v.m_x, u.m_y - v.m_y, u.m_z - v.m_z};
// }
double dot(const Vec3 &u, const Vec3 &v) { //dot prod
    return u.m_x*v.m_x + u.m_y*v.m_y + u.m_z*v.m_z;
}

Vec3 &Vec3::norm() {
    double inv_mag{1/std::sqrt(magnitude())};

    (*this)*=inv_mag;
    return *this;
}
Vec3 Vec3::get_norm() {
    double inv_mag{1/magnitude()};

    return (*this)*inv_mag;
}
double Vec3::magnitude() {
    return std::sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}
Vec3 Vec3::to_colour() {
    return (*this).get_norm()*255.999;
}
std::ostream &operator<<(std::ostream &out, Vec3 v) {
    return out << v.m_x << ' ' << v.m_y << ' ' << v.m_z;
}
Vec3 Vec3::get_random() {
    return Vec3{util::rand(-1, 1), util::rand(-1, 1), util::rand(-1, 1)};
}
Vec3 Vec3::get_random_unit() {
    // return get_random().norm();
     while (true) {
        auto p{Vec3::get_random()};
        if (dot(p, p) < 1)
            return p.norm();
    }
}
Vec3 Vec3::get_random_hemisphere(Vec3 &norm) {
    Vec3 r = get_random_unit();
    if(dot(norm, r) > 0) {
        return r;
    }
    return -r;
}
bool Vec3::near_zero() const {
    // Return true if the vector is close to zero in all dimensions.
    double s{1e-8};
    return (std::fabs(m_x) < s) && (std::fabs(m_y) < s) && (std::fabs(m_z) < s);
}