#include "./card.hpp"
#include "./randomMt.hpp"
#include <array>
#include <algorithm>
#include <cassert>

class Deck {
public:
    using Deck_t = std::array<Card, 52>;
    // using Index = DeckType::size_type;
    int i;
private:
    Deck_t m_deck{};
    
public:
    Deck() : m_deck{{}}, i{0}{};
    Deck(std::mt19937 mt) : m_deck{{}}, i{0}
        {std::shuffle(m_deck.begin(), m_deck.end(), mt);};
    void print();
    void shuffle();
    const Card drawCard();
};
