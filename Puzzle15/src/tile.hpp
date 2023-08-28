#ifndef TILE_HPP
#define TILE_HPP
#include <iostream>

class Tile {
private:
    int m_val{};
public:
    Tile(int v = 0) : m_val{v}{}
    bool isEmpty() const { return m_val == 0; }
    int getNum() const { return m_val; }
    void setNum(int i) { m_val = i;}
    friend std::ostream& operator<<(std::ostream& out, const Tile &t);
    
};
#endif