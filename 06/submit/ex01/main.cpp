#include <iostream>
#include <stdio.h>
#include "Data.hpp"

void print(std::string str)
{
    std::cout << str << "\n";
    return;
}

int main(void)
{
    print("<---- Initialising values ---->");
    Data a("Khong", 25, 'M');

    print("\n<---- Serializing and outputting number ---->");
    uintptr_t i = serialize(&a);
    std::cout << i << std::endl;

    print("\n<---- Deserialzing with uintptr_t ---->");
    Data *n = deserialize(i);

    delete n;
    return (0);
}
