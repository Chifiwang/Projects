#include "./creature.hpp"
#include "./randomMT.hpp"
#include <array>

class Monster : public Creature {
public:
    enum Type {
        DRAGON,
        ORC,
        SLIME,
        max_types,
    };
private:
public:
    Monster(Type t) : Creature{getDefaultCreature(t)}{}
    static const Creature& getDefaultCreature(Type type) {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
            { { "dragon", 'D', 20, 4, 100 },
            { "orc", 'o', 4, 2, 25 },
            { "slime", 's', 1, 1, 10 } }
        };

        return monsterData.at(static_cast<std::size_t>(type));
    }
    static Monster getRandomMonster();
};