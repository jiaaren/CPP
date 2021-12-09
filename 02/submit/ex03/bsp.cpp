/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:45:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 16:03:51 by jkhong           ###   ########.fr       */
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
    // std::cout << totalArea << std::endl;
    // std::cout << Area1 << std::endl;
    // std::cout << Area2 << std::endl;
    // std::cout << Area3 << std::endl;
    // std::cout << (Area1 + Area2 + Area3) << std::endl;
    if ((totalArea == (Area1 + Area2 + Area3)))
        return (true);
    return (false);
}
