#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>

/*
    T is represented by a container
    - https://www.cplusplus.com/reference/stl/
    Need to find a function which exists in all types of containers
    - there is 'find' member but only for associative containers
        - not available in basic containers
    - universally all containers have iterators

    Const iterator vs iterator
    - https://stackoverflow.com/questions/5346890/what-is-the-difference-between-const-iterator-and-iterator
    - const iterator prevents modification of referenced value

    Pre-increment vs post-increment
    - https://stackoverflow.com/questions/1077026/incrementing-iterators-is-it-more-efficient-than-it
    - pre-increment is faster since no new copy is created
*/

// how to put a <int> in here?
template <template <typename, class> class T>
int easyfind(T<int, std::allocator<int>> const &t, int i)
{
    // creating instance of iterator
    T<int, std::allocator<int>>::iterator it;
    for (it = t.begin(); it != t.end(); ++it)
        if (*it == i)
            return (std::distance(t.begin(), it));
    return (-1);
}

#endif
