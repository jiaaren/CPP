#ifndef BASE_HPP
#define BASE_HPP

#include <string>

class Base
{
public:
    Base(void);
    // creating polymorphic class hierarchy
    virtual ~Base(void){};
    Base *generate(void);
    void identify(Base *p);
    void identify(Base &p);
    static std::string const classes;
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif