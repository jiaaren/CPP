/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:52:41 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/03 02:07:21 by jkhong           ###   ########.fr       */
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

private:
    int _fpval;
    static int const _frac_bits;
};

// outside
std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif