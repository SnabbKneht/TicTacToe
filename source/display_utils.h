#ifndef DISPLAY_UTILS_H
#define DISPLAY_UTILS_H
#include <cstdlib>

enum class symbol;
class board;

class display_utils
{
    public:
        static void print_board(const board &);
        static void clear_console() { system("cls"); }

    private:
        static void print_top_bar();
        static void print_middle_bar();
        static void print_bottom_bar();
        static void print_contents(symbol s1, symbol s2, symbol s3);
};

#endif //DISPLAY_UTILS_H
