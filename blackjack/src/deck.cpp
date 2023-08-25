#include "./deck.hpp"

void Deck::print() {
    for(Card c : m_deck) {
        c.print();
    }
}
void Deck::shuffle() {
    std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
}
const Card Deck::drawCard() {
    assert(i < 52);
    return m_deck[i++];
}