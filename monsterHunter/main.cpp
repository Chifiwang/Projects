#include "./src/player.hpp"
#include "./src/monster.hpp"
#include <iostream>
#include <conio.h>

int main() {
    std::cout << 
        "                        _                              _            \n"
        "  /\\/\\   ___  _ __  ___| |_ ___ _ __ /\\  /\\_   _ _ __ | |_ ___ _ __ \n"
        " /    \\ / _ \\| '_ \\/ __| __/ _ | '__/ /_/ | | | | '_ \\| __/ _ | '__|\n"
        "/ /\\/\\ | (_) | | | \\__ | ||  __| | / __  /| |_| | | | | ||  __| |   \n"
        "\\/    \\/\\___/|_| |_|___/\\__\\___|_| \\/ /_/  \\__,_|_| |_|\\__\\___|_|   \n"
        "\n                     --Press any key to start--\n\n";
    getch();

    while(true) {
        std::string n{};
        std::cout << "Enter your Name: ";
        std::cin >> n;
        Player p{n};
        std::cout << "Welcome, " << n << '\n';
        while(true) {
            std::cout 
                << "You have " << p.getHp() << " health and are carrying " 
                << p.getGold() << " gold.\n";
            Monster m{Monster::getRandomMonster()};
            std::cout 
                << "You have encountered a " << m.getName() 
                << " (" << m.getSymbol() << ")\n";
            char ans{};
            while (!m.isDead() && !p.isDead()) {
                std::cout << "(R)un or (F)ight: ";

                while(true) {
                    std::cin.clear();
                    std::cin.ignore(std::cin.rdbuf()->in_avail());
                    std::cin >> ans;
                    if(ans == 'f' || ans == 'r') {
                        break;
                    }
                }

                if(ans == 'f') {
                    m.reduceHp(p.getDmg());
                    std::cout 
                        << "You hit the " << m.getName() 
                        << " for " << p.getDmg() << " damage.\n";
                } else if(Random::get_rand<int>(0, 1)){
                    std::cout << "You successfully fled.\n";
                    break;
                } else {
                    std::cout << "You failed to flee.\n";
                }

                if(!m.isDead()) {
                    p.reduceHp(m.getDmg());
                    std::cout 
                        << "The " << m.getName() << " hit you for " 
                        << m.getDmg() << " damage.\n";
                }
            }

            if(p.isDead()) {
                std::cout 
                    << "You died at level "<< p.getLevel() 
                    <<" and with " << p.getGold() << " gold. \n"
                    << "Too bad you can't take it with you!\n";
                break;
            } else if(ans == 'r') {
                continue;
            }

            p.levelUp();
            p.addGold(m.getGold());
            std::cout << "You killed the " << m.getName() << ".\n";
            std::cout << "You are now level " << p.getLevel() << ".\n";
            std::cout << "You found " << m.getGold() << " gold.\n";
        }
        std::cout << "Would you like to play again " << n <<"? (y/n) ";
        char ans{};
        while(true) {
            std::cin.clear();
            std::cin.ignore(std::cin.rdbuf()->in_avail());
            std::cin >> ans;
            if(ans == 'y' || ans == 'n') {
                break;
            }
        }

        if (ans == 'n') {
            break;
        } 
    }
    return 0;
}