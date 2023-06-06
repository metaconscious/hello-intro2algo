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

    template<typename T>
    concept addable =
    requires(T lhs, T rhs) {
        { lhs += rhs } -> std::convertible_to<T>;
    };

    template<typename T>
    concept value_addable_range = std::ranges::range<T> and addable<std::ranges::range_value_t<T>>;
}

#endif //HELLO_INTRO2ALGO_UTILITY_H
