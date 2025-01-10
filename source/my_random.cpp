#include "my_random.h"

std::random_device my_random::rd;
std::mt19937 my_random::gen(rd());

int my_random::random_index(int size)
{
    std::uniform_int_distribution dist(0, size - 1);

    return dist(gen);
}
