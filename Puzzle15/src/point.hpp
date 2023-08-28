#ifndef POINT_HPP
#define POINT_HPP
#include "./board.hpp"
using namespace UserIn;

class Point {
    // Tile *p_gap{};
    int m_x{};
    int m_y{};
public:
    Point(int x = 0, int y = 0) : m_x{x}, m_y{y}{}
    void move(UserIn::Action a, Board &b);
    bool isValid(Action a);
    

};

#endif