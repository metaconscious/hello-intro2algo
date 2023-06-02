//
// Created by user on 23-6-2.
//

#ifndef HELLO_INTRO2ALGO_SORT_H
#define HELLO_INTRO2ALGO_SORT_H

#include <concepts>
#include <functional>
#include <vector>

namespace hi2a::sort
{
    namespace inplace
    {
        template<std::totally_ordered T>
        constexpr void insertionSort(std::vector<T>& array, std::function<bool(T, T)> compare = std::less{})
        {
            if (array.empty())
            {
                return;
            }
            for (auto eit{ std::next(std::begin(array)) }; eit != std::end(array); ++eit)
            {
                auto value{ *eit };
                auto iit{ std::prev(eit) };
                while (iit != std::prev(std::begin(array)) && !compare(*iit, value))
                {
                    *std::next(iit) = *iit;
                    --iit;
                }
                *std::next(iit) = value;
            }
        }
    }
}

#endif //HELLO_INTRO2ALGO_SORT_H
