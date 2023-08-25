#include "./deck.hpp"
#include <vector>

class Player {
public:
    // using [[maybe_unused]] = DealerOnly;
    const static int g_maxScore{21};
    bool m_isBust{};
    bool m_notStand{};
private:
    std::vector<Card> m_hand{};
    int m_handVal{};
    [[maybe_unused]] bool m_isHidden{}; //for dealer
public:
    Player() : m_handVal{0}, m_isBust{false}, m_isHidden{false}, m_notStand{true}{}
    [[maybe_unused]] void hideCard(); //for dealer
    [[maybe_unused]] void unHideCard(); //for dealer
    void draw(Deck &d);
    void print();
    int value();
};