#ifndef AI_H
#define AI_H
#include <vector>
#include "symbol.h"

class board;

class ai
{
    static std::vector<int> get_possible_moves_to_win_immediately(const board &brd, symbol self);
    static std::vector<int> get_possible_moves_to_win_in_next_turn(const board &brd, symbol self);
};

#endif //AI_H
