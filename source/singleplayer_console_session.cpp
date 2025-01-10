#include "singleplayer_console_session.h"
#include <string>
#include <iostream>
#include <limits>
#include "display_utils.h"
#include "ai.h"

using std::cin;
using std::cout;
using std::cerr;
using std::string;

void singleplayer_console_session::start()
{
    read_player_name();
    while(true)
    {
        print_game_info();
        switch(m_session.get_next_player())
        {
            case symbol::X:
                read_input();
                break;
            case symbol::O:
                m_session.make_turn(ai::get_best_move(m_session.get_board(), symbol::O));
                break;
            case symbol::BLANK:
                throw std::logic_error("Unexpected BLANK as next player.");
        }
    }
}

void singleplayer_console_session::read_player_name()
{
    cout << "Enter player name: ";
    string name;
    cin >> name;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    m_session = session(name, "AI");
}

void singleplayer_console_session::print_game_info() const
{
    display_utils::print_score(
        m_session.get_player1_name(),
        m_session.get_player1_points(),
        m_session.get_player2_name(),
        m_session.get_player2_points());

    display_utils::print_board(m_session.get_board());
}

void singleplayer_console_session::read_input()
{
    while(true)
    {
        int input = 0;
        while(true)
        {
            cin >> input;
            if(cin)
            {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            cerr << "Not a number.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
