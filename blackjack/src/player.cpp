#include "./player.hpp"

void Player::draw(Deck &d) {
    m_hand.push_back(d.drawCard());
    m_handVal += (
        m_hand.back().getRank() == Card::rank_ace 
        && (m_handVal + 11 > 21)
    ) ? 1 : m_hand.back().value();
    m_isBust = m_handVal >= g_maxScore;
}
void Player::print() {
    for(int i = 0 + static_cast<int>(m_isHidden); i < m_hand.size(); i++) {
        m_hand[i].print();
    }
}
[[maybe_unused]] void Player::hideCard() {
    assert(m_hand.size() > 0);
    m_isHidden = true;
    m_handVal -= m_hand[0].value();
}
[[maybe_unused]] void Player::unHideCard() {
    assert(m_isHidden);
    m_isHidden = false;
    m_handVal += m_hand[0].value();
}
int Player::value() {
    return m_handVal;
}