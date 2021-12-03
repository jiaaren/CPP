/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:59:28 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/03 20:26:58 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) : _fpval(0)
{
    return;
}

Fixed::Fixed(Fixed const &n)
{
    *this = n;
    return;
}

Fixed::Fixed(int const n)
{
    // essentially n ^ 8
    this->_fpval = n << _frac_bits;
    return;
}

Fixed::Fixed(float const f)
{
    float tmp = f;
    for (int i = 0; i < 8; i++)
        tmp *= 2;
    this->_fpval = (int)(roundf(tmp));
    return;
}

Fixed::~Fixed(void)
{
    return;
}

// We can call other private variables of classes in another class's member functions
Fixed &Fixed::operator=(Fixed const &rhs)
{
    this->_fpval = rhs._fpval;
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
    float tmp = (float)(this->_fpval);
    for (int i = 0; i < 8; i++)
        tmp /= 2;
    return (tmp);
}

int Fixed::toInt(void) const
{
    return (this->toFloat());
}

bool Fixed::operator>(Fixed const &rhs) const
{
    return (this->_fpval > rhs._fpval);
}

bool Fixed::operator<(Fixed const &rhs) const
{
    return (this->_fpval < rhs._fpval);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
    return (this->_fpval >= rhs._fpval);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
    return (this->_fpval <= rhs._fpval);
}

bool Fixed::operator==(Fixed const &rhs) const
{
    return (this->_fpval == rhs._fpval);
}

bool Fixed::operator!=(Fixed const &rhs) const
{
    return (this->_fpval != rhs._fpval);
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
    Fixed tmp;
    tmp._fpval = this->_fpval + rhs._fpval;
    return (tmp);
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
    Fixed tmp;
    tmp._fpval = this->_fpval - rhs._fpval;
    return (tmp);
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
    Fixed tmp;
    tmp._fpval = this->_fpval * rhs.toFloat();
    return (tmp);
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
    Fixed tmp;
    tmp._fpval = this->_fpval / rhs.toFloat();
    return (tmp);
}

Fixed &Fixed::operator++(void)
{
    (this->_fpval)++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    (this->_fpval)++;
    return (tmp);
}

Fixed &Fixed::operator--(void)
{
    (this->_fpval)--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    (this->_fpval)--;
    return (tmp);
}

int const Fixed::_frac_bits = 8;

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (b < a)
        return (b);
    return (a);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (b < a)
        return (b);
    return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (b < a)
        return (b);
    return (a);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (b > a)
        return (b);
    return (a);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return (o);
}
