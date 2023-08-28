#include "./point.hpp"

bool Point::isValid(UserIn::Action a) {
    switch (a) {
    case up:
        return m_y > 0;
    case down:
        return m_y < 3;
    case left:
        return m_x > 0;
    case right:
        return m_x < 3;
    default:
        return false;
    }
}
void Point::move(Action a, Board &b) {
    if (isValid(a)) {
        switch (a) {
        case up:
            std::swap(b.m_board[m_y][m_x], b.m_board[m_y--][m_x]);
            break;
        case down:
            std::swap(b.m_board[m_y][m_x], b.m_board[m_y++][m_x]);
            break;
        case left:
            std::swap(b.m_board[m_y][m_x], b.m_board[m_y][m_x--]);
            break;
        case right:
            std::swap(b.m_board[m_y][m_x], b.m_board[m_y][m_x++]);
            break;
        }
    }
}