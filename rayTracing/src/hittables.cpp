#include "./hittables.hpp"
#include <iostream>
void Hittables::clear() {
    objs.clear();
}
void Hittables::add(shared_ptr<Hittable> s_ptr) {
    objs.push_back(s_ptr);
}
bool Hittables::hit(Ray &r, Interval i, Hit_record &rec) {
    Hit_record temp;
    bool is_hit{false};
    double closest{i.m_max};

    for(shared_ptr<Hittable> &obj : objs) {
        if(obj->hit(r, Interval{i.m_min, closest}, temp)) {
            closest = temp.t;
            is_hit = true;
            rec = temp;
        }
    }
    // std::cout << "a";
    // rec.mat->scatter(r, rec, rec.mat->m_albedo);
    return is_hit;
}