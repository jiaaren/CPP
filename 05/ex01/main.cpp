#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void print(std::string str)
{
    std::cout << str << std::endl;
    return;
}

int main(void)
{
    print("<--- empty constructor (default grade 150) --->");
    Form a;

    print("\n<--- basic constructor --->");
    Form b("budget 2021", 50, 20);
    Form d("declaration of independence", 1, 1);

    print("\n<--- assignment (a = b) --->");
    a = b;
    std::cout << a << std::endl;

    print("<--- copy constructor --->");
    Form c(b);

    print("\n<--- sign form (successful) via form --->");
    Bureaucrat x("billie", 40);
    b.beSigned(x);
    std::cout << b << std::endl;

    print("<--- sign form (successful) via bureaucrat --->");
    Form e("toilet_paper", 40, 1);
    x.signForm(e);
    std::cout << e << std::endl;
    Form g("way_too_low", 41, 123);
    x.signForm(g);
    std::cout << g << std::endl;

    print("\n<--- sign form (unsuccessful) via form--->");
    print("!! refer to try catch below");

    print("\n<--- sign form (unsuccessful) via bureaucrat --->");
    x.signForm(d);
    std::cout << d << std::endl;
    Form f("still_too_high", 39, 149);
    x.signForm(f);
    std::cout << f << std::endl;

    print("<--- try/catch on too high initialisation (0) --->");
    try
    {
        Form x("too_high1", 0, 150);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form x("too_high2", 1, 0);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    print("\n<--- try/catch on too low initialisation --->");
    try
    {
        Form y("too_low1", 151, 1);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form y("too_low2", 1, 200);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    print("\n<--- beSigned --->");
    Form z("way_too_high", 1, 1);
    try
    {
        z.beSigned(x);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    Bureaucrat h("not_high_enough", 2);
    try
    {
        z.beSigned(h);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    print("\n<-- Copy with signed -->");
    Form zz;
    zz = e;
    std::cout << zz << std::endl;

    print("\n<-- Signed on alreay signed (form) -->");
    e.beSigned(h);

    print("\n<-- Signed on alreay signed (bureaucrat) -->");
    h.signForm(e);

    print("\n<--- END --->");
    return (0);
}
