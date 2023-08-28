#ifndef USERINPUT_HPP
#define USERINPUT_HPP
// #include <iostream>

namespace UserIn {
    enum Action : int {
    up,
    down,
    left, 
    right, 
    quit, 
    num_actions,
    };
    
    Action getAction();
}

#endif