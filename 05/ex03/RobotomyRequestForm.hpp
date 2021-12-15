#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

#ifndef CONST
#define CONST

#define MIN_SIGN 72
#define MIN_EXEC 45
#define FORM_NAME "robotomy request"

#endif

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm const &f);
    virtual ~RobotomyRequestForm(void);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
    // execution
    virtual void execute(Bureaucrat const &executor) const;
};

#endif
