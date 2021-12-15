#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form(FORM_NAME, MIN_SIGN, MIN_EXEC)
{
    setTarget("self");
    std::cout << FORM_NAME << " form, targetted to " << getTarget() << ", created" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form(FORM_NAME, MIN_SIGN, MIN_EXEC)
{
    setTarget(target);
    std::cout << FORM_NAME << " form, targetted to " << getTarget() << ", created" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &f) : Form(FORM_NAME, MIN_SIGN, MIN_EXEC)
{
    *this = f;
    std::cout << FORM_NAME << " form, targetted to " << getTarget() << ", created" << std::endl;
    return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << FORM_NAME << " form, destroyed" << std::endl;
    return;
}

// not sure if this would work, or would have a better way
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    Form::operator=(rhs);
    setTarget(rhs.getTarget());
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!(getSigned()))
    {
        std::cout << "Form not yet signed" << std::endl;
        return;
    }
    checkExec(executor);
    // Use current time as seed for random generator
    srand(time(0));
    int success = rand() % 2;
    if (success)
        std::cout << "Rizzzzzzzz, target " << getTarget() << " has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << "Failed to robotomize target " << getTarget() << std::endl;
    return;
}
