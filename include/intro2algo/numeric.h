//
// Created by user on 23-6-6.
//

#ifndef HELLO_INTRO2ALGO_NUMERIC_H
#define HELLO_INTRO2ALGO_NUMERIC_H

#include "utility.h"
#include <cassert>
#include <concepts>
#include <cstddef>

namespace hi2a
{
    template<std::integral T, std::unsigned_integral Size>
    constexpr inline T arithmeticSeries(T firstTerm, T lastTerm, Size length) noexcept
    {
        return (firstTerm + lastTerm) * length / 2;
    }

    template<std::integral T, std::integral Size>
    constexpr inline T arithmeticSeries(T firstTerm, T lastTerm, Size length)
    {
        if (length < 0)
        {
            throw std::invalid_argument("length must be larger than or equal to zero");
        }
        return (firstTerm + lastTerm) * length / 2;
    }

    template<value_addable_range T>
    constexpr typename std::ranges::range_value_t<T> sum(T range)
    {
        typename std::ranges::range_value_t<T> sum{ 0 };
        for (auto&& e: range)
        {
            sum += e;
        }
        return sum;
    }
}

#endif //HELLO_INTRO2ALGO_NUMERIC_H
