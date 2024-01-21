#include "camera.hpp"

void Camera::initalize_frame() {
    m_focal_length = Vec3{0, 0, 1};
    double view_height{2};
    double view_width{view_height*(static_cast<double>(m_img_width)/m_img_height)};

    m_img_origin = Point3(0, 0, 0);

    m_view_x = Vec3{view_width, 0, 0};
    m_view_y = Vec3{0, -view_height, 0};

    m_view_dx = Vec3{m_view_x/m_img_width};
    m_view_dy = Vec3{m_view_y/m_img_height};

    m_view_origin = Point3{m_img_origin + (m_view_dx + m_view_dy - m_view_x - m_view_y)*0.5 - m_focal_length};
}
void Camera::shift(Ray &r) {
    double rx = -0.5 + util::rand(0, 1);
    double ry = -0.5 + util::rand(0, 1);

    r.set_direct(r.get_direct() + rx*m_view_dx + ry*m_view_dy);
}
Colour Camera::get_colour(Hittables &obj, Ray &r, int depth) {
    m_hr = Hit_record{};
    if(depth <= 0) {
        return Colour(0, 0, 0);
    }
    if(obj.hit(r, Interval{0.001, static_cast<double>(depth)}, m_hr)) {
        // return (m_hr.norm + Colour(1, 1, 1))*0.5; //normal map
        Vec3 rand_dir{Vec3::get_random_hemisphere(m_hr.norm)};
        // m_hr.mat->scatter()
        // Vec3 rand_dir{m_hr.dir};
        Ray rand_ray{m_hr.pt, rand_dir + m_hr.norm};
        return 0.5*get_colour(obj, rand_ray, depth - 1);
    }
    return paint_background(r);
    // return (0, 255, 255);
}
void Camera::set_colour(Hittables &obj, Ray &r) {
    Colour cumulative{0,0,0};
    for(int i = 0; i < m_sample_size; i++){
        Ray temp{r};
        shift(temp);
        cumulative += get_colour(obj, temp, m_max_depth);
    }
    cumulative /= m_sample_size;

    Interval i{0, 0.999};//fix Colour::to_colour();
    i.clamp(std::sqrt(cumulative[0]));
    i.clamp(std::sqrt(cumulative[1]));
    i.clamp(std::sqrt(cumulative[2]));

    r.set_colour(cumulative*255);
}
Colour Camera::paint_background(Ray &r) {
    double a{0.5*(r.get_direct().get_norm()[1] + 1.0)};
    return ((1.0-a)*Colour(1.0, 1.0, 1.0) //lerp
        + a*Colour(0.5, 0.7, 1.0));
    // return r.get_colour();
}
void Camera::render(Hittables world, std::ofstream &output) {
    output << "P3\n" << m_img_width << ' ' << m_img_height << "\n255\n";

    for (int j = 0; j < m_img_height; ++j) {
        for (int i = 0; i < m_img_width; ++i) {
            Vec3 current_pixel{m_view_origin + j*m_view_dy + i*m_view_dx};
            Ray casted_ray{m_img_origin, current_pixel - m_img_origin};

            set_colour(world, casted_ray);
            output << casted_ray.get_colour() << '\n';
        }
    }
}
