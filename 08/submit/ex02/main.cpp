#include <iostream>
#include <list>
#include "mutantstack.hpp"

int main(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    MutantStack<int> another(mstack);
    std::cout << another.top() << std::endl;

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator const it;
    it = mstack.begin();
    (void)it;
    // MutantStack<int>::iterator ite = mstack.end();

    // ++it;
    // --it;
    // while (it != ite)
    // {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }
    // std::stack<int> s(mstack);
    return (0);
}
