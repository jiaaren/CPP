#include <iostream>
#include "Array.hpp"

int main(void)
{
    Array<int> a(2);
    a[1] = 100;
    std::cout << a[-1] << "\n";
}