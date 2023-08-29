#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <string>

class Creature {
    std::string m_name{};
    char m_symbol{};
    int m_hp{};
    int m_dph{};
    int m_gold{};
public:
    Creature(std::string n, char s, int h, int d, int g) : m_name{n}, m_symbol{s}, m_hp{h}, m_dph{d}, m_gold{g}{}
    const std::string& getName() const;
    const char getSymbol() const;
    const int getHp() const;
    int &getDmg();
    const int getGold() const;
    void reduceHp(int dmg);
    bool isDead() const;
    void addGold(int gold);
};
#endif