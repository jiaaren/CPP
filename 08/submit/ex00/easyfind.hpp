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

    Good sources
    1. https://stackoverflow.com/questions/6335105/how-do-i-pass-a-template-as-a-template-parameter-to-a-template
    2. https://www.informit.com/articles/article.aspx?p=376878
    3. Why need typename - https://stackoverflow.com/questions/22874535/dependent-scope-need-typename-in-front
    4. Why need template and typename keywords? - https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
*/

// typename, typaname because tempalte accepts both a type and a hidden allocator
template <template <typename, typename> class Cont>
int easyfind(Cont<int, std::allocator<int>> const &t, int i)
{
    // creating instance of iterator
    // need const iterator because item passed in is const t
    typename Cont<int, std::allocator<int>>::const_iterator it;
    int index = 0;
    for (it = t.begin(); it != t.end(); ++it)
    {
        if (*it == i)
            return (index);
        index++;
    }
    return (-1);
}

#endif
