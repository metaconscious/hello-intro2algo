//
// Created by user on 23-6-2.
//

#ifndef HELLO_INTRO2ALGO_UTILITY_H
#define HELLO_INTRO2ALGO_UTILITY_H

#include <ranges>

namespace hi2a
{
    template<typename T>
    concept sortable_range = std::ranges::contiguous_range<T> and std::totally_ordered<typename T::value_type>;
}

#endif //HELLO_INTRO2ALGO_UTILITY_H
