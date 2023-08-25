#include "userIO.h"
#include "random_MT.h"
#include <string_view>
#include <string>
#include <conio.h>

namespace RandString {
    namespace {
        using namespace std::literals::string_view_literals;
        constexpr std::string_view total_char_set = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-={}[|\\:;\"'<>,./?~`]"sv;
        enum charSetFlags {
            integer_flag,
            alpha_lower_flag,
            alpha_upper_flag,
            symbol_flag,
        };
        enum OutputRange {
            integer = 10,
            integer_ptr = 0,

            alpha_lower = 26,
            alpha_lower_ptr = 10, 

            alpha_upper = 26,
            alpha_upper_ptr = 36,

            symbol = 34,
            symbol_ptr = 62,
        };

        int get_len() {return userIn::get_input<int>();}
        int get_char_set() {
            using namespace std::literals::string_view_literals;
            int output{};
            do{
                output |= userIn::get_validated_YN("Would you like to include numbers [0-9]?                  (Y/N) "sv) << integer_flag;
                output |= userIn::get_validated_YN("Would you like to include lowercase letters [a-z]?        (Y/N) "sv) << alpha_lower_flag;
                output |= userIn::get_validated_YN("Would you like to include uppercase letters [A-Z]?        (Y/N) "sv) << alpha_upper_flag;
                output |= userIn::get_validated_YN("Would you like to include special characters ['!@#$...]?  (Y/N) "sv) << symbol_flag;

                if(output == 0) {
                    std::cout << "At least one character set must be selected\n";
                }
            } while (output == 0);

            return output;
        }
        int decode_char_set_range(int char_set) {
            int total_range{};
            if ((char_set & 0b1 << integer_flag) != 0)     {total_range += integer;}
            if ((char_set & 0b1 << alpha_lower_flag) != 0) {total_range += alpha_lower;}
            if ((char_set & 0b1 << alpha_upper_flag) != 0) {total_range += alpha_upper;}
            if ((char_set & 0b1 << symbol_flag) != 0)      {total_range += symbol;}

            return total_range;
        }
        int decode_char_set_char(int char_set, int index) {
            if (((char_set & 0b1 << integer_flag) != 0) && index < integer)         {return total_char_set[index + integer_ptr];}
            else if (((char_set & 0b1 << integer_flag) != 0) && index >= integer)           {index -= integer;}

            if (((char_set & 0b1 << alpha_lower_flag) != 0) && index < alpha_lower) {return total_char_set[index + alpha_lower_ptr];}
            else if (((char_set & 0b1 << alpha_lower_flag) != 0) && index >= alpha_lower)   {index -= alpha_lower;}

            if (((char_set & 0b1 << alpha_upper_flag) != 0) && index < alpha_upper) {return total_char_set[index + alpha_upper_ptr];}
            else if (((char_set & 0b1 << alpha_upper_flag) != 0) && index >= alpha_upper)   {index -= alpha_upper;}

            if (((char_set & 0b1 << symbol_flag) != 0) && index < symbol)           {return total_char_set[index + symbol_ptr];}
            else if (((char_set & 0b1 << symbol_flag) != 0) && index >= symbol)             {index -= symbol;}

            return 0;
        }
        char get_randchar(int char_set) {
            int total_range{decode_char_set_range(char_set)};
            int char_idx{Random::get_rand_int<int>(0, total_range - 1)};

            return decode_char_set_char(char_set, char_idx);
        }
        std::string generate_randstr(int str_len, int char_set) {
            std::string output{};

            for(int i = 0; i < str_len; i++) {
                output.push_back(get_randchar(char_set));
            }

            return output;
        }
        void print_char_set(int char_set) {
            using namespace std::literals::string_view_literals;

            if ((char_set & 0b1 << integer_flag) != 0)     {std::cout << "1234567890"sv;}
            if ((char_set & 0b1 << alpha_lower_flag) != 0) {std::cout << "abcdefghijklmnopqrstuvwxyz"sv;}
            if ((char_set & 0b1 << alpha_upper_flag) != 0) {std::cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZ"sv;}
            if ((char_set & 0b1 << symbol_flag) != 0)      {std::cout << "!@#$%^&*()_+-={}[|\\:;\"'<>,./?~`]"sv;}
            std::cout << '\n';
        }
    }

    char test() {
        return decode_char_set_char(0b1100, 26);
    }

    void run_randstr_generator() {
        using namespace std::literals::string_view_literals;
        std::cout << " _____                 _                    _____ _        _                _____                           _             \n"sv <<
                    "|  __ \\               | |                  / ____| |      (_)              / ____|                         | |            \n"sv <<
                    "| |__) |__ _ _ __   __| | ___  _ __ ___   | (___ | |_ _ __ _ _ __   __ _  | |  __  ___ _ __   ___ _ __ __ _| |_ ___  _ __ \n"sv <<
                    "|  _  // _` | '_ \\ / _` |/ _ \\| '_ ` _ \\   \\___ \\| __| '__| | '_ \\ / _` | | | |_ |/ _ \\ '_ \\ / _ \\ '__/ _` | __/ _ \\| '__|\n"sv <<
                    "| | \\ \\ (_| | | | | (_| | (_) | | | | | |  ____) | |_| |  | | | | | (_| | | |__| |  __/ | | |  __/ | | (_| | || (_) | |   \n"sv <<
                    "|_|  \\_\\__,_|_| |_|\\__,_|\\___/|_| |_| |_| |_____/ \\__|_|  |_|_| |_|\\__, |  \\_____|\\___|_| |_|\\___|_|  \\__,_|\\__\\___/|_|   \n"sv <<
                    "                                                                    __/ |                                                 \n"sv <<
                    "                                                                    |___/                                                 \n"sv <<
                    "\n                                                Press any key to continue                                                \n"sv;
        getch();

        bool get_user_input = true;
        int str_len{};
        int char_set{};

        while(true){
            if (get_user_input) {
                std::cout << "Enter the desired string length: "sv;
                str_len = get_len();

                std::cout << "Select the characters desired in the string: \n"sv;
                char_set = get_char_set();

                get_user_input = true;
            }

            std::string rand_str{generate_randstr(str_len, char_set)};
            std::cout << "\nChararcter set used: "sv;
            print_char_set(char_set);

            std::cout << "A " << str_len << " character string has been generated: "sv << rand_str << '\n';
            std::cout << "Size in bits: "sv << sizeof(rand_str)*8 << '\n';
            std::cout << "\nPress \"s\" to start over\nPress \"r\" to recreate string\nPress any other key to exit program\n"sv;

            switch (userIn::is_restart()) {
                case userIn::restart:
                    break;
                case userIn::recreate:
                    get_user_input = false;
                    break;
                default:
                    goto end;
                    break;
            }

        }
end:;
    }
}