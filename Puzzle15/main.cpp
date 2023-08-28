#include "./src/point.hpp"
#include <conio.h>



int main() {
    bool isQuit{false};
    std::cout 
        << "  __ _____       _____               _      \n" 
        << " /_ | ____|     |  __ \\             | |     \n"
        << "  | | |__ ______| |__) |   _ _______| | ___ \n"
        << "  | |___ \\______|  ___/ | | |_  /_  / |/ _ \\\n"
        << "  | |___) |     | |   | |_| |/ / / /| |  __/\n"
        << "  |_|____/      |_|    \\__,_/___/___|_|\\___|\n"
        << "\n         --Press any key--\n";
            
    getch();

    while(!isQuit) {
        Board b{};
        Point p{};
        while (!b.validate()) {
            std::cout << "\nBoard:\n" << b;

            std::cout << "What is your next action? [w, a, s, d, q]\n";
            Action a{getAction()};
            
            if(a == quit) {
                isQuit = true;
                break;
            }

            p.move(a, b);
        }
        if(!isQuit){
            std::cout << "\nCongratulations, You win!\n";
            std::cout << "Would you like to play again? [y/n] ";
            while(true) {
                char ans{};
                std::cin.clear();
                std::cin.ignore(std::cin.rdbuf()->in_avail());
                std::cin >> ans;

                if(ans == 'y') {
                    break;
                } else if (ans == 'n') {
                    isQuit = true;
                    break;
                }
            }
        }
            
    }
    return 0;
}