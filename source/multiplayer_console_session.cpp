#include "multiplayer_console_session.h"
#include <iostream>
#include <string>
#include "display_utils.h"
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::string;

void multiplayer_console_session::start()
{
    read_player_names();
    while(true)
    {
        print_game_info_and_ask_for_input();
        read_input();
        display_utils::clear_console();
    }
}

void multiplayer_console_session::read_player_names()
{
    string name1, name2;
    cout << "Enter player 1 name: ";
    cin >> name1;
    cout << "Enter player 2 name: ";
    cin >> name2;
    m_session = session(name1, name2);
}

void multiplayer_console_session::print_game_info_and_ask_for_input() const
{
    display_utils::print_score(
        m_session.get_player1_name(),
        m_session.get_player1_points(),
        m_session.get_player2_name(),
        m_session.get_player2_points());

    display_utils::print_board(m_session.get_board());

    switch(m_session.get_next_player())
    {
        case symbol::X:
            cout << m_session.get_player1_name() << "'s turn:\n";
            break;
        case symbol::O:
            cout << m_session.get_player2_name() << "'s turn:\n";
            break;
        default:
            throw std::logic_error("Unexpected BLANK as next player.");
    }
}

void multiplayer_console_session::read_input()
{
    while(true)
    {
        int input = 0;
        while(true)
        {
            cin >> input;
            if(cin) break;
            cerr << "Not a number.\n";
            cin.clear();
            cin.ignore();
        }
        try
        {
            m_session.make_turn(input);
            break;
        }
        catch(std::out_of_range &err)
        {
            cerr << "Number must be in range 1-9.\n";
        }
        catch(std::invalid_argument &err)
        {
            cerr << "Square already occupied.\n";
        }
    }
}
