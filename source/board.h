#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "symbol.h"

class board
{
    public:
        void clear() { for(symbol &s : contents) s = symbol::BLANK; }
        void set(int index, symbol s);
        symbol get(int index) const;
        bool is_full() const;
        int count() const;
        int get_random_unoccupied_corner() const;

    private:
        std::vector<symbol> contents = std::vector(9, symbol::BLANK);
};

#endif //BOARD_H
