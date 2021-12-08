/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:52:41 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 02:01:48 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
    Fixed(void);
    Fixed(Fixed const &n);
    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _fpval;
    static int const _frac_bits;
};

#endif
