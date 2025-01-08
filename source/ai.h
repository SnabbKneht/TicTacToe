#ifndef AI_H
#define AI_H
#include "symbol.h"

class board;

class ai
{
    static int can_win_in_one_move(const board &brd, symbol self);
};

#endif //AI_H
