/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:59:28 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 01:25:52 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _fpval(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const &n)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = n;
    return;
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    // essentially n ^ 8
    this->setRawBits(n << _frac_bits);
    return;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    float tmp = f;
    for (int i = 0; i < _frac_bits; i++)
        tmp *= 2;
    this->setRawBits((int)roundf(tmp));
    return;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_fpval = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_fpval);
}

void Fixed::setRawBits(int const raw)
{
    this->_fpval = raw;
    return;
}

float Fixed::toFloat(void) const
{
    float tmp = (float)(this->getRawBits());
    for (int i = 0; i < _frac_bits; i++)
        tmp /= 2;
    return (tmp);
}

int Fixed::toInt(void) const
{
    return (this->toFloat());
}

int const Fixed::_frac_bits = 8;

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return (o);
}
