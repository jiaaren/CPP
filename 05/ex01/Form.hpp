#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const _name;
    bool _signed;
    int const _gradeToSign;
    int const _gradeToExec;
    void _constructorPrint(void) const;

public:
    Form(void);
    Form(Form const &f);
    Form(std::string name, int gradeToSign, int gradeToExec);
    ~Form(void);
    Form &operator=(Form const &rhs);
    // getters
    std::string getName(void) const;
    bool getSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExec(void) const;
    // setter
    void beSigned(Bureaucrat const &b);
    // check grade
    void checkGrade(int const &grade) const;
    // exception classes
    class GradeTooHighException : public Bureaucrat::GradeTooHighException
    {
    };
    class GradeTooLowException : public Bureaucrat::GradeTooLowException
    {
    };
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
