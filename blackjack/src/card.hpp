#include <iostream>

class Card {
public:
    enum Suit {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum Rank {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };
private:
    Suit m_suit{};
    Rank m_rank{};
    static int nextCard;
    Card() 
    : m_rank{static_cast<Card::Rank>(nextCard % max_ranks)}
    , m_suit{static_cast<Card::Suit>((nextCard++ / max_ranks) % max_suits)} {}
public:
    Card(Rank r, Suit s) : m_rank{r}, m_suit{s} {}
    const Suit getSuit() const {return m_suit;}
    const Rank getRank() const {return m_rank;}
    void print() const;
    int value() const;

    friend class Deck;
};