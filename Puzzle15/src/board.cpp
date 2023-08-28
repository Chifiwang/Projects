#include "./board.hpp"

bool Board::validate() {
    bool out{true};
    for(int i = 0; i < 15; i++) {
            out &= m_board[i/4][i%4].getNum() == (i + 1);
    }
    return out;
}


std::ostream& operator<<(std::ostream &out, Board b) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            out << b.m_board[i][j];
        } out << '\n';
    }

    return out;
}