#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <math.h>
#include "span.hpp"

#define MAX 10000

void print(int i)
{
    std::cout << i << " ";
}

int main(void)
{
    // set rng
    srand(time(NULL));
    Span a(MAX);
    for (int i = 0; i < MAX; i++)
    {
        // a.addNumber(rand() % 100);
        a.addNumber(rand());
    }
    std::for_each(a.getBegin(), a.getEnd(), print);
    std::cout << "\n";
    std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
    std::cout << "Longest span : " << a.longestSpan() << std::endl;
}
