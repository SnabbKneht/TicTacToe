#ifndef SESSION_H
#define SESSION_H

#include "game.h"
#include <string>

class session
{
    public:
        session() : player1("Player 1"), player2("Player 2") {}
        session(const std::string &player1, const std::string &player2) : player1(player1), player2(player2) {}
        void start();

    private:
        game m_game;
        std::string player1;
        std::string player2;
        int player1_points = 0;
        int player2_points = 0;
};

#endif //SESSION_H
