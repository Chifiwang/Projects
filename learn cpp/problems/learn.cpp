#include ".\learn.h"
#include ".\constants.h"
#include ".\randomMT.h"
#include <iostream>
#include <cmath>
#include <numeric>
#include <string>
#include <string_view>
#include <bitset>
#include <cstdint>
#include <algorithm>
#include <cassert>
#include <array>
#include <numeric>
#include <algorithm>
#include <conio.h>
#include <deque>
#include <unordered_map>
#include <vector>
#include <initializer_list>
#include <stdexcept>

int get_int(std::string_view msg) {
    int x{};
    std::cout << msg;
    std::cin >> x;

    return x;
}
int get_int() {
    int x{};
    std::cin >> x;
    return x;
}
void print(std::string msg) {
    std::cout << msg;
}
void q1_11() {
    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;
    
    std::cout << "Double " << x << " is: " << 2*x << '\n';
    std::cout << "Triple " << x << " is: " << 3*x << '\n';
}
void q1_x() {
    int x{}, y{};

    std::cout << "Enter an integer: ";
    std::cin >> x;

    std::cout << "Enter another integer: ";
    std::cin >> y;

    std::cout << x << " + " << y << " is " << x + y << ".\n";
    std::cout << x << " - " << y << " is " << x - y << ".\n";
}
int q2_4a(int x) {
    return 2*x;
}
void q2_4b() {
    int x = get_int();
    std::cout << q2_4a(x);
}
int q2_7(int a, int b, int c, int d) {
    return a + b * c / d;
}
void q2_8() {
    using namespace std::string_view_literals;

    int x = get_int("Enter an integer: "sv);
    int y = get_int("Enter an integer: "sv);

    std::cout << x << " + " << y << " is " << x + y << "\n";
}
void q2_xa() {
    int x = get_int();
    int y = get_int();

    print(std::to_string(x + y));
}
void q4_3a() {
    std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
    std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";
}
bool q4_9a() {
    int x = get_int();
    // bool y = true;

    for(int i = sqrt(x); i > 1; i--) {
        if(x % i == 0) {
            // y = false;
            std::cout << "This number is not prime";
            return 0;
        }
    }

    std::cout << "This number is prime";
    return 1;
}
void q4_12() {
    char ch{};
    std::cout << "Enter a single character: ";
    std::cin >> ch;
    int n = ch;

    std::cout << "You entered \'" << ch << "\', which has ASCII code " << n << ".";
}
void q4_17() {
    using namespace std::string_view_literals;

    std::string name;
    int age{};

    std::cout << "Enter your full name: ";
    std::getline(std::cin >> std::ws, name);

    age = get_int("Enter your age: "sv);

    std::cout << "Your age + length of name is: " << age + static_cast<int>(name.length());
}
void q4_xa() {
    double x{}, y{}, ans{};

    std::cout << "Enter a double value: ";
    std::cin >> x;
    std::cout << "Enter a double value: ";
    std::cin >> y;

    char opp;
    std::cout << "Enter one of the following (+, -, *, /): ";
    std::cin >> opp;

    if (opp == '+') {
        ans = x + y;
    } else if (opp == '-') {
        ans = x - y;
    } else if (opp == '*') {
        ans = x * y;
    } else {
        ans = x / y;
    }

    std::cout << x << " " << opp << " " << y << " is " << ans;
}
void q4_xb() {
    using namespace std::string_view_literals;
    constexpr double G = 9.8;

    double h = static_cast<double>(get_int("Enter the height of the tower in meters: "sv));
    int t{};
    
    do {
        std::cout << "At " << t << " secocnds, the ball is at height: " << h - 0.5*G*t*t << " meters\n";
        t++;
    } while(h - 0.5*G*t*t > 0);

    std::cout << "At " << t << " secocnds, the ball is on the ground.";
}
bool q5_3b(int x) {
    return x % 2 == 0;
}
void q5_3a() {
    int x = get_int();
    std::cout << std::boolalpha;
    std::cout << q5_3b(x);
}
void qO_2a() {
    std::bitset<4> a {0b0001};
    std::cout << qO_2b(a) << '\n';

    std::bitset<4> b {0b1001};
    std::cout << qO_2b(b) << '\n';
}
std::bitset<4> qO_2b(std::bitset<4> bits) { //(bits<<1) | (bits>>3) is more effective
    return ((bits & static_cast<std::bitset<4>>(0b1000)) >> 3) | (bits << 1); 
}
void qO_3a() {
    [[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
    [[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
    [[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
    [[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
    [[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

    std::uint8_t myArticleFlags{ option_favorited };

    myArticleFlags |= option_viewed;
    myArticleFlags ^= option_favorited;

    std::cout << std::bitset<8>{ myArticleFlags } << '\n';
}
void qO_4() {
    uint8_t a = static_cast<uint8_t>(get_int());

    for(uint8_t i = 128; i > 0; i/=2) {
        std::cout << a/i;
        a = std::min(a, static_cast<uint8_t>(a - i));
    }
}
void q6_3() {
    int x = get_int();
    int y = get_int();
    if (x > y) {
        int tempx = y;
        int tempy = x;

        std::cout << tempx;
        std::cout << tempy;
    } else {//temp dies
        std::cout << x;
        std::cout << y;
    } 
}
void q6_xa() {
    std::cout << "How many students are in your class? ";
	int students{};
	std::cin >> students;


	if (students > constants::MAX_CLASS_SIZE)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class isn't too large";

}
int q6_xb1(int a) {
    static int n = 0;
    n += a;

    return n;
}
void q6_xb2() {
    std::cout << q6_xb1(4) << '\n'; // prints 4
    std::cout << q6_xb1(3) << '\n'; // prints 7
    std::cout << q6_xb1(2) << '\n'; // prints 9
    std::cout << q6_xb1(1) << '\n'; // prints 10
}
void q7_6() {
    int a = get_int();
    int b = get_int();
    char op;
    std::cin >> op;
    
    switch (op) {
    case '+':
        std::cout << a + b;
        break;
    case '-':
        std::cout << a - b;
        break;
    case '*':
        std::cout << a * b;
        break;
    case '/':
        std::cout << a / b;
        break;
    default:
        std::cerr << "Invalid operation";
        break;
    }
}
void q7_7a() {
    char ch = 'a';

    while (ch < 123) {
        std::cout << ch << ": " << (int) ch << '\n';
        ch++;
    }
}
void q7_7b() {
    int i{0};
    while (i < 5) {
        int j{5};
        while (j-i > 0) {
            std::cout << (j--) - i << ' ';
        }
        std::cout << '\n';
        i++;
    }
}
void q7_7c() {
    int i{0};
    while (i < 5) {
        int j{4};
        while (j > i) {
            std::cout << ' ' << ' ';
            --j;
        }

        int k{i + 1};
        while (k > 0) {
            std::cout << k-- << ' ';
        }
        std::cout << '\n';
        i++;
    }
}
void q7_10a() {
    for(int i = 0; i < 21; i += 2) {
        std::cout << i << '\n';
    }
}
void q7_10b() {
    int a = get_int();
    int x{};
    // std::cout << i*(i-1)/2;
    for(int i = 1; i <= a; i++) {
        x+=i;
    }
    std::cout << x;
}
void q7_10c(int a) {
    for(int i = 1; i <= a; i++) {
        int fpb = true;
        
        if (i % 3 == 0) {
            std::cout << "fizz";
            fpb = false;
        }
        if (i % 5 == 0) {
            std::cout << "buzz";
            fpb = false;
        }
        if (i % 7 == 0) {
            std::cout << "pop";
            fpb = false;
        }
        if(fpb) {
            std::cout << i;
        }
    
        std::cout << '\n';
    }
}
bool q7_xa1(int a) {
    if(a == 0 || a == 1) {
        return false;
    }

    for(int i = sqrt(a); i > 1; i--) {
        if(a % i == 0) {
            return false;
        }
    }

    return true;
}
void q7_xa2() {
    assert(!q7_xa1(0));
    assert(!q7_xa1(1));
    assert(q7_xa1(2));
    assert(q7_xa1(3));
    assert(!q7_xa1(4));
    assert(q7_xa1(5));
    assert(q7_xa1(7));
    assert(!q7_xa1(9));
    assert(q7_xa1(11));
    assert(q7_xa1(13));
    assert(!q7_xa1(15));
    assert(!q7_xa1(16));
    assert(q7_xa1(17));
    assert(q7_xa1(19));
    assert(q7_xa1(97));
    assert(!q7_xa1(99));
    assert(q7_xa1(13417));

    std::cout << "Success!\n";
}
void q7_xb() {
    bool go = true;
    while(go) {
        int g, ans{Random::get_rand<int>(1, 100)};
        std::cout << "Let's play a game. I'm thinking of a number" <<
                    " between 1 and 100. You have 7 tries to guess what it is.\n";
        
        for(int i = 0; i < 7; i++) {
            std::cout << "Guess #" << i + 1 << ": ";
            std::cin >> g;
            bool test = true;
            while(test) {
                if(g > 100 || g < 1 || std::cin.fail()) {
                    std::cout << "Guess #" << i + 1 << ": ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> g;
                } else {
                    test = false;
                }
            }

            if(ans < g) {
                std::cout << "Your guess is too high.\n";
                continue;
            } else if(ans > g) {
                std::cout << "Your guess is too low.\n";
                continue;
            } else {
                break;
            }
        }

        if(ans == g) {
            std::cout << "Correct! You win!\n";
        } else {
            std::cout << "Sorry, you lose. The correct number was " << ans <<".\n";
        }

        char c;
        bool test = true;
        while(test) {
            std::cout << "Would you like to play again (y/n)? ";
            std::cin >> c;

            switch(c) {
            case 'y':
                test = false;
                break;
            case 'n':
                go = false;
                test = false;
                break;
            default:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }
    }
    std::cout << "Thank you for playing.";
}
namespace q8_7{
    using PrintError = int;
    PrintError printdata() {
        return 0;
    }
}
namespace q8_xa {
    using Degrees = double;
    using Radians = double;

    Radians convertToRadians(Degrees degrees) {
        return degrees * constants::pi / 180;
    }

    void q8_xa() {
        std::cout << "Enter a number of degrees: ";
        Degrees degrees{};
        std::cin >> degrees;

        Radians radians { convertToRadians(degrees) };
        std::cout << degrees << " degrees is " << radians << " radians.\n";

    }
}
namespace q8_xb {
    template <typename T, typename U> auto add(T a, U b) {
        return a + b;
    }
    template <typename T, typename U> auto mult(T a, U b) {
        return a * b;
    }
    template <typename T, typename U> auto sub(T a, U b) {
        return a - b;
    }
    void q8_xb() {
        std::cout << add(2, 3) << '\n';
	    std::cout << add(1.2, 3.4) << '\n';
    	std::cout << mult(2, 3) << '\n';
	    std::cout << mult(1.2, 3) << '\n';
        std::cout << sub(3, 2) << '\n';
	    std::cout << sub(3.5, 2) << '\n';
	    std::cout << sub(4, 1.5) << '\n';
    }
}
namespace q9 {
    void sort2(int& x, int& y) {
        if(x > y) {
            int temp = x;
            x = y;
            y = temp;
        }
    }

    void q9_x() {
        int x = 7;
        int y = 5;
        sort2(x, y);
        std::cout << x << ' ' << y << '\n'; // should print 5 7

        sort2(x, y);
        std::cout << x << ' ' << y << '\n'; // should print 5 7
    }
}
namespace q10 {
    constexpr std::string_view getAnimalName(Animal a) {
        using namespace std::literals::string_view_literals;
        switch (a) {
            case Animal::pig:
                return "pig"sv;
            case Animal::cat:
                return "cat"sv;
            case Animal::chicken:
                return "chicken"sv;
            case Animal::dog:
                return "dog"sv;
            case Animal::duck:
                return "duck"sv;
            default:
                return "No Animal"sv;
        }
    }
    void printNumberofLegs(Animal a) {
        switch (a) {
            case Animal::pig:
            case Animal::cat:
            case Animal::dog:
                std::cout << 4;
                break;
            case Animal::chicken:
            case Animal::duck:
                std::cout << 2;
                break;
            default:
                std::cout << "No Animal";
                break;
        }
    }
    void q10_2() {Monster::MonsterType player = Monster::trolls;}
    void q10_3() {
        std::cout << "A " << getAnimalName(Animal::cat) << " has ";
        printNumberofLegs(Animal::cat);
        std::cout << " legs.\n";

        std::cout << "A " << getAnimalName(Animal::chicken) << " has ";
        printNumberofLegs(Animal::chicken);
        std::cout << " legs.\n";
    }
    void printData(Ad a) {
        std::cout << "Ads Watched:\t\t" << a.watched << '\n';
        std::cout << "% Clicked:\t\t" << a.clickThroughPercent*100 << "%\n";
        std::cout << "Average Earnings:\t$" << a.avgEarnings << '\n';
        std::cout << "Total Earnings:\t\t$" << a.avgEarnings*a.clickThroughPercent*a.watched << '\n';
    }
    void q10_6a() {
        Ad day {10, 0.1, 2};
        printData(day);
    }
    Fraction mult(Fraction x, Fraction y) {
        return {x.n*y.n, x.d*y.d};
    }
    void q10_6b() {
        using namespace std::literals::string_view_literals;
        Fraction a{get_int("Enter a value for the numerator: "sv), get_int("Enter a value for the denominator: "sv)};
        std::cout << '\n';
        Fraction b{get_int("Enter a value for the numerator: "sv), get_int("Enter a value for the denominator: "sv)};

        Fraction c{mult(a, b)};

        std::cout << "\nYour fractions multiplied together: "<< c.n << '/' << c.d;
    }
    void printMonster(MonsterStats m) {
        std::cout << "This " << m.type << " is named " << m.name <<" and has " << m.hp << " health.\n";
    }
    void q10_xa() {
        using namespace std::literals::string_view_literals;
        MonsterStats ogre{"Ogre"sv, "Trog"sv, 145};
        MonsterStats slime{"Slime"sv, "Blurp"sv, 23};

        printMonster(ogre);
        printMonster(slime);
    }
    template <typename T> void print(const Triad<T>& t) {
        std::cout << '[' << t.a << ", " << t.b << ", " << t.c << "]";
    }
    void q10_xb() {
        Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
        print(t1);

        Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
        print(t2);
    }
    void q10_y() {
        std::string str{ "I saw a red car yesterday." };

        str.replace(8, 3, "blue");

        std::cout << str << '\n'; // I saw a blue car yesterday.
    }
}
namespace q11 {
    double temp[365]{};
    void q11_2() {
        int legs[Animals::totalNumAnimals]{2, 4, 4, 4, 2, 0};
        std::cout << legs[Animals::elephant];
    }
    void q11_3a() {
        constexpr int arr[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
        // for(int i = 0; i < static_cast<int>(std::size(arr)); i++) {
        //     std::cout << arr[i];
        // }
        int n;
        while(true) {
            std::cout << "Enter a number between 1 and 9: ";
            std::cin >> n;

            if(!std::cin.fail()) {
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for(int i = 0; i < static_cast<int>(std::size(arr)); i++) {
            if (arr[i] == n) {
                std::cout << i;
            }
        }
    }
    void q11_3b() {
        constexpr int scores[]{ 84, 92, 76, 81, 56 };

        int maxScore{ 0 }; // Assume our largest score is 0 to start

        // now look for a larger score in the full array
        for (int student{ 0 }; student < static_cast<int>(std::size(scores)); ++student)
        {
            if (scores[student] > scores[maxScore])
            {
                maxScore = student;
            }
        }

        std::cout << "The best score was " << scores[maxScore] << '\n';
    }
    void q11_3c() {
        using namespace std::literals::string_view_literals;
        int div[7]{3, 5, 7, 11, 13, 17, 19};
        std::string_view out[7]{"fizz"sv, "buzz"sv, "pop"sv, "bang"sv, "jazz"sv, "pow"sv, "boom"sv};

        for(int i = 0; i < 150; i++) {
            bool isNotFizz = true;
            for(int j = 0; j < 7; j++) {

                if((i+1)%div[j] == 0) {
                    std::cout << out[j];
                    isNotFizz = false;
                } 
            } 
            if(isNotFizz) {
                std::cout << i + 1;
            }
            std::cout << '\n';
        }
    }

    int* select_sort(int *arr, int arr_size, bool order = false) {// false = fwd, true = rev
        for(int i = 0; i < arr_size; i++) {
            int *largestInd{arr + i};
            for(int j = i; j < arr_size; j++) {
                if((*(arr + j) < *(largestInd)) ^ order) {
                    largestInd = (arr + j);
                }
            }

            std::swap(*(arr + i), *(largestInd));
        }

        return arr;
    }

    int* bubble_sort(int* arr, int arr_size, bool order = false) {// false = fwd, true = rev
        // int j = 0;
        bool swapped = false;
        for(int j = 0; j < arr_size -1; j++) {
            for(int i = 0; i < arr_size - 1 - j; i++) {
                if(*(arr + i) > *(arr + i + 1) ^ order) {
                    swapped = true;
                    std::swap(*(arr + i), *(arr + i + 1));
                }
            }

            if(!swapped) {
                break;
            } swapped = false;
            // j++;
        }

        return arr;
    }

    void q11_4a() {
        int arr1[] {6, 3, 2, 9, 7, 1, 5, 4, 8};
        int arr2[] {6, 3, 2, 9, 7, 1, 5, 4, 8};
        // int *ptr[5]{&arr};
        enum SortOrder {
            forward, 
            reverse,
        };
        // select_sort(arr1, std::size(arr1), reverse);
        // for(auto i : arr1) {
        //     std::cout << i << ' ';
        // }

        bubble_sort(arr2, std::size(arr2), reverse);
        for(auto i : arr2) {
            std::cout << i << ' ';
        }

    }
    int* findValue(int* begin, int* end, int val) {
        for(int* i = begin; i != end; i++) {
            if(*i == val) {
                return i;
            }
        }

        return end;
    }

    void q11_8() {
        int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

        // Search for the first element with value 20.
        int* found{ findValue(std::begin(arr), std::end(arr), 20) };

        // If an element with value 20 was found, print it.
        if (found != std::end(arr))
        {
            std::cout << *found << '\n';
        }
    }
    void q11_10() {
        int n{};
        std::cin >> n;
        std::string *ptr{new std::string[n]};
        for(int i = 0; i < n; i++) {
            std::cin >> *(ptr + i);
        }

        std::sort(ptr, ptr + n);

        for(int i = 0; i < n; i++) {
            std::cout << *(ptr + i) << '\n';
        }

        delete[] ptr;
    }
    void q11_12() {
        using namespace std::literals::string_view_literals;
        const std::string_view names[]{"alex"sv, "betty"sv, "caroline"sv, "dave"sv, "emily"sv, "fred"sv, "greg"sv, "holly"sv};

        std::string in;
        std::cin >> in;

        std::string_view view{in};


        bool isFound = false;
        for(std::string_view name: names) {
            if(name == view) {
                std::cout << name;
                isFound = true;
            }
        }

        if(isFound) {
            std::cout << "was found";
        }
        else {
            std::cout << "was not found";
        }
    }
    
    int count(std::array<int, 3> arr) {
        return std::reduce(std::begin(arr), std::end(arr));
    }

    void q11_xa() {
        enum Items {
            health_pots, 
            torches, 
            arrows, 
        };

        std::array<int, 3> inv {2, 5, 10};

        std::cout << count(inv) << ' ' << inv[1];
    }

    struct Student {
                std::string_view name;
                int grade;
    };

    int partition(std::vector<Student> &s, int low, int high) {
        int i{low - 1};

        for(int j = low; j < high; j++) {
            if(s[j].grade < s[high].grade) {
                std::swap(s[++i], s[j]);
            }
        }
        std::swap(s[++i], s[high]);
        return i;
    }

    void q_sort(std::vector<Student> &s, int low, int high) {
        if (low < high) {
            int p = partition(s, low, high);
            q_sort(s, low, p-1);
            q_sort(s, p+1, high);
        }
    }

    bool comp(Student a, Student b) {
        return a.grade > b.grade;
    }

    void q11_xb() {

        using namespace std::literals::string_view_literals;
        int n {get_int("How many students are there? "sv)};
        std::vector<Student> students;

        for(int i = 0; i < n; i++) {
            std::string name;
            std::cin >> name;
            int grade;
            std::cin >> grade;

            std::string_view sv = name;
            Student temp{sv, grade};
            students.push_back(temp);
        }

        std::sort(students.begin(), students.end(), comp);
        for(int i = 0; i < 5; i++) {
            std::cout << students[i].grade << ' ';
        }
    }
    void intswap(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }
    void q11_xc() {
        int x = 1;
        int y = 2;
        intswap(x, y);
        std::cout << x << y;
    }
    void pcstr(const char *s) {
        char i = 0;
        while(*s != '\0') {
            std::cout << *(s++);
        }
    } 

    void q11_xd() {
        char s[] = "test";
        // std::cout <<s.size();
        pcstr(s);
    }

    //BlackJack starts Here

    enum cardrank {
        two = 2,
        three, 
        four, 
        five, 
        six,
        seven, 
        eight, 
        nine, 
        ten, 
        jack, 
        queen, 
        king, 
        ace ,
    };

    enum cardsuit {
        clubs, 
        diamonds, 
        hearts, 
        spades,
    };

    struct Card {
        int rank;
        int suit;
    };

    void printCard(const Card c) {
        switch (c.rank)
        {
        case 10:
            std::cout << 'T';
            break;
        case 11:
            std::cout << 'J';
            break;
        case 12:
            std::cout << 'Q';
            break;
        case 13:
            std::cout << 'K';
            break;
        case 14:
            std::cout << 'A';
            break;
        default:
            std::cout << c.rank;
            break;
        }

        switch (c.suit)
        {
        case 0:
            std::cout << 'C';
            break;
        case 1:
            std::cout << 'D';
            break;
        case 2:
            std::cout << 'H';
            break;
        case 3:
            std::cout << 'S';
        default:
            break;
        }
    }

    void createDeck(std::array<Card, 52> &deck) {
        int i{};
        for(int s = clubs; s <= spades; s++) {
            for(int r = two; r <= ace; r++) {
                deck[i++] = {r, s};
            }
        }
    }
    
    void shuffle(std::array<Card, 52> &deck) {
        std::shuffle(deck.begin(), deck.end(), Random::mt);
    }

    int cardValue(Card c) {
        switch (c.rank)
        {
        case 11:
        case 12:
        case 13:
            return 10;
            break;
        case 14:
            return 11;
            break;
        default:
            return c.rank;
            break;
        }

    }

    struct Deck {
        std::deque<Card> deck;

        Deck() {
            std::array<Card, 52> d;
            createDeck(d);
            shuffle(d);
            
            for(Card c : d) {
                deck.push_back(c);
            }
        }
    };

    struct Hand {
        std::deque<Card> cards;
    };

    struct Player {
        Hand hand;
        Card hidden;
        int handVal{};

        Player(Deck &d, int n);
        void draw(Deck &d, int n) {
            for(int i = 0; i < n; i++) {
                hand.cards.push_back(d.deck.back());
                handVal += (cardValue(d.deck.back()) == 11 && (11 + handVal) > 21) ? 1 : 11;
                d.deck.pop_back();
            }
        }

        void hideCard() {
            hidden = hand.cards.back();
            // handVal -= cardValue(hidden);
            hand.cards.pop_back();
        }      
    }; Player::Player(Deck &d, int n) {
        draw(d, n);
    }

    void printHand(Hand h) {
        for(Card c : h.cards) {
            printCard(c);
            std::cout << ' ';
        }
    }

    void printInfo(Player c, Player p) {
        std::cout << "Dealer Hand: ";
        printHand(c.hand);
        std::cout << "\n Value: " << c.handVal -  cardValue(c.hidden) << '+';

        std::cout << "\n\nPlayer Hand: ";
        printHand(p.hand);
        std::cout << "\nValue: " << p.handVal;
    }

    

    void q11_xe() {
        Deck d;
        Player c(d, 2);
        c.hideCard();
        Player p(d, 2);
        char ans;
        
        while(true) {
            printInfo(c, p);
            std::cout << "\nWould you like to hit or stand? (h/s) ";
            std::cin >> ans;

            if(ans == 'h') {
                p.draw(d, 1);
                if (p.handVal > 21) {
                    std::cout << "you lose";
                    break;
                }
            } else if (ans == 's') {
                if (p.handVal < c.handVal) {
                    std::cout << "you lose";
                    break;
                } else {
                    std::cout << "you win";
                    break;
                }
            }

            if(c.handVal < 17) {
                c.draw(d, 1);
                if(c.handVal > 21) {
                    std::cout << "you win";
                    break;
                }
            }
        }
    }
}

namespace q12 {
    int add(int a, int b) {return a + b;}
    int subtract(int a, int b) {return a - b;}
    int multiply(int a, int b) {return a * b;}
    int divide(int a, int b) {return a / b;}
    using ArithFunct = int (*)(int, int);
    ArithFunct getArithFunct(char opp) {
        switch (opp) {
            case '+':
                return add;
                break;
            case '-':
                return subtract;
                break;
            case '*':
                return multiply;
                break;
            case '/':
                return divide;
                break;
        }
        return add;
    }
    void q12_1a() {
        int a, b;
        char opp;

        std::cin >> a >> b >> opp;
        std::cout << getArithFunct(opp)(a, b);
    }

    int fact(int n) {
        if(n > 2) {
            return n*fact(n-1);
        }
        return n;
    }

    int sumDig(int n) {
        if(n > 9) {
            return n%10 + sumDig(n/10);
        }
        return n;
    }

    void printbin(unsigned int n) {
        // if(n < 0) {
        //     n = static_cast<int64_t>(static_cast<uint32_t>(n));
        // }
        // std::cout << "here";
        if (n > 0b1) {
            printbin(n / 2);
        }
        std::cout << (n & 0b1);
    }

    void q12_4a() {
        std::cout << fact(7);
    }
    void q12_4b() {
        std::cout << sumDig(93427);
    }
    void q12_4c() {
        printbin(-15);//1111
    }

    struct Student {
        std::string name;
        int pts;
    };

    void q12_7a() {
        std::array<Student, 8> arr{
        { { "Albert", 3 },
            { "Ben", 5 },
            { "Christine", 2 },
            { "Dan", 8 }, // Dan has the most points (8).
            { "Enchilada", 4 },
            { "Francis", 1 },
            { "Greg", 3 },
            { "Hagrid", 5 } }
        };

        std::cout << std::max_element(
            arr.begin(), arr.end(), 
            [](Student a, Student b) -> bool {
                return (a.pts < b.pts);
            })->name;
    }

    struct Season
    {
    std::string_view name{};
    double averageTemperature{};
    };

    void q12_7b() {
        std::array<Season, 4> seasons{
            { { "Spring", 285.0 },
            { "Summer", 296.0 },
            { "Fall", 288.0 },
            { "Winter", 263.0 } }
        };

        std::sort(
            seasons.begin(), seasons.end(), 
            [](const Season &a, const Season &b) {
                return a.averageTemperature < b.averageTemperature;
            });

        for (const auto& season : seasons)
        {
            std::cout << season.name << '\n';
        }
    }

    void q12_8() {
        int a, b;
        std::cin >> a >> b;
        std::unordered_map<int, bool> arr{};
        for(int i = 0; i < b; i++) {
            arr[(a*(a++)) << 2] = true;
        }


        int ans;
        for(int i = 0; i < b; i++) {
            std::cin >> ans;
            if(arr[ans]) {
                std::cout << "yes";
                arr[ans] = false;
            } else {
                std::cout << "no";
                for(int j = ans - 4; j < ans + 5; j++) {
                    if(arr[j]) {
                        std::cout << j;
                    }
                }
            }
        }

    }

    // double max(double a, double b);
    // void swap(int &a, int &b);
    // auto& getLargestEle(auto *a, int len);

    // int it_binSearch(int *beg, int *end,  int val) {
    //     int* i = beg, j = end;

    //     for(int i = 0; i < end - beg; i++) {
    //         if((beg + (*i + *j) >> 2 + 1) == val) {
    //             return ((*i + *j) >> 2) + 1; 
    //         } else if ((beg + ((*i + *j)) >> 2 + 1) > val) {
    //             j = ((*i + *j) >> 2) + 1;
    //         } else {
    //             i = ((*i + *j) >> 2) + 1;
    //         }

    //         if (*i > *j) {
    //             return -1;
    //         }
    //     }

    //     return -1;
    // }

    int* rec_binSearch(int *beg, int *end, int val) {
        int len = end - beg;
        int mid = ((len) >> 1);
        if (val < *beg || val > *end) return nullptr;

        if(*(beg + mid) == val) {
            return beg + mid;
        }

        if(*(beg + mid) > val) {
            return rec_binSearch(beg, beg + mid, val);
        } else {
            return rec_binSearch(beg + mid + 1, end, val);
        }


    }

    int* it_binSearch(int *beg, int *end, int val) {
        while(true) {
            int len = end - beg;
            int mid = len >> 1;

            if (val < *beg || val > *end) return nullptr;
            if(*(beg + mid) == val) {
                return beg + mid;
            }

            if(*(beg + mid) > val) {
                end = beg + mid;
            } else {
                beg = beg + mid + 1;
            }
        }
        return nullptr;
    }

    void q12_xa() {
        int arr[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

        std::cout << *it_binSearch(arr, arr + 14, 36);
    }
}
namespace q13 {
    class IntPair {
        int m_a{}, m_b{};

    public:
        IntPair(int a, int b) {
            m_a = a;
            m_b = b;
        }
        IntPair() {}
        void set(int a, int b) {
            m_a = a;
            m_b = b;
        }
        void print() {
            std::cout << m_a << ' ' << m_b;
        }
    };
    void q13_2() {
        IntPair p1;
        p1.set(1, 1); // set p1 values to (1, 1)

        IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

        p1.print();
        p2.print();
    }
    class Vector3d;


    class Point3D {
        // friend class Vector3d;
        double m_x{};
        double m_y{};
        double m_z{};

    public: 
        Point3D() {}
        Point3D(double x, double y, double z) {set(x, y, z);}
        void set(double x, double y, double z) {
            m_x = x;
            m_y = y;
            m_z = z;
        }
        bool isEqual(Point3D p2) {
            return m_x == p2.m_x && m_y == p2.m_y && m_z == p2.m_z;
        }
        void print() {
            std::cout << '<' << m_x << ", " << m_y << ", " << m_z << '>';
        }
        void add(Vector3d v);
    };

    class Vector3d
    {
        
        // friend class Point3D;
    private:
        double m_x{};
        double m_y{};
        double m_z{};

    public:
        friend void Point3D::add(Vector3d v);
        
        Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
            : m_x{x}, m_y{y}, m_z{z}
        {

        }

        void print() const
        {
            std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
        }
    }; void Point3D::add(Vector3d v) {
            m_x += v.m_x;
            m_y += v.m_y;
            m_z += v.m_z;
        }
    void q13_3a() {
        Point3D point1;
        point1.set(1, 2, 3);

        Point3D point2;
        point2.set(1, 2, 3);

        if (point1.isEqual(point2))
        {
            std::cout << "point1 and point2 are equal\n";
        }
        else
        {
            std::cout << "point1 and point2 are not equal\n";
        }

        Point3D point3;
        point3.set(3, 4, 5);

        if (point1.isEqual(point3))
        {
            std::cout << "point1 and point3 are equal\n";
        }
        else
        {
            std::cout << "point1 and point3 are not equal\n";
        }

        // return 0;
    }
    class Stack {
        int arr[10]{};
        int size {};

    public:
        Stack() {};
        void reset() {
            for(int i : arr) {
                i = 0;
            }
            size = 0;
        }
        void push(int x) {
            // static_assert(size < 9 );
            arr[size++] = x;
        }
        void pop() {
            arr[--size] = 0;
        }
        void print() {
            std::cout << "( ";
            for(int i = 0; i < size; i++) {
                std::cout << arr[i] << ' ';
            }
            std::cout << ")\n";
        }
    };

    void q13_3b() {
        Stack stack;
        stack.print();

        stack.push(5);
        stack.push(3);
        stack.push(8);
        stack.print();

        stack.pop();
        stack.print();

        stack.pop();
        stack.pop();

        stack.print();
    }
    class Ball {
    public:
        // Ball() = default;
        Ball(std::string colour = "Black", double radius = 10.0) {
            m_colour = colour;
            m_radius = radius;
        }
        Ball(double radius) {
            m_radius = radius;
        }
        void print() {
            std::cout << "colour: " << m_colour << ", radius: " << m_radius << std::endl;
        }
    private:
        std::string m_colour {"Black"};
        double m_radius{10};
    };

    void q13_5() {
        Ball def{};
        def.print();

        Ball blue{ "blue" };
        blue.print();

        Ball twenty{ 20.0 };
        twenty.print();

        Ball blueTwenty{ "blue", 20.0 };
        blueTwenty.print();
    }
    class RGBA {
    private:
        std::uint8_t m_red{};
        std::uint8_t m_green{};
        std::uint8_t m_blue{};
        std::uint8_t m_alpha{};
    public:
        RGBA(std::uint8_t r = 0, std::uint8_t g = 0, std::uint8_t b = 0, std::uint8_t a = 255) 
            : m_red{r}, m_green{g}, m_blue{b}, m_alpha{a} {};
        void print() {
            std::cout 
                << "( " << static_cast<int>(m_red) 
                << ", " << static_cast<int>(m_green) 
                << ", " << static_cast<int>(m_blue) 
                << ", " << static_cast<int>(m_alpha) << " )\n";
        }

    };
    void q13_6() {
        RGBA teal{ 0, 127, 127 };
	    teal.print();
    }
    void q13_15() {
        Point3D p{1.0, 2.0, 3.0};
        Vector3d v{2.0, 2.0, -3.0};

        p.print();
        p.add(v);
        p.print();
    }
    class Point2d {
        double m_x;
        double m_y;

    public:
        Point2d(double x = 0.0, double y = 0.0) : m_x{x}, m_y{y} {}
        void print() {std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";}
        friend double distanceFrom(Point2d p1, Point2d p2);
    };
    double distanceFrom(Point2d p1, Point2d p2) {
        return std::sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y));
    }

    void q13_xa() {
        Point2d first{};
        Point2d second{ 3.0, 4.0 };
        first.print();
        second.print();
        std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
    }
    class Monster {
    public:
        enum Type {
            Dragon, 
            Goblin, 
            Ogre, 
            Orc, 
            Skeleton, 
            Troll, 
            Vampire, 
            Zombie,    
            max_monster_types
        };
    private:
        Type m_type{};
        std::string m_name{};
        std::string m_roar{};
        int m_hp{};

    public:

        Monster(Type t, std::string n, std::string r, int hp) 
            : m_type{t}, m_name{n}, m_roar{r}, m_hp{hp}{}
        const std::string printType() {
            switch (m_type)
            {
            case Dragon:
                return "Dragon";
            case Goblin:
                return "Goblin";
            case Ogre:
                return "Ogre";
            case Orc:
                return "Orc";
            case Skeleton:
                return "Skeleton";
            case Troll:
                return "Troll";
            case Vampire:
                return "Vampire";
            case Zombie:
                return "Zombie";
            
            default:
                return "Error";
            }
        }
        void print() {
            std::cout << m_name << " the " << printType() << " has " << m_hp << " hit points and says " << m_roar;
        }
    };

    namespace MonsterGenerator {
        static std::string names[] {"a", "b", "c", "d", "e", "f"};
        static std::string roars[] {"1", "2", "3", "4", "5", "6"};
        Monster generate() {

            return { 
                static_cast<Monster::Type>(Random::get_rand<int>(0, Monster::max_monster_types - 1)) 
                , names[Random::get_rand<int>(0, 5)]
                , roars[Random::get_rand<int>(0, 5)]
                , Random::get_rand<int>(1, 100) 
                };
        }
    }

    void q13_xb() {
        MonsterGenerator::generate().print();
    }
}

namespace q14 {
    class Fraction {
    private:
        int m_num{};
        int m_den{};

    public:
        Fraction(int num = 0, int den = 1) : m_num{num}, m_den{den}{}
        friend Fraction operator+(Fraction a, Fraction b);
        friend Fraction operator*(Fraction a, Fraction b);
        friend Fraction operator*(Fraction a, int b);
        friend Fraction operator*(int a, Fraction b);
        friend std::ostream& operator<<(std::ostream& out, const Fraction f);
        friend std::istream& operator>>(std::istream& in, Fraction &f);
        friend bool operator== (Fraction a, Fraction b);
        friend bool operator!= (Fraction a, Fraction b);
        friend bool operator>= (Fraction a, Fraction b);
        friend bool operator<= (Fraction a, Fraction b);
        friend bool operator> (Fraction a, Fraction b);
        friend bool operator< (Fraction a, Fraction b);

        void print(){std::cout << m_num << '/' << m_den << '\n';}
        Fraction reduce() {return Fraction{m_num/std::gcd(m_den, m_num), m_den/std::gcd(m_den, m_num)};}
    };
    Fraction operator+(Fraction a, Fraction b) {
        return Fraction{a.m_num + b.m_num, a.m_den + b.m_den};
    }
    Fraction operator*(Fraction a, Fraction b) {return Fraction{a.m_num*b.m_num, a.m_den*b.m_den}.reduce();}
    Fraction operator*(Fraction a, int b) {return Fraction{a.m_num*b, a.m_den}.reduce();}
    Fraction operator*(int a, Fraction b) {return Fraction{b.m_num*a, b.m_den}.reduce();}
    std::ostream& operator<<(std::ostream& out, const Fraction f) {return out << f.m_num << '/' << f.m_den;}
    std::istream& operator>>(std::istream& in, Fraction &f) {
        in >> f.m_num;
        in.ignore();
        in >> f.m_den; 
        return in;
    }
    bool operator== (Fraction a, Fraction b) {
        return (a.reduce().m_num == b.reduce().m_num) && (a.reduce().m_den == b.reduce().m_den);
    }
    bool operator!= (Fraction a, Fraction b) {return !operator==(a, b);}
    bool operator>= (Fraction a, Fraction b) {return operator>(a, b) || operator==(a, b);}
    bool operator<= (Fraction a, Fraction b) {return operator<(a, b) || operator==(a, b);}
    bool operator> (Fraction a, Fraction b) {return {a.m_num/static_cast<double>(a.m_den) > b.m_num/static_cast<double>(b.m_den)};}
    bool operator< (Fraction a, Fraction b) {return operator>(b, a);}

    void q14_2() {
        Fraction f1{ 3, 2 };
        Fraction f2{ 5, 8 };

        std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
        std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
        std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
        std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
        std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
        std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
    }
    class Car {
    private:
        std::string m_make;
        std::string m_model;

    public:
        Car(std::string_view make, std::string_view model)
            : m_make{ make }, m_model{ model }{}

        friend bool operator== (const Car& c1, const Car& c2);
        friend bool operator!= (const Car& c1, const Car& c2);
        friend std::ostream& operator<< (std::ostream& out, const Car &c);
        friend bool operator> (const Car& c1, const Car& c2);
        friend bool operator< (const Car& c1, const Car& c2);
    };

    bool operator== (const Car& c1, const Car& c2) {
        return (c1.m_make == c2.m_make &&
                c1.m_model == c2.m_model);
    }

    bool operator!= (const Car& c1, const Car& c2) {
        return (c1.m_make != c2.m_make ||
                c1.m_model != c2.m_model);
    }

    bool operator> (const Car& c1, const Car& c2) {
        return (c1.m_make > c2.m_make) || (c1.m_model > c2.m_model);
    }
    bool operator< (const Car& c1, const Car& c2) {
        return operator>(c2, c1);
    }


    std::ostream& operator<< (std::ostream &out, const Car &c) {
        return (out << '(' << c.m_make << ", " << c.m_model << ')');
    }

    void q14_7() {
        std::vector<Car> cars{
            { "Toyota", "Corolla" },
            { "Honda", "Accord" },
            { "Toyota", "Camry" },
            { "Honda", "Civic" }
        };

        std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

        for (const auto& car : cars)
            std::cout << car << '\n'; // requires an overloaded operator<<
    }

    struct StudentGrade {
        std::string name;
        char grade;
    };

    class Map {
        std::vector<StudentGrade> m_map{};

    public:
        Map() = default;
        Map(std::vector<StudentGrade> m) : m_map{m}{}

        char& operator[] (std::string key) {
            auto temp{std::find_if(m_map.begin(), m_map.end(), 
            [&](const auto &student) {
                return student.name == key;
            })};
            if(temp != m_map.end()) {
                return temp->grade;
            } else {
                m_map.push_back({key, '\0'});
                return m_map.back().grade;
            }
        }
    };

    void q14_9() {
        Map grades{};

        grades["Joe"] = 'A';
        grades["Frank"] = 'B';

        std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
        std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
    }

    class MyString {
        std::string m_string;
    public:
        MyString(std::string s) : m_string{s}{}
        friend std::ostream& operator<< (std::ostream& out, MyString s);
        std::string operator() (int i, int len) {
            return m_string.substr(i, len);
        }
        std::string_view substr(int i, int len) {
            std::string_view temp = m_string;
            temp.remove_prefix(i);
            temp.remove_suffix(temp.size() - len);
            return temp;
        }
    };
    std::ostream& operator<< (std::ostream& out, MyString s) {
        return (out << s.m_string);
    }

    void q14_10() {
        MyString s { "Hello, world!" };
        std::cout << s.substr(7, 5) << '\n'; // start at index 7 and return 5 characters
    }

    class Point {
        int m_x{};
        int m_y{};
        int m_z{};

    public:
        Point(int x = 0, int y = 0, int z = 0) : m_x{x}, m_y{y}, m_z{z}{};
        Point operator-() {return Point{-m_x, -m_y, -m_z};}
        Point operator=(int a) {return Point{a};}
        friend Point operator+(Point a, Point b);
        friend std::ostream& operator<<(std::ostream &out, Point p);
    };
    Point operator+(Point a, Point b) {return Point{a.m_x + b.m_x, a.m_y + b.m_y, a.m_z + b.m_z};}
    std::ostream& operator<<(std::ostream &out, Point p) {return out << '(' << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';}

    class Average {
        double m_total{};
        int m_amount{};
        Average(double a, int b) : m_total{a}, m_amount{b}{}
    public:
        // Average() = default;
        Average(double a = 0) : m_total{a}, m_amount{(a != 0) ? 1 : 0}{};
        Average(const Average &a) : m_total{a.m_total}, m_amount{a.m_amount}{}
        Average &operator+=(double a) {m_total += a; m_amount++; return *this;}
        friend std::ostream& operator<<(std::ostream &out, const Average &avg);
    }; std::ostream& operator<<(std::ostream &out, const Average &avg) {
        // std::cout << (avg.m_total/avg.m_amount);
        return (out << (avg.m_total/avg.m_amount));}

    void q14_xa() {
        Average avg{};
        // std::cout << avg << '\n'; // 4 / 1 = 4
        avg += 4;
        std::cout << avg << '\n'; // 4 / 1 = 4

        avg += 8;
        std::cout << avg << '\n'; // (4 + 8) / 2 = 6

        avg += 24;
        std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

        avg += -10;
        std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

        (avg += 6) += 10; // 2 calls chained together
        std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

        Average copy{ avg };
        std::cout << copy << '\n';
    }
}
namespace q16 {
    class IntArray
    {
    private:
        int m_length{};
        int* m_data{};

    public:
        IntArray() = default;

        IntArray(int length)
            : m_length{ length }
            , m_data{ new int[static_cast<std::size_t>(length)] {} }
        {

        }

        IntArray(std::initializer_list<int> list) // allow IntArray to be initialized via list initialization
            : IntArray(static_cast<int>(list.size())) // use delegating constructor to set up initial array
        {
            // Now initialize our array from the list
            int count{ 0 };
            for (auto element : list)
            {
                m_data[count] = element;
                ++count;
            }
        }

        ~IntArray()
        {
            delete[] m_data;
        }

        IntArray operator=(std::initializer_list<int> list) {
            delete[] m_data;
            m_length = list.size();
            m_data = new int[static_cast<size_t>(m_length)]{};
            int count = 0;
            for(const auto i : list) {
                m_data[count] = i;
                ++count;
            }

            // for(int i = 0; i < m_length; i++) {
            //     m_data[i] = list.;
            // }

            return *this;
        }

    //	IntArray(const IntArray&) = delete; // to avoid shallow copies
    //	IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

        int& operator[](int index)
        {
            assert(index >= 0 && index < m_length);
            return m_data[index];
        }

        int getLength() const { return m_length; }
    };

    void q16_x() {
        IntArray array { 5, 4, 3, 2, 1 }; // initializer list
        for (int count{ 0 }; count < array.getLength(); ++count)
            std::cout << array[count] << ' ';

        std::cout << '\n';

        array = { 1, 3, 5, 7, 9, 11 };

        for (int count{ 0 }; count < array.getLength(); ++count)
            std::cout << array[count] << ' ';

        std::cout << '\n';
    }

}
namespace q17 {
    class Fruit {
        std::string name{};
        std::string colour{};
    public:
        Fruit(std::string n, std::string c) : name{n}, colour{c}{}
        std::string getName() {
            return name;
        }
        std::string getColour() {
            return colour;
        }
    };

    class Apple : public Fruit {
        double fibre{};
    public:
        Apple(std::string c) : Fruit{"apple", c}{}
        Apple(std:: string n, std::string c, double f = 0) : Fruit{n, c}, fibre{f}{}
        double getFibre() {
            return fibre;
        }
        friend std::ostream& operator<<(std::ostream &out, Apple a);
    };

    std::ostream& operator<<(std::ostream &out, Apple a) {
        return (out << "Apple(" << a.getName() <<", " << a.getColour() << ", " << a.getFibre() << ")");
    }

    class Banana : public Fruit {
    public:
        Banana() : Fruit{"banana", "yellow"}{}
        Banana(std::string n, std::string c) : Fruit{n, c}{}
        friend std::ostream& operator<<(std::ostream &out, Banana b);
    };

    std::ostream& operator<<(std::ostream &out, Banana b) {
            return out << "Banana(" << b.getName() <<", " << b.getColour() << ")";
    }

    class GrannySmith : public Apple {
    public:
        GrannySmith() : Apple{"granny smith", "green"}{}
    };

    void q17_4() {
        const Apple a{ "Red delicious", "red", 4.2 };
        std::cout << a << '\n';

        const Banana b{ "Cavendish", "yellow" };
        std::cout << b << '\n';
    }

}

namespace q18 {
    class Animal
    {
    protected:
        // using std::literals::string_view_literals;
        std::string m_name;
        std::string m_speak;

        // We're making this constructor protected because
        // we don't want people creating Animal objects directly,
        // but we still want derived classes to be able to use it.
        Animal(std::string_view name, std::string_view s = "???")
            : m_name{ name }, m_speak{s}
        {
        }

        // To prevent slicing (covered later)
        Animal(const Animal&) = default;
        Animal& operator=(const Animal&) = default;

    public:
        std::string_view getName() const { return m_name; }
        std::string_view speak() const { return m_speak; }
    };

    class Cat: public Animal
    {
    public:
        Cat(std::string_view name)
            : Animal{ name , speak()}
        {
        }

        std::string_view speak() const { return "Meow"; }
    };

    class Dog: public Animal
    {
    public:
        Dog(std::string_view name)
            : Animal{ name , speak()}
        {
        }
        std::string_view speak() const { return "Woof"; }
    };
    void q18_1() {
        const Cat fred{ "Fred" };
        const Cat misty{ "Misty" };
        const Cat zeke{ "Zeke" };

        const Dog garbo{ "Garbo" };
        const Dog pooky{ "Pooky" };
        const Dog truffle{ "Truffle" };

        // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
        // const auto animals{ std::to_array<const Animal*>({ &fred, &garbo, &misty, &pooky, &truffle, &zeke }) };

        // Before C++20, with the array size being explicitly specified
        const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

        for (const auto animal : animals)
        {
            std::cout << animal->getName() << " says " << animal->speak() << '\n';
        }
    }
    class Point {
    private:
        int m_x{};
        int m_y{};

    public:
        Point(int x, int y)
            : m_x{ x }, m_y{ y }
        {

        }

        friend std::ostream& operator<<(std::ostream& out, const Point& p)
        {
            return out << "Point(" << p.m_x << ", " << p.m_y << ')';
        }
    };

    class Shape {
    public:
        Shape() = default;
        virtual ~Shape() = default;
        virtual std::ostream& print(std::ostream& out) const = 0;
        friend std::ostream& operator<<(std::ostream& out, const Shape& s)
        {
            return s.print(out);
        }
    };
    class Triangle : public Shape{
        Point m_1;
        Point m_2;
        Point m_3;
    public:
        Triangle(Point a, Point b, Point c) : m_1{a}, m_2{b}, m_3{c}{}
        std::ostream& print(std::ostream& out) const override {
            return out << "Triangle(" << m_1 << ", " << m_2 << ", " << m_3<< ")";
        }
    };
    class Circle : public Shape{
        int m_r;
        Point m_c;
    public:
        Circle(Point c, int r) : m_c{c}, m_r{r}{}
        int getRadius() {
            return m_r;
        }
        std::ostream& print(std::ostream& out) const override {
            return out << "Circle(" << m_c << ", radius " << m_r<< ")";
        }
    };

    int getLargestRadius(std::vector<Shape*> v) {
        int max{0};
        for(auto * s: v) {
            Circle* temp{dynamic_cast<Circle*>(s)};
            if(temp) {
                max = std::max(temp -> getRadius(), max);
            }
        }
        return max;
    }

    void q18_x() {
        std::vector<Shape*> v{
            new Circle{Point{ 1, 2 }, 7},
            new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
            new Circle{Point{ 7, 8 }, 3}
        };

        for(auto* s : v) {
            std::cout << *s << '\n';
        }

        std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

        // delete each element in the vector here
        for(auto * s : v) {
            delete s;
        }
    }
}
namespace q19 {
    template <typename T>
    class Pair1 {
        T m_1;
        T m_2;
    public:
        Pair1(T a, T b) : m_1{a}, m_2{b}{}
        T first() const {return m_1;}
        T second() const {return m_2;}
    };

    template <typename T, typename U>
    class Pair {
        T m_t;
        U m_u;
    public:
        Pair(T a, U b) : m_t{a}, m_u{b}{}
        T first() const {return m_t;}
        U second() const {return m_u;}
    };

    template <typename U>
    class StringValuePair : public Pair<std::string, U> {
    public:
        StringValuePair(std::string str, U u) : Pair<std::string, U>{str, u}{}
    };

    void q19_x() {
        // Pair1<int> p1 { 5, 8 };
        // std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        // const Pair1<double> p2 { 2.3, 4.5 };
        // std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

        Pair<int, double> p1 { 5, 6.7 };
        std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        const Pair<double, int> p2 { 2.3, 4 };
        std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

        StringValuePair<int> svp { "Hello", 5 };
        std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';    
    }
}
namespace q20 {
    class Fraction {
        int m_num;
        int m_den;

    public:
        Fraction(int n = 0, int d = 1) : m_num{n}, m_den{d}{
            if(d == 0) {
                throw std::runtime_error("Invalid denominator");
            }
        }
    };

    void q20_x() {
        int n, d;
        try {
            std::cin >> n >> d;
            Fraction f{n, d};
        } catch (std::runtime_error rte) {
            std::cout << rte.what();
        }
    }
}