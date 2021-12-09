/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:45:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 16:43:33 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

Fixed calcTriangleArea(Point const &a, Point const &b, Point const &c)
{
    Fixed det;
    det = ((a.getX() - c.getX()) * (b.getY() - c.getY())) - ((b.getX() - c.getX()) * (a.getY() - c.getY()));
    if (det < 0)
        return (-det);
    return (det);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = calcTriangleArea(a, b, c);
    Fixed Area1 = calcTriangleArea(a, b, point);
    Fixed Area2 = calcTriangleArea(a, c, point);
    Fixed Area3 = calcTriangleArea(b, c, point);
    if ((totalArea != (Area1 + Area2 + Area3))
        || Area1 == 0.0f || Area2 == 0.0f || Area3 == 0.0f)
        return (false);
    return (true);
}
