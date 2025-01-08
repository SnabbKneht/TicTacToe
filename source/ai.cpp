#include "ai.h"
#include "board.h"

int ai::can_win_in_one_move(const board &brd, symbol self)
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

    return
        // horizontal 1
        a == self && b == self && c == symbol::BLANK ||
        a == symbol::BLANK && b == self && c == self ||
        a == self && b == symbol::BLANK && c == self ||

        // horizontal 2
        d == self && e == self && f == symbol::BLANK ||
        d == symbol::BLANK && e == self && f == self ||
        d == self && e == symbol::BLANK && f == self ||

        // horizontal 3
        g == self && h == self && i == symbol::BLANK ||
        g == symbol::BLANK && h == self && i == self ||
        g == self && h == symbol::BLANK && i == self ||

        // vertical 1
        a == self && d == self && g == symbol::BLANK ||
        a == symbol::BLANK && d == self && g == self ||
        a == self && d == symbol::BLANK && g == self ||

        // vertical 2
        b == self && e == self && h == symbol::BLANK ||
        b == symbol::BLANK && e == self && h == self ||
        b == self && e == symbol::BLANK && h == self ||

        // vertical 3
        c == self && f == self && i == symbol::BLANK ||
        c == symbol::BLANK && f == self && i == self ||
        c == self && f == symbol::BLANK && i == self ||

        // diagonal 1
        a == self && e == self && i == symbol::BLANK ||
        a == symbol::BLANK && e == self && i == self ||
        a == self && e == symbol::BLANK && i == self ||

        // diagonal 2
        c == self && e == self && g == symbol::BLANK ||
        c == symbol::BLANK && e == self && g == self ||
        c == self && e == symbol::BLANK && g == self;
}
