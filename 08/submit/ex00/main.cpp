#include <list>
#include <deque>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

/*
    arrays are not in C++98

    forward lists not in C++98
    - https://www.geeksforgeeks.org/difference-between-forward-list-and-list-in-c/
    - forward lists -> based on singly linked lists
    - lists -> based on doubly linked lists

    queues and stacks are not really containers (e.g no iterator)
    - https://stackoverflow.com/questions/7361251/difference-between-sequence-containers-and-container-adaptors-in-c
    - limited functionalities of containers
    - inherits from containers, e.g. stack inherits from deques
*/

void print(std::string str)
{
    std::cout << str << "\n";
}

int main(void)
{
    {
        print("<---- List ---->");
        std::list<int> abc;
        abc.push_back(42);
        abc.push_back(100);
        print("\n** Existing number");
        std::cout << easyfind<std::list>(abc, 100) << "\n";
        print("\n** Non-existing number");
        try
        {
            std::cout << easyfind<std::list>(abc, 124) << "\n";
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << "\n";
        }
    }
    {
        print("\n<---- Vector ---->");
        std::vector<int> abc;
        abc.push_back(42);
        abc.push_back(100);
        print("\n** Existing number");
        std::cout << easyfind<std::vector>(abc, 100) << "\n";
        print("\n** Non-existing number");
        try
        {
            std::cout << easyfind<std::vector>(abc, 124) << "\n";
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << "\n";
        }
    }
    {
        print("\n<---- Deque ---->");
        std::deque<int> abc;
        abc.push_back(42);
        abc.push_back(100);
        print("\n** Existing number");
        std::cout << easyfind<std::deque>(abc, 100) << "\n";
        print("\n** Non-existing number");
        try
        {
            std::cout << easyfind<std::deque>(abc, 124) << "\n";
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << "\n";
        }
    }
}
