#include <iostream>
#include "whatever.hpp"

int main(void)
{
    // test double
    std::cout << "<--- Double --->\n";
    {
        double a = 42.42f;
        double b = 10.12f;
        std::cout << "Before, a: " << a << ", b: " << b << "\n";
        std::cout << "Max: " << max(a, b) << "\n";
        std::cout << "Min: " << min(a, b) << "\n";
        swap(a, b);
        std::cout << "After swap, a: " << a << ", b: " << b << "\n";
    }
    std::cout << "\n";
    // test float
    std::cout << "<--- Float --->\n";
    {
        float a = -42.42f;
        float b = 10.12f;
        std::cout << "Before, a: " << a << ", b: " << b << "\n";
        std::cout << "Max: " << max(a, b) << "\n";
        std::cout << "Min: " << min(a, b) << "\n";
        swap(a, b);
        std::cout << "After swap, a: " << a << ", b: " << b << "\n";
    }
    std::cout << "\n";
    // test int
    std::cout << "<--- Int --->\n";
    {
        int a = 42;
        int b = -100;
        std::cout << "Before, a: " << a << ", b: " << b << "\n";
        std::cout << "Max: " << max(a, b) << "\n";
        std::cout << "Min: " << min(a, b) << "\n";
        swap(a, b);
        std::cout << "After swap, a: " << a << ", b: " << b << "\n";
    }
    std::cout << "\n";
    // test char
    std::cout << "<--- Char --->\n";
    {
        char a = 'a';
        char b = 'z';
        std::cout << "Before, a: " << a << ", b: " << b << "\n";
        std::cout << "Max: " << max(a, b) << "\n";
        std::cout << "Min: " << min(a, b) << "\n";
        swap(a, b);
        std::cout << "After swap, a: " << a << ", b: " << b << "\n";
    }
    std::cout << "\n";
    // test bool
    std::cout << "<--- Bool --->\n";
    {
        bool a = true;
        bool b = false;
        std::cout << std::boolalpha << "Before, a: " << a << ", b: " << b << "\n";
        std::cout << "Max: " << max(a, b) << "\n";
        std::cout << "Min: " << min(a, b) << "\n";
        swap(a, b);
        std::cout << std::boolalpha << "After swap, a: " << a << ", b: " << b << "\n";
    }
    std::cout << "\n";
}
