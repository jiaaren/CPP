#include "Fixed.hpp"
#include <iostream>

int main(void)
{

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}

// int main(void)
// {
//     std::cout << std::boolalpha << (Fixed(1) < Fixed(2)) << std::endl;
//     std::cout << std::boolalpha << (Fixed(1) > Fixed(2)) << std::endl;
//     std::cout << std::boolalpha << (Fixed(1) > Fixed(1)) << std::endl;
//     std::cout << std::boolalpha << (Fixed(1) >= Fixed(1)) << std::endl;
//     std::cout << std::boolalpha << (Fixed(1) <= Fixed(2)) << std::endl;
//     std::cout << std::boolalpha << (Fixed(1) == Fixed(1)) << std::endl;
//     std::cout << std::boolalpha << (Fixed(1) == Fixed(2)) << std::endl;
//     std::cout << std::boolalpha << (Fixed(1) != Fixed(2)) << std::endl;
//     std::cout << std::endl;
//     // ok
//     std::cout << (Fixed(5.05f) * Fixed(2)) << std::endl;
//     return (0);
// }
