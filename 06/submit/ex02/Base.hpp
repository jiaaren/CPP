#ifndef BASE_HPP
#define BASE_HPP

#include <string>

class Base
{
public:
    Base(void);
    // creating polymorphic class hierarchy
    virtual ~Base(void){};
    static std::string const classes;
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

class A : public Base
{
public:
    A(void){};
    ~A(void){};
};

class B : public Base
{
public:
    B(void){};
    ~B(void){};
};

class C : public Base
{
public:
    C(void){};
    ~C(void){};
};

#endif
