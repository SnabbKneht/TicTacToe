#include "session.h"
#include <iostream>
#include <thread>

#include "display_utils.h"

using std::cin;
using std::cout;
using std::cerr;

void session::start()
{
    while(true)
    {
        while(m_game.get_winner() == symbol::BLANK)
        {
            bool input_is_valid = false;
            while(!input_is_valid)
            {
                display_utils::clear_console();
                display_utils::print_board(m_game.get_board());
                cout << (m_game.get_next_player() == symbol::X ? player1 : player2) << "'s turn\n";
                cout << "Select square (1-9): ";

                int input = 0;
                cin >> input;
                if(!cin)
                {
                    cerr << "Invalid input.\n";
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                try
                {
                    m_game.make_turn(input);
                    input_is_valid = true;
                }
                catch(const std::out_of_range &err)
                {
                    cerr << "Provided number is out of range.\n";
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }
                catch(const std::invalid_argument &err)
                {
                    cerr << "This square is already occupied.\n";
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                }
            }
        }

        display_utils::clear_console();
        display_utils::print_board(m_game.get_board());

        if(m_game.get_winner() == symbol::X)
            ++player1_points;
        else
            ++player2_points;

        cout << "Do you want to play again? (y/n)\n";
        char c = '\0';
        cin >> c;
        if(c != 'y') break;
        m_game.reset();
    }
}
