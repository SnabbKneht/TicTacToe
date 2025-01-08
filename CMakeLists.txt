cmake_minimum_required(VERSION 3.30)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

add_executable(TicTacToe source/main.cpp
        source/display_utils.cpp
        source/display_utils.h
        source/board.cpp
        source/board.h
        source/symbol.h
        source/game.cpp
        source/game.h
        source/session.cpp
        source/session.h
        source/game_state.h
        source/multiplayer_console_session.cpp
        source/multiplayer_console_session.h
        source/menu.cpp
        source/menu.h)
