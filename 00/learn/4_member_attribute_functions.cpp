#include <iostream>
#include "3_Sample.class.hpp"

// Constructor and destructor from previous lessons
Sample::Sample(void)
{
    return;
}

Sample::~Sample(void)
{
    return;
}

void Sample::bar(void)
{
    std::cout << "Member function bar called" << std::endl;

    return;
}

int main(void)
{
    Sample one;
    one.num = 42;

    std::cout << "Number is " << one.num << std::endl;
    one.bar();

    return (0);
}