#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include <memory>
#include <limits>
#include <cmath>
#include <random>

namespace util {
const double ifty{std::numeric_limits<double>::infinity()};
const double pi{3.1415926535897932385};

using radians = double;
using degrees = double;
inline degrees to_deg(radians theta) {return theta*180.0/pi;}
inline radians to_rad(degrees theta) {return theta*pi/180.0;}
inline double rand(double min = 0, double max = 1) {
    static std::uniform_real_distribution<double> dist(min, max);
    static std::mt19937 mt;
    return dist(mt);
}
}
#endif