#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

template<typename T>
T maximum(T a, T b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

template<typename T>
void shuffle(std::vector<T>& v)
{
    for(int i = 0; i < v.size() - 1; i++)
    {
        int j = rand() % (v.size()- i);
        swap(v[i], v[i+j]);
    }
}
