#include <iostream>
#include "3_Sample.class.hpp"

// Declaring constructor
Sample::Sample(void)
{
    std::cout << "Constructor called" << std::endl;
    // not required but good to return
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
    // variable instance created
    Sample instance;

    Sample instance2;
    return (0);
}