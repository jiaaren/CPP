#include <iostream>
#include <math.h>
#include <time.h>
#include <stdexcept>
#include "Base.hpp"

std::string const Base::classes = "ABC";

Base::Base(void)
{
    std::cout << "Base Class created\n";
    return;
}

Base *generate(void)
{
    int r;

    srand(time(0));
    r = rand() % 3;
    std::cout << "Base instantiated with " << Base::classes[r] << " generated\n";
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

// pointers check for return value of NULL
void identify(Base *p)
{
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);

    int i = 0;
    if (a)
        ;
    else if (b)
        i = 1;
    else if (c)
        i = 2;
    std::cout << "Real type (pointer) is: " << Base::classes[i] << "\n";
}

// references check for exceptions returned to bad_type
void identify(Base &p)
{
    int i;

    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        i = 0;
    }
    catch (std::exception &bc)
    {
        (void)bc;
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        i = 1;
    }
    catch (std::exception &bc)
    {
        (void)bc;
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        i = 2;
    }
    catch (std::exception &bc)
    {
        (void)bc;
    }
    std::cout << "Real type (reference) is: " << Base::classes[i] << "\n";
}
