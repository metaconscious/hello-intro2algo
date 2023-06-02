//
// Created by user on 23-6-2.
//

#ifndef HELLO_INTRO2ALGO_SORT_H
#define HELLO_INTRO2ALGO_SORT_H

#include <concepts>
#include <vector>

namespace hi2a::sort
{
    namespace inplace
    {
        template<std::totally_ordered T>
        void insertionSort(std::vector<T>& array)
        {
            if (array.empty())
            {
                return;
            }
            for (auto eit{ std::begin(array) + 1 }; eit != std::end(array); ++eit)
            {
                auto value{ *eit };
                auto iit{ eit - 1 };
                while (iit != std::begin(array) - 1 && *iit > value)
                {
                    *(iit + 1) = *iit;
                    --iit;
                }
                *(iit + 1) = value;
            }
        }
    }
}

#endif //HELLO_INTRO2ALGO_SORT_H
