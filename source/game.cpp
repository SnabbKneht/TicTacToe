#include "game.h"
#include <stdexcept>

game_state game::get_game_state() const
{
    symbol a = m_board.get(1);
    symbol b = m_board.get(2);
    symbol c = m_board.get(3);
    symbol d = m_board.get(4);
    symbol e = m_board.get(5);
    symbol f = m_board.get(6);
    symbol g = m_board.get(7);
    symbol h = m_board.get(8);
    symbol i = m_board.get(9);

    auto winner_symbol = symbol::BLANK;

    // win by horizontal
    if(a != symbol::BLANK && a == b && b == c) winner_symbol = a;
    else if(d != symbol::BLANK && d == e && e == f) winner_symbol = d;
    else if(g != symbol::BLANK && g == h && h == i) winner_symbol = g;

    // win by vertical
    else if(a != symbol::BLANK && a == d && d == g) winner_symbol = a;
    else if(b != symbol::BLANK && b == e && e == h) winner_symbol = b;
    else if(c != symbol::BLANK && c == f && f == i) winner_symbol = c;

    // win by diagonal
    else if(a != symbol::BLANK && a == e && e == i) winner_symbol = a;
    else if(c != symbol::BLANK && c == e && e == g) winner_symbol = c;

    switch(winner_symbol)
    {
        case symbol::X:
            return game_state::X_WON;
        case symbol::O:
            return game_state::O_WON;
        case symbol::BLANK:
            return m_board.is_full() ? game_state::DRAW : game_state::IN_PROGRESS;
    }
}

void game::make_turn(int index)
{
    symbol current = m_next_player;
    if(current == symbol::BLANK) throw std::logic_error("Trying to make turn as BLANK player (Unexpected BLANK as m_next_turn).");
    m_board.set(index, current);
    switch(current)
    {
        case symbol::X:
            m_next_player = symbol::O;
            break;
        case symbol::O:
            m_next_player = symbol::X;
            break;
        default:
            ; // BLANK case already handled
    }
}

void game::reset()
{
    m_board.clear();
    switch(m_starting_player)
    {
        case symbol::X:
            m_next_player = symbol::O;
            break;
        case symbol::O:
            m_next_player = symbol::X;
            break;
        default:
            throw std::logic_error("Unexpected BLANK encountered while restarting the game.");
    }
    m_starting_player = m_next_player;
}
