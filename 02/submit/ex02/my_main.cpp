/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:38:21 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 01:47:17 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    std::cout << std::boolalpha << (Fixed(1) < Fixed(2)) << std::endl;
    std::cout << std::boolalpha << (Fixed(1) > Fixed(2)) << std::endl;
    std::cout << std::boolalpha << (Fixed(1) > Fixed(1)) << std::endl;
    std::cout << std::boolalpha << (Fixed(1) >= Fixed(1)) << std::endl;
    std::cout << std::boolalpha << (Fixed(1) <= Fixed(2)) << std::endl;
    std::cout << std::boolalpha << (Fixed(1) == Fixed(1)) << std::endl;
    std::cout << std::boolalpha << (Fixed(1) == Fixed(2)) << std::endl;
    std::cout << std::boolalpha << (Fixed(1) != Fixed(2)) << std::endl;
    std::cout << std::endl;
    std::cout << Fixed::max(Fixed(1.01f), Fixed(1.02f)) << std::endl;
    std::cout << Fixed::min(Fixed(1.01f), Fixed(1.02f)) << std::endl;
    std::cout << std::endl;
    Fixed a(100);
    Fixed b(5);
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << b++ << std::endl;
    std::cout << b << std::endl;
    std::cout << ++b << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl;
    std::cout << (Fixed(5.05f) / Fixed(3)) << std::endl;
    return (0);
}
