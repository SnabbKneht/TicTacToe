#include "menu.h"
#include <iostream>
#include "multiplayer_console_session.h"

using std::cin;
using std::cout;

void menu::load()
{
    cout << "Singleplayer\n";
    cout << "Multiplayer\n";
    cout << "Exit\n";

    char input = '\0';
    cin >> input;
    if(input == 'm')
    {
        multiplayer_console_session session;
        session.start();
    }
}
