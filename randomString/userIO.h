#ifndef USERIO_H
#define USERIO_H
#include <string_view>
#include <string>
#include <sstream>
#include <iostream>

namespace userIn {
    namespace {
        std::string get_line() {
            std::string input{};
            std::getline(std::cin, input, '\n');
            return input;
        }
    }
    enum Commands {
        restart, 
        recreate, 
        exit,
    };

    template <typename T> T get_input() {
        T output;

        while (true) {
            std::stringstream input_buff(get_line());

            if(input_buff >> output) {
                break;
            }
        }

        return output;
    }

    bool get_validated_YN(std::string_view prompt) {
        char output;
        while (true) {
            std::cout << prompt;
            std::stringstream input_buff(get_line());

            if(input_buff.str().length() == 1 && input_buff >> output && (output == 'y'|| output =='Y')) {return true;} 
            else if(input_buff.str().length() == 1 && (output == 'n'|| output =='N')) {return false;}
        }
        return false;
    }
    
    int is_restart() {
        std::stringstream input_buff(get_line());
        char action;
        input_buff >> action;
        switch (action) {
        case 's':
            return restart;
        case 'r':
            return recreate;
        default:
            return exit;
        }
    }
}

#endif