#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

#ifndef CONST
#define CONST

#define MIN_SIGN 25
#define MIN_EXEC 5
#define FORM_NAME "presidential pardon"

#endif

class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &f);
    virtual ~PresidentialPardonForm(void);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
    // execution
    virtual void execute(Bureaucrat const &executor) const;
};

#endif
