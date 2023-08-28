#ifndef BOARD_HPP
#define BOARD_HPP
#include "./userInput.hpp"
#include "./tile.hpp"
#include "randomMt.hpp"
#include <algorithm>
// #include "./point.hpp"

class Point;
class Board {
private:
    Tile m_board[4][4];
public:
    Board() {
        int start[16]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        std::shuffle(&start[1], &start[15] + 1, Random::mt);
        for(int i = 0; i < 16; i++) {
            m_board[i/4][i%4] = {start[i]};
        }
    }
    bool validate();

    friend std::ostream& operator<<(std::ostream &out, Board b);
    friend class Point;
};

#endif