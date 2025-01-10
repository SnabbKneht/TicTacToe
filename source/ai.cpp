#include "ai.h"
#include "board.h"

using std::vector;

vector<int> ai::get_possible_moves_to_win_immediately(const board &brd, symbol self)
{
    const symbol a = brd.get(1);
    const symbol b = brd.get(2);
    const symbol c = brd.get(3);
    const symbol d = brd.get(4);
    const symbol e = brd.get(5);
    const symbol f = brd.get(6);
    const symbol g = brd.get(7);
    const symbol h = brd.get(8);
    const symbol i = brd.get(9);

    vector<int> result;

    // horizontal 1
    if(a == self && b == self && c == symbol::BLANK) result.push_back(3);
    else if(a == symbol::BLANK && b == self && c == self) result.push_back(1);
    else if(a == self && b == symbol::BLANK && c == self) result.push_back(2);

    // horizontal 2
    if(d == self && e == self && f == symbol::BLANK) result.push_back(6);
    else if(d == symbol::BLANK && e == self && f == self) result.push_back(4);
    else if(d == self && e == symbol::BLANK && f == self) result.push_back(5);

    // horizontal 3
    if(g == self && h == self && i == symbol::BLANK) result.push_back(9);
    else if(g == symbol::BLANK && h == self && i == self) result.push_back(7);
    else if(g == self && h == symbol::BLANK && i == self) result.push_back(8);

    // vertical 1
    if(a == self && d == self && g == symbol::BLANK) result.push_back(7);
    else if(a == symbol::BLANK && d == self && g == self) result.push_back(1);
    else if(a == self && d == symbol::BLANK && g == self) result.push_back(4);

    // vertical 2
    if(b == self && e == self && h == symbol::BLANK) result.push_back(8);
    else if(b == symbol::BLANK && e == self && h == self) result.push_back(2);
    else if(b == self && e == symbol::BLANK && h == self) result.push_back(5);

    // vertical 3
    if(c == self && f == self && i == symbol::BLANK) result.push_back(9);
    else if(c == symbol::BLANK && f == self && i == self) result.push_back(3);
    else if(c == self && f == symbol::BLANK && i == self) result.push_back(6);

    // diagonal 1
    if(a == self && e == self && i == symbol::BLANK) result.push_back(9);
    else if(a == symbol::BLANK && e == self && i == self) result.push_back(1);
    else if(a == self && e == symbol::BLANK && i == self) result.push_back(5);

    // diagonal 2
    if(c == self && e == self && g == symbol::BLANK) result.push_back(7);
    else if(c == symbol::BLANK && e == self && g == self) result.push_back(3);
    else if(c == self && e == symbol::BLANK && g == self) result.push_back(5);

    return result;
}

// returns moves that will result in at least two 2/3 complete lines, i.e. the opponent won't be able to block both
std::vector<int> ai::get_possible_moves_to_win_in_next_turn(const board &brd, symbol self)
{
    vector<int> result;

    for(int i = 1; i <= 9; ++i)
    {
        if(brd.get(i) != symbol::BLANK) continue;

        board new_brd = brd;
        new_brd.set(i, self);
        if(get_possible_moves_to_win_immediately(new_brd, self).size() >= 2)
            result.push_back(i);
    }
}
