#ifndef MULTIPLAYER_CONSOLE_SESSION_H
#define MULTIPLAYER_CONSOLE_SESSION_H

#include "session.h"

class multiplayer_console_session
{
    public:
        void start();

    private:
        session m_session;
        void read_player_names();
        void print_game_info_and_ask_for_input() const;
        void read_input();
};

#endif //MULTIPLAYER_CONSOLE_SESSION_H
