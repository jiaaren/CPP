#include <iostream>
#include "Bureaucrat.hpp"

void print(std::string str)
{
    std::cout << str << std::endl;
    return;
}

int main(void)
{
    print("<--- empty constructor (default grade 150) --->");
    Bureaucrat a;
    std::cout << a << std::endl;

    print("\n<--- basic constructor --->");
    Bureaucrat b("billy", 50);
    std::cout << b << std::endl;

    print("\n<--- assignment (a = b) --->");
    a = b;
    std::cout << a << std::endl;

    print("\n<--- copy constructor --->");
    Bureaucrat c(b);
    std::cout << c << std::endl;

    print("\n<--- setter --->");
    a.setGrade(30);
    std::cout << a << std::endl;

    print("\n<--- increment --->");
    a.incrementGrade(29);
    std::cout << a << std::endl;

    print("\n<--- decrement --->");
    a.decrementGrade(76);
    std::cout << a << std::endl;

    print("\n<--- try/catch on too high initialisation --->");
    try
    {
        Bureaucrat x("mrtoohigh", 0);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    print("\n<--- try/catch on too low initialisation --->");
    try
    {
        Bureaucrat y("mrtoohigh", 151);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    print("\n<--- too much increment --->");
    try
    {
        a.incrementGrade(80);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    print("\n<--- try/catch on too low initialisation --->");
    try
    {
        a.decrementGrade(100);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    print("\n<--- try/catch on inappropriate set --->");
    try
    {
        a.setGrade(1000000);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    print("\n<--- try/catch on valid input --->");
    try
    {
        a.setGrade(50);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    print("\n<--- no try/catch (abort) --->");
    Bureaucrat z("wrong boi", 0);
    return (0);
}
