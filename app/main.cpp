#include "intro2algo/sort.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
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

int main(int argc, const char* argv[])
{
    std::vector<int> original(1e4);
    std::iota(original.begin(), original.end(), 1);
    std::vector randomized{ original };
    std::random_device r{};
    std::seed_seq seeds{ r(), r(), r(), r(), r(), r() };
    std::mt19937 mersenneTwister{ seeds };
    std::ranges::shuffle(randomized, mersenneTwister);

    auto start{ std::chrono::high_resolution_clock::now() };

    hi2a::sort::inplace::insertionSort(randomized);

    auto finish{ std::chrono::high_resolution_clock::now() };

    bool same{ original == randomized };

    std::cout << "Sort took " << std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count()
              << " seconds.\n";

    std::cout << "successfully sorted? " << std::boolalpha << same << '\n';

    if (!same)
    {
        std::cout << std::noboolalpha << "Original: " << original << '\n';
        std::cout << std::noboolalpha << "Sorted: " << randomized << '\n';
    }

    return 0;
}
