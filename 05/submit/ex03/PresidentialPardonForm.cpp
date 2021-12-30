#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form(FORM_NAME, MIN_SIGN, MIN_EXEC)
{
    setTarget("self");
    std::cout << FORM_NAME << " form, targetted to " << getTarget() << ", created" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form(FORM_NAME, MIN_SIGN, MIN_EXEC)
{
    setTarget(target);
    std::cout << FORM_NAME << " form, targetted to " << getTarget() << ", created" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &f) : Form(FORM_NAME, MIN_SIGN, MIN_EXEC)
{
    *this = f;
    std::cout << FORM_NAME << " form, targetted to " << getTarget() << ", created" << std::endl;
    return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << FORM_NAME << " form, destroyed" << std::endl;
    return;
}

// not sure if this would work, or would have a better way
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    Form::operator=(rhs);
    setTarget(rhs.getTarget());
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!(getSigned()))
    {
        std::cout << "Form not yet signed" << std::endl;
        return;
    }
    checkExec(executor);
    std::cout << "Action: " << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
    return;
}
