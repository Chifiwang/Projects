#include "./hittable.hpp"
#include <iostream>

void Hit_record::set_face_dir(Ray &r, Vec3 norm) {
    Hit_record::norm = (dot(r.get_direct(), norm) < 0) ? norm : -norm; 
}

bool Diffuse::scatter(Ray &r, Hit_record &hr, Colour &attenuation) {
    hr.dir = Vec3::get_random_hemisphere(hr.norm);
    std::cout << "here";
    return true;
}