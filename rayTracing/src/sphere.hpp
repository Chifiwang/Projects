#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "./hittable.hpp"

class Sphere : public Hittable{
    double m_r;
    Point3 m_c;
    Material *m_mat;
public:
    Sphere(double r, Point3 c, Material&& m = Diffuse()) : m_r{r}, m_c{c}, m_mat{&m} {}
    // Vec3 get_centre();
    // double get_radius();
    bool hit(Ray &r, Interval i, Hit_record &rec) override;
    double intersect(Ray r);
    Vec3 get_norm(Point3 p);
};

#endif