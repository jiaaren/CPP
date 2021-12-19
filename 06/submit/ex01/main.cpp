#include <cstdint>
#include <iostream>
#include <stdio.h>
#include "Data.hpp"

int main(void)
{
    Data a("James", 120, 'M');

    // unsigned char c = 255;
    // unsigned char tmp = (c << 4);
    // unsigned char tmp2 = (tmp >> 4);

    // char str[] = "0000";
    // int *tmp_num = reinterpret_cast<int *>(str);

    // std::cout << static_cast<int>(tmp2) << std::endl;
    // std::cout << *tmp_num << std::endl;

    uintptr_t i = serialize(&a);
    std::cout << i << std::endl;

    Data *n = deserialize(i);

    delete n;
    return (0);
}