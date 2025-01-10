#include "board.h"
#include <stdexcept>

#include "my_random.h"

using std::invalid_argument;
using std::out_of_range;
using std::vector;

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

bool board::is_full() const
{
    for(auto square : contents)
    {
        if(square == symbol::BLANK)
            return false;
    }
    return true;
}

int board::count() const
{
    int result = 0;
    for(auto square : contents)
    {
        if(square != symbol::BLANK)
            ++result;
    }
    return result;
}

vector<int> board::get_unoccupied_corners() const
{
    vector<int> corners;
    if(get(1) == symbol::BLANK) corners.push_back(1);
    if(get(3) == symbol::BLANK) corners.push_back(3);
    if(get(7) == symbol::BLANK) corners.push_back(7);
    if(get(9) == symbol::BLANK) corners.push_back(9);

    return corners;
}

std::vector<int> board::get_unoccupied_squares() const
{
    vector<int> squares;
    for(int i = 1; i <= 9; ++i)
    {
        if(get(i) == symbol::BLANK)
            squares.push_back(i);
    }
    return squares;
}

bool board::is_any_corner_occupied() const
{
    return
        get(1) != symbol::BLANK ||
        get(3) != symbol::BLANK ||
        get(7) != symbol::BLANK ||
        get(9) != symbol::BLANK;
}
