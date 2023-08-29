#include "./monster.hpp"


Monster Monster::getRandomMonster() {
    return Monster{static_cast<Type>(Random::get_rand<int>(0, static_cast<int>(max_types) - 1))};
}