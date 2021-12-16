
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void print(std::string str)
{
    std::cout << str << "\n";
    return;
}

int main(void)
{
    print("<--- Create new intern --->");
    Intern boy;

    print("\n<--- Create valid forms --->");
    Form *shrub = boy.makeForm("shrubbery creation", "target1");
    Form *pres = boy.makeForm("presidential pardon", "target2");
    Form *robot = boy.makeForm("robotomy request", "target3");

    print("\n<--- Signing form --->");
    Bureaucrat best("best", 1);
    shrub->beSigned(best);
    pres->beSigned(best);
    best.signForm(*robot);

    print("\n<--- Creating forms that don't exist --->");
    Form *notexist = boy.makeForm("not exit", "fake target");
    (void)notexist;

    print("\n<--- END --->");
    delete shrub;
    delete pres;
    delete robot;
    return (0);
}
