#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("(none)"), _signed(false),
                   _gradeToSign(MIN_GRADE), _gradeToExec(MIN_GRADE)
{
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExec);
    _constructorPrint();
    return;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false),
                                                                 _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExec);
    _constructorPrint();
    return;
}

Form::Form(Form const &f) : _name(f.getName()), _signed(f.getSigned()),
                            _gradeToSign(f.getGradeToSign()), _gradeToExec(f.getGradeToExec())
{
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExec);
    _constructorPrint();
    return;
}

void Form::_constructorPrint(void) const
{
    std::cout << "Form " << _name << " created. "
              << "status: ( signed: " << std::boolalpha << _signed << ", "
              << "gradeToSign: " << _gradeToSign << ", gradeToExec: " << _gradeToExec
              << " )" << std::endl;
    return;
}

// Form::~Form(void)
// {
//     std::cout << "Form " << _name << " destructed." << std::endl;
//     return;
// }

Form &Form::operator=(Form const &rhs)
{
    _signed = rhs.getSigned();
    return (*this);
}

void Form::beSigned(Bureaucrat const &b)
{
    if (_signed)
    {
        std::cout << "Form already signed" << std::endl;
        return;
    }
    if (_gradeToSign < b.getGrade())
    {
        std::cout << "Bureaucrat too low grade to sign form" << std::endl;
        throw GradeTooLowException();
    }
    std::cout << "Bureaucrat " << b.getName() << " (Grade: " << b.getGrade() << ")"
              << " has signed form " << _name << " (Grade: " << _gradeToSign << ")"
              << std::endl;
    _signed = true;
    return;
}

void Form::setTarget(std::string const &target)
{
    _target = target;
    return;
}

std::string Form::getName(void) const
{
    return (_name);
}

bool Form::getSigned(void) const
{
    return (_signed);
}

int Form::getGradeToSign(void) const
{
    return (_gradeToSign);
}

int Form::getGradeToExec(void) const
{
    return (_gradeToExec);
}

std::string Form::getTarget(void) const
{
    return (_target);
}

void Form::checkGrade(int const &grade) const
{
    if (grade < MAX_GRADE)
        throw GradeTooHighException();
    if (grade > MIN_GRADE)
        throw GradeTooLowException();
    return;
}

void Form::checkExec(Bureaucrat const &executor) const
{
    if (_gradeToExec < executor.getGrade())
    {
        std::cout << "Bureaucrat too low grade to execute form" << std::endl;
        throw GradeTooLowException();
    }
    return;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
    o << "Form " << rhs.getName() << ". "
      << "status: ( signed: " << std::boolalpha << rhs.getSigned() << ", "
      << "gradeToSign: " << rhs.getGradeToSign() << ", gradeToExec: " << rhs.getGradeToExec()
      << " )";
    return (o);
}
