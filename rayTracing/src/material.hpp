#ifndef MATERIAL_HPP
#define MATERIAL_HPP
#include "ray.hpp"
#include "hittable.hpp"
#include <memory>
class Hit_record;
class Material {
public:
    virtual ~Material() = default;
    virtual bool scatter(
        Ray &r, Hit_record &hr, Colour &attenuation, Ray &out
    ) = 0;
};

class Diffuse : public Material {
    Colour albedo;
public:
    Diffuse(Colour a = Colour(0,0,0)) : albedo{a}{}
    bool scatter(
        Ray &r, Hit_record &hr, Colour &attenuation, Ray &out
    ) override;
};
#endif