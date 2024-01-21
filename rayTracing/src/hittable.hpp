#ifndef HITTABLE_HPP
#define HITTABLE_HPP
#include "./ray.hpp"
#include "interval.hpp"
// #include "material.hpp"
#include <memory>
class Material;
class Hit_record {
public:
    Point3 pt;
    Vec3 norm;
    Vec3 dir;
    double t;
    Material *mat;

    void set_face_dir(Ray &r, Vec3 norm);
};

class Material {
public:
    Colour m_albedo;
    virtual ~Material() = default;
    virtual bool scatter(
        Ray &r, Hit_record &hr, Colour &attenuation
    ) = 0;
};

class Diffuse : public Material {
public:
    Colour m_albedo;
    Diffuse(Colour a = Colour(0,0,0)) : m_albedo{a}{}
    bool scatter(
        Ray &r, Hit_record &hr, Colour &attenuation
    ) override;
};

class Hittable {
public:
    virtual ~Hittable() = default;
    virtual bool hit(Ray &r, Interval i, Hit_record &rec) = 0;
};
#endif