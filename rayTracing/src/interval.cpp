#include "interval.hpp"

bool Interval::operator[](double x) {
    return m_min <= x && x <= m_max;
}
bool Interval::operator()(double x) {
    return m_min < x && x < m_max;
}
double Interval::clamp(double x) {
    if(x < m_min) return m_min;
    if(x > m_max) return m_max;
    return x;
}