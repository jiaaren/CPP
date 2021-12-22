#include <iostream>
#include <stdexcept>
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

    print("\n<---- Invalid Input (surname) ---->");
    try
    {
        Data z("Padington", 25, 'F');
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    print("\n<---- Invalid Input (age) ---->");
    try
    {
        Data z("Billy", 151, 'F');
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    print("\n<---- Invalid Input (gender) ---->");
    try
    {
        Data z("Bobbi", 25, 'Z');
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    delete n;
    return (0);
}
