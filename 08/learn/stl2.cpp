#include <iostream>
#include <list>
#include <algorithm>

void print_int(int i)
{
    std::cout << i << "\n";
}

int main(void)
{
    std::list<int> l;
    l.push_back(10);
    l.push_back(25);
    l.push_back(42);
    l.push_back(35);
    l.push_back(4);
    l.push_back(2);
    l.push_back(-100);

    std::for_each(l.begin(), l.end(), print_int);
}