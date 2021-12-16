#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("(no name)"), _grade(MIN_GRADE)
{
    std::cout << "Bureaucrat " << _name << " (grade " << _grade << ") created" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    checkGrade(grade);
    std::cout << "Bureaucrat " << _name << " (grade " << _grade << ") created" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &b) : _name(b.getName()), _grade(b.getGrade())
{
    *this = b;
    std::cout << "Bureaucrat " << _name << " assigned with grade " << _grade << std::endl;
    return;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat " << _name << " has died" << std::endl;
    return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    _grade = rhs.getGrade();
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void Bureaucrat::setGrade(int const &grade)
{
    checkGrade(grade);
    _grade = grade;
    return;
}

void Bureaucrat::incrementGrade(void)
{
    checkGrade(_grade - 1);
    _grade -= 1;
    return;
}

void Bureaucrat::decrementGrade(void)
{
    checkGrade(_grade + 1);
    _grade += 1;
    return;
}

void Bureaucrat::checkGrade(int const &grade) const
{
    if (grade < MAX_GRADE)
        throw GradeTooHighException();
    if (grade > MIN_GRADE)
        throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &f)
{
    if (f.getSigned())
    {
        std::cout << "Form already signed" << std::endl;
        return;
    }
    if (_grade > f.getGradeToSign())
    {
        std::cout << "Bureaucrat " << _name << " (grade: " << _grade << ") "
                  << "cannot sign form " << f.getName() << " (grade: " << f.getGradeToSign() << ") "
                  << "Grade too low" << std::endl;
        return;
    }
    f.beSigned(*this);
    return;
}

void Bureaucrat::executeForm(Form const &form)
{
    if (!(form.getSigned()))
    {
        std::cout << "Form not yet signed" << std::endl;
        return;
    }
    if (_grade > form.getGradeToExec())
    {
        std::cout << "Bureaucrat " << _name << " (grade: " << _grade << ") "
                  << "cannot execute form " << form.getName() << " (grade: " << form.getGradeToSign() << ") "
                  << "Grade too low" << std::endl;
        return;
    }
    form.execute(*this);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "Grade will be too high, operation not allowed";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "Grade will be too low, operation not allowed";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat : grade " << rhs.getGrade();
    return (o);
}
