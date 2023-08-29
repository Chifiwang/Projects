#include "./creature.hpp"

const std::string& Creature::getName() const {
    return m_name;
}
const char Creature::getSymbol() const {
    return m_symbol;
}
const int Creature::getHp() const {
    return m_hp;
}
int &Creature::getDmg() {
    return m_dph;
}
const int Creature::getGold() const {
    return m_gold;
}
void Creature::reduceHp(int dmg) {
    m_hp -= dmg;
}
bool Creature::isDead() const {
    return m_hp <= 0;
}
void Creature::addGold(int gold) {
    m_gold += gold;
}