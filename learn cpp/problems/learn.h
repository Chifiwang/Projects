#ifndef LEARN_H
#define LEARN_H
#include <string>
#include <bitset>
#include <array>

int get_int(std::string msg);
int get_int();
void print(std:: string msg);
void q1_11();
void q1_x();
int q2_4a(int x);
void q2_4b();
int q2_7(int a, int b, int c, int d);
void q2_8();
void q2_xa();
void q4_3a();
bool q4_9a();
void q4_12();
void q4_17();
void q4_xa();
void q4_xb();
void q5_3a();
bool q5_3b(int a);
void qO_2a();
std::bitset<4> qO_2b(std::bitset<4> bits);
void qO_3a();
void qO_4();
void q6_3();
void q6_xa();
void q6_xb1();
void q6_xb2();
void q7_6();
void q7_7a();
void q7_7b();
void q7_7c();
void q7_10a();
void q7_10b();
void q7_10c(int a);
void q7_10d();
bool q7_xa1(int a);
void q7_xa2();
void q7_xb();
namespace q8_8 {
    using PrintError = int;
    PrintError printdata();
}
namespace q8_xa {
    using Degrees = double;
    using Radians = double;
    namespace constants {
        inline constexpr double pi { 3.14159 };
    }
    void q8_xa();
}
namespace q8_xb {
    template <typename T, typename U> auto add(T a, U b);
    template <typename T, typename U> auto mult(T a, U b);
    template <typename T, typename U> auto sub(T a, U b);
    void q8_xb();
}
namespace q9 {void q9_x();}
namespace q10 {
    namespace Monster {
        enum MonsterType {
            orcs, 
            goblins, 
            trolls, 
            ogres,
            skeletons,
        };
    }
    enum class Animal {
        pig,
        chicken, 
        cat, 
        dog, 
        duck,
    };
    constexpr std::string_view getAnimalName(Animal a);
    void printNumberofLegs(Animal a);
    struct Ad {
        int watched = 0;
        double clickThroughPercent = 0;
        double avgEarnings = 0;
    };
    void printData(Ad a);
        struct Fraction {
        int n = 0;
        int d = 1;
    };
    Fraction mult(Fraction x, Fraction y);
    struct MonsterStats {
        std::string_view type;
        std::string_view name;
        int hp;
    };
    template <typename T> struct Triad {
        T a;
        T b;
        T c;
    };
    template <typename T> Triad(T, T, T) -> Triad<T>;
    void printMonster(MonsterStats m);
    template <typename T> void print(const Triad<T>& t);
    void q10_2();
    void q10_3();
    void q10_6a();
    void q10_6b();
    void q10_xa();
    void q10_xb();
    void q10_y();
}
namespace q11 {
    namespace Animals {
        enum Animals {
            chicken, 
            dog, 
            cat, 
            elephant, 
            duck, 
            snake, 
            totalNumAnimals, 
        };
    }
    int* select_sort(int *arr, int arr_size, bool order); 
    int* bubble_sort(int* arr, int arr_size, bool order);
    int* findvalue(int* begin, int* end, int val);
    int count(std::array<int, 3> arr);
    void q11_2();
    void q11_3a();
    void q11_3b();
    void q11_3c();
    void q11_4a();
    void q11_8();
    void q11_10();
    void q11_12();
    void q11_xa();
    void q11_xb();
    void q11_xc();
    void q11_xd();
    void q11_xe();
}
namespace q12 {
    void q12_1a();
    void q12_4a();
    void q12_4b();
    void q12_4c();
    void q12_7a();  
    void q12_7b();
    void q12_xa();
}
namespace q13 {
    void q13_2();
    void q13_3a();
    void q13_3b();
    void q13_5();
    void q13_6();
    void q13_15();
    void q13_xa();
    void q13_xb();
    // void q13_xc();
}
namespace q14 {
    void q14_2();
    void q14_7();
    void q14_9();
    void q14_10();
    void q14_xa();
}
namespace q16 {
    void q16_x();
}
namespace q17 {
    void q17_4();
    void q17_x();
}
namespace q18 {
    void q18_1();
    void q18_x();
}
namespace q19 {
    void q19_x();
}
namespace q20 {
    void q20_x();
}
#endif