#include <stdexcept>
#include <iostream>

// 1 way of implemeting it
void test1()
{
    try
    {
        if (/* error found*/)
        {
            throw std::exception();
        }
        else
        {
            // do some more stuff
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test2()
{
    if (/* error found*/)
    {
        throw std::exception();
    }
    else
    {
        // do some more stuff
    }
}

void test3()
{
    try
    {
        test2();
    }
    catch (const std::exception &e)
    {
        // handle error
    }
}

void test4()
{
    class PEBKACException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("Problem exists between keyboard and chair");
        }
    };
    try
    {
        // or something which throws an exception
        test3();
    }
    catch (PEBKACException &e)
    {
        // specific exception
        std::cerr << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        // all exceptions
        std::cerr << e.what() << '\n';
    }
}