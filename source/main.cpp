#include <iostream>
#include "board.h"
#include "display_utils.h"
#include "game.h"
#include "multiplayer_console_session.h"
#include "session.h"

using std::cin;
using std::cout;

int main()
{
    multiplayer_console_session session;
    session.start();
}
