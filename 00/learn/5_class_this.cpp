#include <iostream>
#include "3_Sample.class.hpp"

void Sample::bar(void)
{
    std::cout << "Member function `bar` called" << std::endl;
}

Sample::Sample(void)
{
    std::cout << "Constructor called" << std::endl;

    // START HERE
    // Assigning variable within constructor
    this->num = 42;
    std::cout << "this->foo is " << this->num << std::endl;
    // Executing class function within constructor
    this->bar();
    // END HERE

    return;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    // not required but good to return
    return;
}

int main(void)
{
    Sample instance;
    return (0);
}