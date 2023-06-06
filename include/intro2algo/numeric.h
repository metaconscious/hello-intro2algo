//
// Created by user on 23-6-6.
//

#ifndef HELLO_INTRO2ALGO_NUMERIC_H
#define HELLO_INTRO2ALGO_NUMERIC_H

#include <cstddef>

namespace hi2a
{
    template<typename T>
    constexpr inline T arithmeticSeries(T firstTerm, T lastTerm, std::size_t length)
    {
        return (firstTerm + lastTerm) * length / 2;
    }

    template<typename T>
    constexpr typename T::value_type sum(T range)
    {
        typename T::value_type sum{ 0 };
        for (auto&& e: range)
        {
            sum += e;
        }
        return sum;
    }
}

#endif //HELLO_INTRO2ALGO_NUMERIC_H
