#include "./creature.hpp"

class Player : public Creature {
    int m_level{};
public:
    Player(std::string n) : Creature{n, '@', 10, 1, 0}, m_level{0}{}
    void levelUp();
    const int getLevel() const;
    bool hasWon() const;
};