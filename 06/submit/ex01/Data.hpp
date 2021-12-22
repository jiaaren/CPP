#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <stdexcept>

typedef unsigned long int uintptr_t;

class Data
{
private:
    std::string _surname;
    int _age;
    char _gender;

public:
    Data(std::string surname, int age, char gender);
    // getter
    std::string getSurname(void) const;
    int getAge(void) const;
    char getGender(void) const;
    class invalidInput : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif
