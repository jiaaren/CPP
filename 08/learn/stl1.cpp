#include <list>
#include <map>
#include <vector>
#include <iostream>

int main(void)
{
    {
        std::list<int> lst1;
        lst1.push_back(1);
        lst1.push_back(42);
        lst1.push_back(69);

        // what's difference between iterator and const_iterator?
        std::list<int>::const_iterator it;
        // not really the last element, but the element pass the last?
        std::list<int>::const_iterator ite = lst1.end();

        // why ++1
        // visualise as if we're iterating through string until we find a NUL terminator
        for (it = lst1.begin(); it != ite; ++it)
            std::cout << *it << "\n";
    }
    {
        // can combine with classes and use sub type polymorphism
        std::map<std::string, IOperation *> map1;

        map1["var1"] = new OperationA;
        map1["var2"] = new OperationB;
    }
    {
        // no value initialised
        std::vector<int> v1;
        std::vector<int> v2(42, 100);
    }
}
