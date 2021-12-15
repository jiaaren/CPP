
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void print(std::string str)
{
    std::cout << str << std::endl;
    return;
}

int main(void)
{
    print("\n<---- PresidentialPardonForm ---->");
    PresidentialPardonForm a("bubbles the elephant");
    Bureaucrat b("hamilton", 5);

    print("\n<---- No sign ---->");
    b.executeForm(a);
    std::cout << a << std::endl;

    print("\n<---- Signed ---->");
    a.beSigned(b);
    a.execute(b);

    print("\n<---- Noobish bureaucrat test ---->");
    Bureaucrat noob1("noober 1", 6);
    noob1.executeForm(a);
    try
    {
        a.execute(noob1);
    }
    catch (std::exception &e)
    {
        print(e.what());
    }

    print("\n\n\n<---- ShrubberyCreationForm ---->");
    ShrubberyCreationForm c("santa");
    Bureaucrat d("rudolph", 137);

    print("\n<---- No sign ---->");
    d.executeForm(c);
    std::cout << c << std::endl;

    print("\n<---- Signed ---->");
    c.beSigned(d);
    c.execute(d);

    print("\n<---- Noobish bureaucrat test ---->");
    Bureaucrat noob2("noober 2", 138);
    noob2.executeForm(c);
    try
    {
        c.execute(noob2);
    }
    catch (std::exception &e)
    {
        print(e.what());
    }

    print("\n\n\n<---- RobotomyRequestForm ---->");
    RobotomyRequestForm e("student");
    Bureaucrat f("professor", 45);

    print("\n<---- No sign ---->");
    f.executeForm(e);
    std::cout << e << std::endl;

    print("\n<---- Signed ---->");
    e.beSigned(f);
    e.execute(f);

    print("\n<---- Noobish bureaucrat test ---->");
    Bureaucrat noob3("noober 3", 46);
    noob3.executeForm(e);
    try
    {
        e.execute(noob3);
    }
    catch (std::exception &e)
    {
        print(e.what());
    }
    print("\n<---- END ---->");

    return (0);
}