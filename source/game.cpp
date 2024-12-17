#include "game.h"
#include <stdexcept>

symbol game::get_winner() const
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

    // win by horizontal
    if(a != symbol::BLANK && a == b && b == c) return a;
    if(d != symbol::BLANK && d == e && e == f) return d;
    if(g != symbol::BLANK && g == h && h == i) return g;

    // win by vertical
    if(a != symbol::BLANK && a == d && d == g) return a;
    if(b != symbol::BLANK && b == e && e == h) return b;
    if(c != symbol::BLANK && c == f && f == i) return c;

    // win by diagonal
    if(a != symbol::BLANK && a == e && e == i) return a;
    if(c != symbol::BLANK && c == e && e == g) return c;

    return symbol::BLANK;
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
