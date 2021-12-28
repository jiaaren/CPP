#include <iostream>
#include <algorithm>
#include "span.hpp"

void print(int i)
{
    std::cout << i << "\n";
}

int main(void)
{
    {
        Span sp = Span(5);

        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        Span test = Span(5);
        test.addRange(sp.getBegin(), sp.getEnd());
        std::for_each(test.getBegin(), test.getEnd(), print);
    }
}