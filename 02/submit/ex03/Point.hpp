/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 02:01:08 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 17:24:59 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
    Point(void);
    Point(Point const &p);
    Point(const float x, const float y);
    ~Point(void);

    Point operator=(Point const &rhs);
    Fixed getX(void) const;
    Fixed getY(void) const;

private:
    Fixed const _x;
    Fixed const _y;
};

#endif
