#include "src/sphere.hpp"
#include "src/camera.hpp"
#include <iostream>
#include <fstream>

int main() {
    Camera cam{400, 16.0/9.0};
    std::ofstream output("./out/image.ppm", std::ofstream::out);

    Hittables world;

    world.add(make_shared<Sphere>(0.5, Point3(0, 0, -1)));
    world.add(make_shared<Sphere>(100, Point3(0, -100.5, -1)));

    cam.render(world, output);
    output.close();
}