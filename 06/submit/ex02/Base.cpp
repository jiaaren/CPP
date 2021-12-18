#include <iostream>
#include <math.h>
#include <time.h>
#include <stdexcept>
#include "Base.hpp"

Base::Base(void)
{
    std::cout << "Base Class created\n";
    return;
}

Base *Base::generate(void)
{
    int r;
    // why can't make this static
    std::string classes = "ABC";

    srand(time(0));
    r = rand() % 3;
    std::cout << "Base instantiated with " << classes[r] << " generated\n";
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

// pointers check for return value of NULL
void Base::identify(Base *p)
{
    A *a = static_cast<A *>(p);
    B *b = static_cast<B *>(p);
    C *c = static_cast<C *>(p);
    // why can't make this static
    std::string classes = "ABC";

    int i = 0;
    if (a)
        ;
    else if (b)
        i = 1;
    else if (c)
        i = 2;
    std::cout << "Real type is: " << classes[i] << "\n";
}

// references check for exceptions returned to bad_type
void Base::identify(Base &p)
{
    int i;
    // why can't make this static
    std::string classes = "ABC";

    try
    {
        A &a = static_cast<A &>(p);
        i = 0;
    }
    catch (std::bad_cast &bc)
    {
        (void)bc;
    }
    try
    {
        B &b = static_cast<B &>(p);
        i = 1;
    }
    catch (std::bad_cast &bc)
    {
        (void)bc;
    }
    try
    {
        C &c = static_cast<C &>(p);
        i = 2;
    }
    catch (std::bad_cast &bc)
    {
        (void)bc;
    }
    std::cout << "Real type is: " << classes[i] << "\n";
}

// why can't i create this
// static std::string const classes = "ABC";
