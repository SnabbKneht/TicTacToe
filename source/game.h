#ifndef GAME_H
#define GAME_H

#include "symbol.h"
#include "board.h"
#include "game_state.h"

class board;

class game
{
    public:
        game() = default;
        explicit game(symbol starting_player) : m_starting_player(starting_player), m_next_player(starting_player) {}

        // returns symbol that won or blank if the game is not finished
        game_state get_game_state() const;
        void make_turn(int index);
        void reset();
        const board & get_board() const { return m_board; }
        symbol get_next_player() const { return m_next_player; }

    private:
        board m_board;
        symbol m_starting_player = symbol::X;
        symbol m_next_player = symbol::X;
};

#endif //GAME_H
