#include "vector_utils.h"
#include <algorithm>

void vector_utils::add_if_does_not_exist(std::vector<int> &vec, int elem)
{
    if(std::find(vec.begin(), vec.end(), elem) != vec.end()) return;
    vec.push_back(elem);
}
