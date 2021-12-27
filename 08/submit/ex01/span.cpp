#include <iostream>
#include <vector>
#include <limits>
#include "span.hpp"

Span::Span(unsigned int n) : _filled(0), _size(n), _v(std::vector<int>(n))
{
    return;
}

Span::~Span(void)
{
    return;
}

int Span::getFilled(void) const
{
    return (_filled);
}

int Span::getSize(void) const
{
    return (_size);
}

void Span::addNumber(int i)
{
    if (_filled >= _size)
        throw(FilledUp());
    _v.push_back(i);
    _filled++;
    return;
}

int Span::shortestSpan(void) const
{
    if (_filled <= 1)
        throw(SearchFailed());
    return (0);
}

int Span::longestSpan(void) const
{
    if (_filled <= 1)
        throw(SearchFailed());
    int smallest = std::numeric_limits<int>::max();
    int largest = std::numeric_limits<int>::min();
    std::vector<int>::const_iterator it;
    std::cout << largest << " " << smallest << "\n";
    for (it = _v.begin(); it != _v.end(); ++it)
    {
        if (*it > largest)
            largest = *it;
        if (*it < smallest)
            smallest = *it;
        // std::cout << largest << " " << smallest << "\n";
        std::cout << *it << "\n";
    }
    std::cout << largest << " " << smallest << "\n";
    return (largest - smallest);
}

const char *Span::FilledUp::what() const throw()
{
    return ("All filled up!");
}

const char *Span::SearchFailed::what() const throw()
{
    return ("Need at least 2 numbers stored!, no span to find :(");
}
