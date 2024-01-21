#ifndef HITTABLES_HPP
#define HITABLES_HPP
#include "./hittable.hpp"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class Hittables : public Hittable{
    std::vector<shared_ptr<Hittable>> objs;
public:
    Hittables(){}
    Hittables(shared_ptr<Hittable> s_ptr) {objs.push_back(s_ptr);}

    void clear();
    void add(shared_ptr<Hittable> s_ptr);
    bool hit(Ray& r, Interval i, Hit_record& rec) override;
};
#endif