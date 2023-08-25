#include "./card.hpp"

int Card::nextCard = -1;
void Card::print() const {
    switch (m_rank) {
        case rank_10:
            std::cout << 'T';
            break;
        case rank_jack:
            std::cout << 'J';
            break;
        case rank_queen:    
            std::cout << 'Q';
            break;
        case rank_king:
            std::cout << 'K';
            break;
        case rank_ace:
            std::cout << 'A';
            break;
        default:
            std::cout << m_rank + 2;
            break;
    }
    switch (m_suit) {
        case spade:
            std::cout << "S";
            break;
        case heart:
            std::cout << "H";
            break;
        case club:    
            std::cout << "C";
            break;
        case diamond:
            std::cout << "D";
            break;
    }
    std::cout << ' ';
}
int Card::value() const {
    switch (m_rank) {
        case rank_jack:
        case rank_queen:    
        case rank_king:
        case rank_ace:
            return 11;
        default:
            return m_rank + 2;
            break;
    }
}