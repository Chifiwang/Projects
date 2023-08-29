#include "./player.hpp"

void Player::levelUp() {
    ++m_level;
    ++getDmg();
}
const int Player::getLevel() const {
    return m_level;
}
bool Player::hasWon() const {
    return m_level >=20;
}