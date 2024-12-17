#include "display_utils.h"
#include <iostream>
#include <string>
#include "symbol.h"
#include "board.h"

using std::cout;
using std::string;

void display_utils::print_board(const board &b)
{
    print_top_bar();
    print_contents(b.get(1), b.get(2), b.get(3));
    print_middle_bar();
    print_contents(b.get(4), b.get(5), b.get(6));
    print_middle_bar();
    print_contents(b.get(7), b.get(8), b.get(9));
    print_bottom_bar();
}

void display_utils::print_top_bar()
{
    cout << "+-----+-----+-----+\n"
            "|     |     |     |\n";
}

void display_utils::print_middle_bar()
{
    cout << "|     |     |     |\n"
            "+-----+-----+-----+\n"
            "|     |     |     |\n";
}

void display_utils::print_bottom_bar()
{
    cout << "|     |     |     |\n"
            "+-----+-----+-----+\n";
}

void display_utils::print_contents(symbol s1, symbol s2, symbol s3)
{
    char c1 = s1 == symbol::O ? 'O' :
              s1 == symbol::X ? 'X' : ' ';
    char c2 = s2 == symbol::O ? 'O' :
              s2 == symbol::X ? 'X' : ' ';
    char c3 = s3 == symbol::O ? 'O' :
              s3 == symbol::X ? 'X' : ' ';

    cout << "|  " << c1 << "  |  " << c2 << "  |  " << c3 << "  |\n";
}
