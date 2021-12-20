#include <iostream>
#include "iter.hpp"

template <typename T>
void print_val(T const &x)
{
    std::cout << x << " ";
    return;
}

template <typename T>
void mult_ten(T &x)
{
    x *= 10;
    return;
}

template <typename T>
void add_one(T &x)
{
    x++;
    return;
}

int main(void)
{
    {
        std::cout << "<--- Double array --->\n";
        double arr[10] = {-5.123f, -4.3412f, -3.23f, -2.134f, -1.3413f, 0, 1.24f, 2.1234f, 3.1234f, 4.1234f};
        // to specify type for <double>, still don't really fully understand positioning of <>
        ::iter(arr, 10, print_val<double>);
        std::cout << "\n";
        ::iter(arr, 10, mult_ten<double>);
        ::iter(arr, 10, print_val<double>);
        std::cout << "\n";
    }
    {
        std::cout << "\n<--- Float array --->\n";
        float arr[10] = {-5.123f, -4.3412f, -3.23f, -2.134f, -1.3413f, 0, 1.24f, 2.1234f, 3.1234f, 4.1234f};
        // to specify type for <float>, still don't really fully understand positioning of <>
        ::iter(arr, 10, print_val<float>);
        std::cout << "\n";
        ::iter(arr, 10, mult_ten<float>);
        ::iter(arr, 10, print_val<float>);
        std::cout << "\n";
    }
    {
        std::cout << "\n<--- Char array --->\n";
        char arr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
        // to specify type for <int>, still don't really fully understand positioning of <>
        ::iter(arr, 10, print_val<char>);
        std::cout << "\n";
        ::iter(arr, 10, add_one<char>);
        ::iter(arr, 10, print_val<char>);
        std::cout << "\n";
    }
    {
        std::cout << "\n<--- Bool array --->\n";
        char arr[10] = {true, false, true, false, true, false, true, false, true, false};
        // to specify type for <int>, still don't really fully understand positioning of <>
        ::iter(arr, 10, print_val<bool>);
        std::cout << "\n";
    }
}
