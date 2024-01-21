#ifndef INTERVAL_HPP
#define INTERVAL_HPP
#include "constants.hpp"
class Interval {
public:
    double m_min;
    double m_max;

    Interval(double min = util::ifty, double max = -util::ifty) : m_min{min}, m_max{max}{}

    bool operator[](double x);
    bool operator()(double x);
    double clamp(double x);
};

const static Interval empty{};
const static Interval universal{-util::ifty, util::ifty};
#endif