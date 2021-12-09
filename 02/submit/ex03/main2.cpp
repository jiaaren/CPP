/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:18:00 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 16:35:30 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

Point a(-4.0f, 2.0f);
Point b(2.0f, 8.0f);
Point c(4.0f, 4.0f);

void check_point(float x, float y)
{
    std::cout << std::boolalpha << bsp(a, b, c, Point(x, y)) << std::endl;
}

int main(void)
{
    // middle
    check_point(0.0f, 4.0f);
    // edge
    check_point(-2.0f, 4.01f);
    return (0);
}