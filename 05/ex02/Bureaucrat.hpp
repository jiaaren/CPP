#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Form;

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;

public:
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &b);
    ~Bureaucrat(void);
    Bureaucrat &operator=(Bureaucrat const &rhs);
    // getters
    std::string getName(void) const;
    int getGrade(void) const;
    // setter
    void setGrade(int const &grade);
    // decrement and increment grade
    void incrementGrade(unsigned int const &amt);
    void decrementGrade(unsigned int const &amt);
    // check grade
    void checkGrade(int const &grade) const;
    // actions
    void signForm(Form &f); // no const
    void executeForm(Form const &form);
    // exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what(void) const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs);

#endif
