#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    std::cout << "Intern created" << std::endl;
    return;
}

Intern::Intern(Intern const &i)
{
    (void)i;
    std::cout << "Intern created" << std::endl;
    return;
}

Intern::~Intern(void)
{
    std::cout << "Intern destroyed" << std::endl;
    return;
}

Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return (*this);
}

Form *Intern::makeForm(std::string const &name, std::string const &target) const
{
    const char *form_names[] = {"shrubbery creation", "robotomy request", "presidential pardon", NULL};
    int i = -1;

    while (form_names[++i])
        if (name.compare(form_names[i]) == 0)
            break;
    switch (i)
    {
    case 0:
        return new ShrubberyCreationForm(target);
        break;
    case 1:
        return new RobotomyRequestForm(target);
        break;
    case 2:
        return new PresidentialPardonForm(target);
        break;
    default:
        std::cout << "Form name doesn't exist, Intern could not find form :(" << std::endl;
    }
    return (NULL);
}
