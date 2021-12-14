#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

#define MIN_SIGN 145
#define MIN_EXEC 137

class ShrubberyCreationForm : public Form
{
private:
    std::string const _target;
    // replace here with private function

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &scf);
    virtual ~ShrubberyCreationForm(void);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
    // getter
    std::string getTarget(void) const;
    // exec
    void execute(Bureaucrat const &executor);
};

#endif
