#include "./userInput.hpp"
#include <iostream>



UserIn::Action UserIn::getAction() {
    while(true) {
        char uIn;
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        std::cin >> uIn;
        switch (uIn) {
        case 'w':
            return UserIn::Action::up;
        case 'a':
            return UserIn::Action::left;
        case 's':
            return UserIn::Action::down;
        case 'd':
            return UserIn::Action::right;
        case 'q':
            return UserIn::Action::quit;
        default:
            break;
        }
    }

    return UserIn::Action::num_actions;
}