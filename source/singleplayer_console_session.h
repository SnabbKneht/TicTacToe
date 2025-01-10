#ifndef SINGLEPLAYER_CONSOLE_SESSION_H
#define SINGLEPLAYER_CONSOLE_SESSION_H
#include "session.h"

class singleplayer_console_session
{
    public:
        void start();

    private:
        session m_session;
        void read_player_name();
        void print_game_info() const;
        void read_input();
};

#endif //SINGLEPLAYER_CONSOLE_SESSION_H
