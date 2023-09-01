#include ".\randomMT.h"
#include <random>
#include <chrono>
#include <iostream>

// using namespace Random;

 std::mt19937 get_rand_var() {
    std::random_device rd{};
    std::seed_seq ss{static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()), 
                    rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    
    return std::mt19937{ss};
}

 std::mt19937 mt{get_rand_var()};

template <typename T, typename M, typename N>
 T Random::get_rand(N min, M max) {
    return std::uniform_int_distribution<T>{static_cast<T>(min), static_cast<T>(max)}(mt);
}
void doNothing() { //wtf is going on donot touch for fear of everything comming down in a hell fire
// goto THERE;
    Random::get_rand<int>(1, 10);
// THERE:
    // ;

}