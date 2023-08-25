#ifndef RANDOM_H
#define RANDOM_H
#include <random>
#include <chrono>

namespace Random {
    namespace {
        inline std::mt19937 seed_rand_var() {
            std::random_device rd{};
            std::seed_seq ss{static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()), 
                            rd(), rd(), rd(), rd(), rd(), rd(), rd()
                            };
        
            return std::mt19937{ss};
        }

        inline std::mt19937 mt{seed_rand_var()};
    }

    template <typename T, typename M, typename N>
    inline T get_rand_int(N min, M max) {
        return std::uniform_int_distribution<T>{static_cast<T>(min), static_cast<T>(max)}(mt);
    }
}
#endif