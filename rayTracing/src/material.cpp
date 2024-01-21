#include "material.hpp"
bool Diffuse::scatter(Ray &r, Hit_record &hr, Colour &attenuation, Ray &out) {
    Vec3 rand_dir{Vec3::get_random_hemisphere(hr.norm)};
    
    if(rand_dir.near_zero())
        rand_dir = hr.norm;

    out = Ray{hr.pt, rand_dir/* + m_hr.norm */};
    attenuation = albedo;
    return true;
}