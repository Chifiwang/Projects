#include "./tile.hpp"

std::ostream& operator<<(std::ostream& out, const Tile &t) {
    if(t.m_val == 0) {
        return out << "    ";
    }

    if(t.m_val < 10) {
        return out << "  " << t.m_val << ' ';
    }

    return out << ' ' << t.m_val << ' ';
}