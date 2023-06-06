#include "helper.h"
#include "intro2algo/numeric.h"
#include "intro2algo/sort.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>


int main(int argc, const char* argv[])
{
    using value_type = int;
    constexpr value_type initialValue{ 1 };
    constexpr auto size{ static_cast<value_type>(1e4) };

    std::vector<value_type> original(size);
    std::iota(original.begin(), original.end(), initialValue);
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

    std::cout << "successfully sorted? " << std::boolalpha << same << std::noboolalpha << '\n';

    auto series{ hi2a::arithmeticSeries(initialValue, size, size) };
    auto sum{ hi2a::sum(randomized) };

    std::cout << "Sum == series? " << std::boolalpha << (sum == series) << std::noboolalpha << '\n';

    if (!same)
    {
        std::cout << "Original: " << original << '\n';
        std::cout << "Sorted: " << randomized << '\n';
    }

    return 0;
}
