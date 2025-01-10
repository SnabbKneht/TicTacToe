#include "ai.h"
#include "board.h"
#include <iostream>
#include "my_random.h"

using std::vector;
using std::cout;

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

    vector<bool> v(9, false);
    vector<int> result;

    // horizontal 1
    if(a == self && b == self && c == symbol::BLANK) v[2] = true;
    else if(a == symbol::BLANK && b == self && c == self) v[0] = true;
    else if(a == self && b == symbol::BLANK && c == self) v[1] = true;

    // horizontal 2
    if(d == self && e == self && f == symbol::BLANK) v[5] = true;
    else if(d == symbol::BLANK && e == self && f == self) v[3] = true;
    else if(d == self && e == symbol::BLANK && f == self) v[4] = true;

    // horizontal 3
    if(g == self && h == self && i == symbol::BLANK) v[8] = true;
    else if(g == symbol::BLANK && h == self && i == self) v[6] = true;
    else if(g == self && h == symbol::BLANK && i == self) v[7] = true;

    // vertical 1
    if(a == self && d == self && g == symbol::BLANK) v[6] = true;
    else if(a == symbol::BLANK && d == self && g == self) v[0] = true;
    else if(a == self && d == symbol::BLANK && g == self) v[3] = true;

    // vertical 2
    if(b == self && e == self && h == symbol::BLANK) v[7] = true;
    else if(b == symbol::BLANK && e == self && h == self) v[1] = true;
    else if(b == self && e == symbol::BLANK && h == self) v[4] = true;

    // vertical 3
    if(c == self && f == self && i == symbol::BLANK) v[8] = true;
    else if(c == symbol::BLANK && f == self && i == self) v[2] = true;
    else if(c == self && f == symbol::BLANK && i == self) v[5] = true;

    // diagonal 1
    if(a == self && e == self && i == symbol::BLANK) v[8] = true;
    else if(a == symbol::BLANK && e == self && i == self) v[0] = true;
    else if(a == self && e == symbol::BLANK && i == self) v[4] = true;

    // diagonal 2
    if(c == self && e == self && g == symbol::BLANK) v[6] = true;
    else if(c == symbol::BLANK && e == self && g == self) v[2] = true;
    else if(c == self && e == symbol::BLANK && g == self) v[4] = true;

    for(int square = 1; square <= 9; ++square)
        if(v[square - 1]) result.push_back(square);

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

    return result;
}

std::vector<int> ai::get_possible_moves_to_force_a_block(const board &brd, symbol self)
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

    vector<bool> v(9, false);
    vector<int> result;

    // horizontal 1
    if(a == self && b == symbol::BLANK && c == symbol::BLANK) v[1] = true, v[2] = true;
    else if(a == symbol::BLANK && b == self && c == symbol::BLANK) v[0] = true, v[2] = true;
    else if(a == symbol::BLANK && b == symbol::BLANK && c == self) v[0] = true, v[1] = true;

    // horizontal 2
    if(d == self && e == symbol::BLANK && f == symbol::BLANK) v[4] = true, v[5] = true;
    else if(d == symbol::BLANK && e == self && f == symbol::BLANK) v[3] = true, v[5] = true;
    else if(d == symbol::BLANK && e == symbol::BLANK && f == self) v[3] = true, v[4] = true;

    // horizontal 3
    if(g == self && h == symbol::BLANK && i == symbol::BLANK) v[7] = true, v[8] = true;
    else if(g == symbol::BLANK && h == self && i == symbol::BLANK) v[6] = true, v[8] = true;
    else if(g == symbol::BLANK && h == symbol::BLANK && i == self) v[6] = true, v[7] = true;

    // vertical 1
    if(a == self && d == symbol::BLANK && g == symbol::BLANK) v[3] = true, v[6] = true;
    else if(a == symbol::BLANK && d == self && g == symbol::BLANK) v[0] = true, v[6] = true;
    else if(a == symbol::BLANK && d == symbol::BLANK && g == self) v[0] = true, v[3] = true;

    // vertical 2
    if(b == self && e == symbol::BLANK && h == symbol::BLANK) v[4] = true, v[7] = true;
    else if(b == symbol::BLANK && e == self && h == symbol::BLANK) v[1] = true, v[7] = true;
    else if(b == symbol::BLANK && e == symbol::BLANK && h == self) v[1] = true, v[4] = true;

    // vertical 3
    if(c == self && f == symbol::BLANK && i == symbol::BLANK) v[5] = true, v[8] = true;
    else if(c == symbol::BLANK && f == self && i == symbol::BLANK) v[2] = true, v[8] = true;
    else if(c == symbol::BLANK && f == symbol::BLANK && i == self) v[2] = true, v[5] = true;

    // diagonal 1
    if(a == self && e == symbol::BLANK && i == symbol::BLANK) v[4] = true, v[8] = true;
    else if(a == symbol::BLANK && e == self && i == symbol::BLANK) v[0] = true, v[8] = true;
    else if(a == symbol::BLANK && e == symbol::BLANK && i == self) v[0] = true, v[4] = true;

    // diagonal 2
    if(c == self && e == symbol::BLANK && g == symbol::BLANK) v[4] = true, v[6] = true;
    else if(c == symbol::BLANK && e == self && g == symbol::BLANK) v[2] = true, v[6] = true;
    else if(c == symbol::BLANK && e == symbol::BLANK && g == self) v[2] = true, v[4] = true;

    for(int square = 1; square <= 9; ++square)
        if(v[square - 1]) result.push_back(square);

    return result;
}

