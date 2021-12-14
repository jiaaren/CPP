#include <iostream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : _target("self"),
                                                     Form("ShrubberyCreationForm", MIN_SIGN, MIN_EXEC)
{
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : _target(target),
                                                                          Form("ShrubberyCreationForm", MIN_SIGN, MIN_EXEC)
{
    return;
}