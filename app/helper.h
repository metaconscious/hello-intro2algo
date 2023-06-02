//
// Created by user on 23-6-2.
//

#ifndef HELLO_INTRO2ALGO_HELPER_H
#define HELLO_INTRO2ALGO_HELPER_H

#include <iostream>
#include <ranges>

template<typename T>
concept output_streamable =
requires(T elem)
{
    { std::cout << elem } -> std::convertible_to<std::ostream&>;
};

template<typename T>
requires std::ranges::range<T> and output_streamable<typename T::value_type>
std::ostream& operator<<(std::ostream& os, T range)
{
    for (auto&& e: range)
    {
        os << e << ' ';
    }
    return os;
}

template<typename T>
concept readonly_array =
requires(T array) {
    { array.at() } -> std::same_as<typename T::value_type>;
};

template<typename T>
concept sized_array =
readonly_array<T> and
requires(T sized_array) {
    { sized_array.size() }->std::same_as<typename T::size_type>;
};

template<typename T>
requires sized_array<T> and std::equality_comparable<T>
bool operator==(const T& lhs, const T& rhs)
{
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    for (std::size_t i{ 0 }; i < lhs.size(); ++i)
    {
        if (lhs.at(i) != rhs.at(i))
        {
            return false;
        }
    }
    return true;
}

#endif //HELLO_INTRO2ALGO_HELPER_H
