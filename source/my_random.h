#ifndef MY_RANDOM_H
#define MY_RANDOM_H

#include <random>

class my_random
{
    public:
        static int random_index(int size);

    private:
        static std::random_device rd;
        static std::mt19937 gen;
};

#endif //MY_RANDOM_H
