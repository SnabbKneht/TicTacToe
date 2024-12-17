#include "board.h"

#include <stdexcept>

using std::invalid_argument;
using std::out_of_range;

void board::set(int index, symbol s)
{
    if(index < 1 || index > 9) throw out_of_range("Board index out of range.");
    if(get(index) != symbol::BLANK) throw invalid_argument("Trying to set an already occupied square.");
    contents[index - 1] = s;
}

symbol board::get(int index) const
{
    if(index < 1 || index > 9) throw out_of_range("Board index out of range.");
    return contents[index - 1];
}
