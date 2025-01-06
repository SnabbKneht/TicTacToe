#ifndef SESSION_H
#define SESSION_H

#include "game.h"
#include <string>

class session
{
    public:
        session() : player1_name("Player 1"), player2_name("Player 2") {}
        session(const std::string &player1_name, const std::string &player2_name) : player1_name(player1_name), player2_name(player2_name) {}

        game_state get_current_game_state() const { return m_game.get_game_state(); }
        void make_turn(int index);
        const board & get_board() const { return m_game.get_board(); }
        const std::string & get_player1_name() const { return player1_name; }
        const std::string & get_player2_name() const { return player2_name; }
        int get_player1_points() const { return player1_points; }
        int get_player2_points() const { return player2_points; }
        symbol get_next_player() const { return m_game.get_next_player(); }

    private:
        game m_game;
        std::string player1_name;
        std::string player2_name;
        int player1_points = 0;
        int player2_points = 0;
};

#endif //SESSION_H
