#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

#ifndef CONST
#define CONST

#define MIN_SIGN 145
#define MIN_EXEC 137
#define FORM_NAME "shrubbery creation"

#endif

class ShrubberyCreationForm : public Form
{
public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &scf);
    virtual ~ShrubberyCreationForm(void);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
    // executor
    virtual void execute(Bureaucrat const &executor) const;
};

#endif
