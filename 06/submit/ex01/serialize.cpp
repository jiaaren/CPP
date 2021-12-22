#include <string>
#include <iostream>
#include <stdexcept>
#include <bitset>
#include "Data.hpp"

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
    return "Invalid input, cannot construct Data class";
}

/*
    1. Serializing data requiring the following bytes:
    a. gender - 1 byte
    b. age - 1 byte (since lowest is 1 and highest is 150, much lower than max unsigned char val of 255)
    c. surname - 6 bytes -> min surname length is 1 and max 6
    Total bytes = 8 bytes, i.e. size of uintptr_t

    Serializing gender (e.g. Male 'M'), and left shift by 1 byte (8 bits)
    I.    00000000 00000000 00000000 00000000 00000000 00000000 00000000 01001101
    II.   00000000 00000000 00000000 00000000 00000000 00000000 01001101 00000000

    Serializing age (e.g. 25), and left shift by 6 bytes
    III.  00000000 00000000 00000000 00000000 00000000 00000000 01001101 00011001
    IV.   01001101 00011001 00000000 00000000 00000000 00000000 00000000 00000000

    Creating new bitset to store surname bits (e.g. Khong) - bits are filled from back to front
         |                          |  g     |   n    |   o    |   h    |   K    |
    V.    00000000 00000000 00000000 01100111 01101110 01101111 01101000 01001011

    Bit operator OR to combine gender-age with surname
         | Gender |  Age   |                     Surname                         |
    VI.   01001101 00011001 00000000 01100111 01101110 01101111 01101000 01001011
    V. Convert to ulong() and return
*/
uintptr_t serialize(Data *ptr)
{
    // serialize (i) gender, (ii) age, (iii) surname
    std::bitset<BITS * 8> tmp;
    // serialize gender (OR bitwise operator)
    tmp = (tmp |= std::bitset<BITS * 8>(ptr->getGender()));
    // serialize age (OR bitwise operator)
    tmp = (tmp << BITS) |= std::bitset<BITS * 8>(ptr->getAge());
    // serialize name: (i) initialise std::string and surname_bits
    std::string sn = ptr->getSurname();
    std::bitset<BITS * 8> surname_bits;
    // use bitwise operator to input into surname_bits
    for (int i = 5; i >= 0; i--)
    {
        if (i <= (int)sn.length() - 1)
            surname_bits = surname_bits |= std::bitset<BITS * 8>(sn[i]);
        if (i != 0)
            surname_bits = surname_bits << BITS;
    }
    tmp = (tmp << BITS * 6) |= surname_bits;
    return (tmp.to_ulong());
}

/*
    Deserialize (using example from above)
        | Gender |  Age   |                     Surname                         |
        01001101 00011001 00000000 01100111 01101110 01101111 01101000 01001011
    I. deserialize gender (left shift to end and cast to char *)
                                                                   | Gender |
        00000000 00000000 00000000 00000000 00000000 00000000 00000000 01001101
    II. deserialize age (left shift to end and cast to unsigned char *)
        this since pointer is unsigned char *, dereferencing it or indexing to [0] will retrieve left most byte
                                                             | Gender |  Age  |
        00000000 00000000 00000000 00000000 00000000 00000000 01001101 00011001
    III. deserialize surname (left by 2 to remove gender and age, and right shift by 2)
        |                   Surname                          |
        00000000 01100111 01101110 01101111 01101000 01001011 00000000 00000000
                |  NUL   |                   Surname                           |
        00000000 00000000 00000000 01100111 01101110 01101111 01101000 01001011
*/
Data *deserialize(uintptr_t raw)
{
    uintptr_t gender_raw = raw >> (BITS * 7);
    char gender = *(reinterpret_cast<char *>(&gender_raw));
    uintptr_t age_raw = raw >> (BITS * 6);
    unsigned char age = *(reinterpret_cast<unsigned char *>(&age_raw));
    // this will be indirectly NUL terminated since after bitshift right, there will be 2 NUL bytes at end
    uintptr_t surname_raw = (raw << (BITS * 2)) >> (BITS * 2);
    std::string surname(reinterpret_cast<char *>(&surname_raw));
    return (new Data(surname, age, gender));
}
