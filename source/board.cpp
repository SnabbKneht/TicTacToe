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

int board::get_random_unoccupied_corner() const
{
    vector<int> corners;
    if(get(1) == symbol::BLANK) corners.push_back(1);
    if(get(3) == symbol::BLANK) corners.push_back(3);
    if(get(7) == symbol::BLANK) corners.push_back(7);
    if(get(9) == symbol::BLANK) corners.push_back(9);

    if(corners.empty()) throw std::runtime_error("There are no unoccupied corners.");

    return corners[my_random::random_index(corners.size())];
}
