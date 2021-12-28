#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
private:
    std::vector<int> _v;
    unsigned int _filled;
    unsigned int _size;

public:
    Span(unsigned int n);
    ~Span(void);
    // getter
    int getFilled(void) const;
    int getSize(void) const;
    std::vector<int>::const_iterator getBegin(void) const;
    std::vector<int>::const_iterator getEnd(void) const;
    // add
    void addNumber(int i);
    void addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
    // search functions
    int shortestSpan(void) const;
    int longestSpan(void) const;

    class FilledUp : public std::exception
    {
        virtual const char *what() const throw();
    };
    class SearchFailed : public std::exception
    {
        virtual const char *what() const throw();
    };
};

#endif
