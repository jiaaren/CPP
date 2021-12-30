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
    std::string _target;
    void _constructorPrint(void) const;

public:
    Form(void);
    Form(Form const &f);
    Form(std::string name, int gradeToSign, int gradeToExec);
    virtual ~Form(void){};
    Form &operator=(Form const &rhs);
    // getters
    std::string getName(void) const;
    bool getSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExec(void) const;
    std::string getTarget(void) const;
    // setter
    void beSigned(Bureaucrat const &b);
    void setTarget(std::string const &target);
    // check grade
    void checkGrade(int const &grade) const;
    void checkExec(Bureaucrat const &executor) const;
    // action
    virtual void execute(Bureaucrat const &executor) const = 0;
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
