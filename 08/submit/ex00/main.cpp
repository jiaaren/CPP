#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main(void)
{
    {
        // List
        std::list<int> l;
        l.push_back(42);
        l.push_back(100);
        std::cout << easyfind<std::list>(l, 100) << "\n";
    }
}
