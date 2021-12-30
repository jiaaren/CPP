#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "Form.hpp"

class Intern
{
public:
    Intern(void);
    Intern(Intern const &i);
    ~Intern(void);
    Intern &operator=(Intern const &rhs);
    Form *makeForm(std::string const &name, std::string const &target) const;
};

#endif
