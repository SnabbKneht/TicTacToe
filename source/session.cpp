#include "session.h"

void session::make_turn(int index)
{
    m_game.make_turn(index);
    auto state = get_current_game_state();
    switch(state)
    {
        case game_state::X_WON:
            ++player1_points;
            m_game.reset();
            break;
        case game_state::O_WON:
            ++player2_points;
            m_game.reset();
            break;
        case game_state::DRAW:
            m_game.reset();
        case game_state::IN_PROGRESS:
            ;
    }
}
