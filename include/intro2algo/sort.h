//
// Created by user on 23-6-2.
//

#ifndef HELLO_INTRO2ALGO_SORT_H
#define HELLO_INTRO2ALGO_SORT_H

#include "utility.h"
#include <functional>

namespace hi2a::sort
{
    namespace inplace
    {
        template<sortable_range T>
        constexpr void insertionSort(T& array,
                                     std::function<bool(typename T::value_type,
                                                        typename T::value_type)> compare = std::less{})
        {
            [[unlikely]] if (array.empty())
            {
                return;
            }
            for (auto outerIter{ std::next(std::begin(array)) }; outerIter != std::end(array); ++outerIter)
            {
                auto currentValue{ *outerIter };
                auto innerIter{ std::prev(outerIter) };
                while (innerIter != std::prev(std::begin(array)) && !compare(*innerIter, currentValue))
                {
                    *std::next(innerIter) = *innerIter;
                    --innerIter;
                }
                *std::next(innerIter) = currentValue;
            }
        }
    }
}

#endif //HELLO_INTRO2ALGO_SORT_H
