#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // MutantStack(void);
    // MutantStack(MutantStack const &ms);
    // virtual ~MutantStack(void){};
    // create iterator class
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    MutantStack &operator=(MutantStack &ms);
    // iterator method for begin and end, cannot have const function to return nothing...
    iterator begin(void);
    iterator end(void);
    const_iterator cbegin(void);
    const_iterator cend(void);
    reverse_iterator rbegin(void);
    reverse_iterator rend(void);
    const_reverse_iterator crbegin(void);
    const_reverse_iterator crend(void);
};

// std::stack<T> refers to the base class
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void)
{
    return (std::stack<T>::c.cend());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void)
{
    return (std::stack<T>::c.cbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
    return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
    return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin(void)
{
    return (std::stack<T>::c.crbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend(void)
{
    return (std::stack<T>::c.crend());
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> &ms)
{
    std::stack<T>::operator=(ms);
}

#endif
