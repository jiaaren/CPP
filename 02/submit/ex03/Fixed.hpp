/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:52:41 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/03 20:27:53 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <ostream>

class Fixed
{
public:
    Fixed(void);
    Fixed(Fixed const &n);
    Fixed(int const n);
    Fixed(float const f);
    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    // conditions
    bool operator>(Fixed const &rhs) const;
    bool operator<(Fixed const &rhs) const;
    bool operator>=(Fixed const &rhs) const;
    bool operator<=(Fixed const &rhs) const;
    bool operator==(Fixed const &rhs) const;
    bool operator!=(Fixed const &rhs) const;

    // arithmetic
    Fixed operator+(Fixed const &rhs) const;
    Fixed operator-(Fixed const &rhs) const;
    Fixed operator*(Fixed const &rhs) const;
    Fixed operator/(Fixed const &rhs) const;

    // prefix 
    Fixed &operator++(void);
    Fixed &operator--(void);
    // postfix -> int within brackets == postfix
    Fixed operator++(int);
    Fixed operator--(int);

    static Fixed &min(Fixed &a, Fixed &b);
    // don't really understand the const requirement
    //  i.e. why need const?  static Fixed &const min(Fixed &const a, Fixed &const b); -> why couldn't i do this?
    const static Fixed &min(Fixed const &a, Fixed const &b);
    static Fixed &max(Fixed &a, Fixed &b);
    const static Fixed &max(Fixed const &a, Fixed const &b);

private:
    int _fpval;
    static int const _frac_bits;
};

// outside
std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
