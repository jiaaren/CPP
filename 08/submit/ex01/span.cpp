#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "span.hpp"

Span::Span(void) : _v(std::vector<int>(0)), _filled(0), _size(0)
{
    return;
}

// initialise std::vector<int> to 0
Span::Span(unsigned int n) : _v(std::vector<int>(0)), _filled(0), _size(n)
{
    return;
}

Span::Span(Span const &s)
{
    *this = s;
}

Span::~Span(void)
{
    return;
}

Span &Span::operator=(Span const &rhs)
{
    _v = rhs.getVector();
    _filled = rhs.getFilled();
    _size = rhs.getSize();
    return (*this);
}

std::vector<int> Span::getVector(void) const
{
    return (_v);
}

int Span::getFilled(void) const
{
    return (_filled);
}

int Span::getSize(void) const
{
    return (_size);
}

std::vector<int>::const_iterator Span::getBegin(void) const
{
    return (_v.begin());
}

std::vector<int>::const_iterator Span::getEnd(void) const
{
    return (_v.end());
}

void Span::addNumber(int i)
{
    if (_filled >= _size)
        throw(FilledUp());
    _v.push_back(i);
    _filled++;
    return;
}

// For each - https://www.cplusplus.com/reference/algorithm/for_each/
void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    std::vector<int>::const_iterator it;
    for (it = begin; it != end; ++it)
    {
        if (_filled >= _size)
            throw(FilledUp());
        _v.push_back(*it);
        _filled++;
    }
    return;
}

int Span::shortestSpan(void) const
{
    if (_filled <= 1)
        throw(SearchFailed());
    std::vector<int> tmp(_v);
    std::sort(tmp.begin(), tmp.end());
    std::vector<int>::const_iterator it;
    int shortest = std::numeric_limits<int>::max();
    int range = 0;
    for (it = tmp.begin(); it != tmp.end() && (it + 1) != tmp.end(); ++it)
    {
        range = *(it + 1) - *(it);
        if (range < shortest)
            shortest = range;
    }
    return (shortest);
}

int Span::longestSpan(void) const
{
    if (_filled <= 1)
        throw(SearchFailed());
    int min = *std::min_element(_v.begin(), _v.end());
    int max = *std::max_element(_v.begin(), _v.end());
    return (max - min);
}

const char *Span::FilledUp::what() const throw()
{
    return ("All filled up!");
}

const char *Span::SearchFailed::what() const throw()
{
    return ("Need at least 2 numbers stored!, no span to find :(");
}