int ai::get_best_move(const board &brd, symbol self)
{
    symbol opponent = self == symbol::X ? symbol::O : symbol::X;

    if(brd.count() == 0)
    {
        cout << "I move first so I take one of the corners.\n";
        auto corners = brd.get_unoccupied_corners();
        return corners[my_random::random_index(corners.size())];
    }
    if(brd.count() == 1)
    {
        if(brd.is_any_corner_occupied())
        {
            cout << "I move second, and you took one of the corners so I take the center.\n";
            return 5;
        }
        else
        {
            cout << "I move second, and since you didn't take a corner, I will (though I am not sure about it).\n";
            auto corners = brd.get_unoccupied_corners();
            return corners[my_random::random_index(corners.size())];
        }
    }
    if(auto my_win_moves = get_possible_moves_to_win_immediately(brd, self); my_win_moves.size() > 0)
    {
        cout << "I can win in one move, so I do.\n";
        return my_win_moves[my_random::random_index(my_win_moves.size())];
    }
    auto opponent_win_moves = get_possible_moves_to_win_immediately(brd, opponent);
    if(opponent_win_moves.size() == 1)
    {
        cout << "You can win in one move, so I block you.\n";
        return opponent_win_moves[0];
    }
    if(opponent_win_moves.size() >= 2)
    {
        cout << "You can win in one move in multiple ways so I already lost. Making a random move.\n";
        auto all = brd.get_unoccupied_squares();
        return all[my_random::random_index(all.size())];
    }
    if(auto my_moves = get_possible_moves_to_win_in_next_turn(brd, self); my_moves.size() > 0)
    {
        cout << "I can create an auto-win situation, so I do.\n";
        return my_moves[my_random::random_index(my_moves.size())];
    }
    auto opponent_moves = get_possible_moves_to_win_in_next_turn(brd, opponent);
    if(opponent_moves.size() == 1)
    {
        cout << "You can create an auto-win situation but only in one way, so I block you.\n";
        return opponent_moves[my_random::random_index(opponent_moves.size())];
    }
    auto possible_block_forces = get_possible_moves_to_force_a_block(brd, self);
    if(opponent_moves.size() >= 2 && possible_block_forces.size() > 0)
    {
        cout << "You can create an auto-win situation in multiple-ways, but I can force a block, so I do.\n";
        return possible_block_forces[my_random::random_index(possible_block_forces.size())];
    }

    cout << "I don't know what to do. Making a random move.\n";
    auto all = brd.get_unoccupied_squares();
    return all[my_random::random_index(all.size())];
}
