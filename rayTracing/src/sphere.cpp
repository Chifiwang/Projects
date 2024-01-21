#include "sphere.hpp"
#include <iostream>
double Sphere::intersect(Ray r) {
    Vec3 ac{r.get_point() - m_c};
    double a{dot(r.get_direct(), r.get_direct())};
    double b_half{dot(ac, r.get_direct())};
    double c{dot(ac, ac) - m_r*m_r};
    double delta{b_half*b_half - a*c};
    
    if (delta < 0) {   
        return -1.0;
    } else {
        return (-b_half - std::sqrt(delta))/a;
    }
}

Vec3 Sphere::get_norm(Point3 p) {
    return (p - m_c).get_norm();
    // std::cout << (p).magnitude() << ' ';
    // return p;
}

bool Sphere::hit(Ray &r, Interval i, Hit_record &rec) {
    Vec3 ac{r.get_point() - m_c};
    double a{dot(r.get_direct(), r.get_direct())};
    double b_half{dot(ac, r.get_direct())};
    double c{dot(ac, ac) - m_r*m_r};
    double delta{b_half*b_half - a*c};
    
    if (delta < 0) {   
        return false;
    }

    double rt{(-b_half - std::sqrt(delta))/a};

    if (!i(rt)) {
        rt = (-b_half + std::sqrt(delta))/a;
        if (!i(rt)) {
            return false;
        }
    }

    rec.t = rt;
    rec.pt = r.at(rt);
    rec.set_face_dir(r, ((rec.pt - m_c)/m_r));
    rec.norm = ((rec.pt - m_c).get_norm());
    rec.mat = m_mat;

    // rec.mat->scatter(r, rec, m_mat->m_albedo);
    return true;
}