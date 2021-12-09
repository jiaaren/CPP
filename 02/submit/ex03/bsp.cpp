/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:45:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 01:09:47 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include <cmath>
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

bool bsp_worse(Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = calcTriangleArea(a, b, c);
    Fixed Area1 = calcTriangleArea(a, b, point);
    Fixed Area2 = calcTriangleArea(a, c, point);
    Fixed Area3 = calcTriangleArea(b, c, point);
    if ((totalArea != (Area1 + Area2 + Area3)) || Area1 == 0.0f || Area2 == 0.0f || Area3 == 0.0f)
        return (false);
    return (true);
}

Point **cartesian_to_polar(Point const a, Point const b, Point const c, Point const point)
{
    Point arr[4] = {a, b, c, point};
    Fixed least_x(0);
    Fixed least_y(0);
    for (int i = 0; i < 4; i++)
    {
        if (arr[i].getX() < least_x)
            least_x = arr[i].getX();
        if (arr[i].getY() < least_y)
            least_y = arr[i].getY();
    }
    static Point *new_coor[4];
    for (int i = 0; i < 4; i++)
    {
        new_coor[i] = new Point(arr[i].getX().toFloat() + roundf(-(least_x.toFloat()) + 1)
                        , arr[i].getY().toFloat() + roundf(-(least_y.toFloat()) + 1));
    }
    return (new_coor);
}

// Gamedev maths - point in triangle
// https://www.youtube.com/watch?v=HYAgJN3x4GA&t=134s
bool inTriangle(Point a, Point b, Point c, Point point)
{
    Fixed s1 = c.getY() - a.getY();
    Fixed s2 = c.getX() - a.getX();
    Fixed s3 = b.getY() - a.getY();
    Fixed s4 = point.getY() - a.getY();
    Fixed s5 = b.getX() - a.getX();

    Fixed w1 = ((a.getX() * s1) + (s4 * s2) - (point.getX() * s1)) / ((s3 * s2) - (s5 * s1));
    Fixed w2 = (s4 - (w1 * s3)) / s1;
    return (w1.toFloat() > 0.0f && w2.toFloat() > 0.0f && (w1.toFloat() + w2.toFloat()) < 1.0f);
}

// no difference between cartesian and polar
bool bsp_w_polar(Point const a, Point const b, Point const c, Point const point)
{
    Point **new_coor = cartesian_to_polar(a, b, c, point);
    bool res = inTriangle(*new_coor[0], *new_coor[1], *new_coor[2], *new_coor[3]);
    for (int i = 0; i < 4; i++)
        delete new_coor[i];
    return (res);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    return(inTriangle(a, b, c, point));
}
