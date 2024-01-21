#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "hittables.hpp"
#include "constants.hpp"
#include "interval.hpp"
// #include "material.hpp"
#include <fstream>


class Camera {
    int m_img_width;
    int m_img_height;
    double m_aspect_ratio;

    Hit_record m_hr;

    Vec3 m_focal_length;
    Point3 m_img_origin{};
    Point3 m_view_origin;

    Vec3 m_view_x;
    Vec3 m_view_y;
    Vec3 m_view_dx;
    Vec3 m_view_dy;

    void initalize_frame();
    void set_colour(Hittables &obj, Ray &r);
    Colour get_colour(Hittables &obj, Ray &r, int depth);
    Colour paint_background(Ray &r);
    void shift(Ray &r);

    int m_sample_size{100};
    int m_max_depth{50};
public:
    Camera(int w, double aspect) 
        : m_img_width{w}, m_aspect_ratio{aspect}
        , m_img_height{std::max(static_cast<int>(w/aspect), 1)}{initalize_frame();}
    void render(Hittables world, std::ofstream &output);
    
};
#endif