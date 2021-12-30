#include <string>

/*
    things to learn:
    - how to call constructor for parent
    - how to call constructor for both parent and child
    - sequence of events -> 1. initialising parent, 2. then initialise child

    Encapsulation levels of inheritance
    - public, private, protected in 'Class Cat : public Animal'

    Multiple inheritance
    - what happens if there are conflicting attributes/functions?
    -
*/

class Animal
{
private:
    int _numberOfLegs;

public:
    Animal();
    Animal(Animal const &);
    ~Animal();
    Animal &operator=(Animal const &);

    void run(int distance);
};

class Cat : public Animal
{
public:
    Cat();
    Cat(Cat const &);
    ~Cat();
    Cat &operator=(Cat const &);

    void meow(std::string &meow);
};