/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:52:41 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 02:01:59 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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

// outside of class
std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
