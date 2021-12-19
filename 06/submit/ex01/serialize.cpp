
#include <string>
#include <iostream>
#include <stdexcept>
#include <bitset>
#include "Data.hpp"

#include <stdio.h>

#define BITS 8

/*
    typedef unsigned long uintptr_t
    uintptr_t has 8 bytes,
    1. 6 bytes allocated for surname
    2. 1 byte for age
    3. 1 byte for gender
*/

Data::Data(std::string surname, int age, char gender) : _surname(surname), _age(age), _gender(gender)
{
    if (surname.length() > 6 || surname.length() <= 0)
    {
        std::cout << "Invalid surname length, more than 6\n";
        throw invalidInput();
    }
    else if (age <= 0 || age > 150)
    {
        std::cout << "Invalid age, must be more than 0 or less than 150\n";
        throw invalidInput();
    }
    else if (gender != 'M' && gender != 'F')
    {
        std::cout << "Please enter either M or F for gender\n";
        throw invalidInput();
    }
    std::cout << "Data initiated with the following:\n"
              << "Surname: " << _surname << "\n"
              << "Age: " << static_cast<int>(_age) << "\n"
              << "Gender: " << _gender << "\n";
    return;
}

std::string Data::getSurname(void) const
{
    return (_surname);
}

int Data::getAge(void) const
{
    return (_age);
}

char Data::getGender(void) const
{
    return (_gender);
}

const char *Data::invalidInput::what() const throw()
{
    return "Invalid input, cannot construct Data class\n";
}

uintptr_t serialize(Data *ptr)
{
    // serialize (i) gender, (ii) age, (iii) surname
    std::bitset<BITS * 8> tmp;
    // serialize gender
    tmp = (tmp |= std::bitset<BITS * 8>(ptr->getGender()));
    // serialize age
    tmp = (tmp << BITS) |= std::bitset<BITS * 8>(ptr->getAge());
    // serialize name
    std::string sn = ptr->getSurname();

    // unused variblae
    // char *surname = const_cast<char *>(ptr->getSurname().data());
    // std::bitset<BITS * 6> *surname_bits = reinterpret_cast<std::bitset<BITS * 6> *>(surname);
    std::bitset<BITS * 8> surname_bits;

    // 6 bits
    for (int i = 5; i >= 0; i--)
    {
        if (i <= (int)sn.length() - 1)
            surname_bits = surname_bits |= std::bitset<BITS * 8>(sn[i]);
        if (i != 0)
            surname_bits = surname_bits << BITS;
    }
    // is this automatically null terminated?
    tmp = (tmp << BITS * 6) |= surname_bits;

    std::cout << tmp << std::endl;
    // std::cout << surname_bits << std::endl;

    return (tmp.to_ulong());
}

Data *deserialize(uintptr_t raw)
{
    uintptr_t gender_raw = raw >> (BITS * 7);
    char gender = *(reinterpret_cast<char *>(&gender_raw));
    uintptr_t age_raw = raw >> (BITS * 6);
    unsigned char age = *(reinterpret_cast<unsigned char *>(&age_raw));
    uintptr_t surname_raw = (raw << (BITS * 2)) >> (BITS * 2);
    std::string surname(reinterpret_cast<char *>(&surname_raw));

    // std::cout << "char: " << gender << std::endl;
    // std::cout << "age: " << static_cast<int>(age) << std::endl;
    // std::cout << "surname " << surname << std::endl;
    return (new Data(surname, age, gender));
}
