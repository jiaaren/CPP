/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:18:00 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 01:50:36 by jkhong           ###   ########.fr       */
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
    std::cout << "middle" << std::endl;
    check_point(0.0124124f, 4.012421432f);
    check_point(1.0f, 6.0f);
    std::cout << "\n";
    // edge
    std::cout << "edge" << std::endl;
    check_point(-4.0f, 2.0f);
    check_point(0.0f, -3.0f);
    check_point(3.0f, 6.0f);
    std::cout << "\n";
    // a little in edge
    std::cout << "little in edge" << std::endl;
    check_point(-1.99f, 4.0f);
    check_point(0.0f, 3.05f);
    check_point(2.9f, 6.0f);
    std::cout << "\n";
    // a little over edge
    std::cout << "little over edge" << std::endl;
    check_point(-2.05f, 4.0f);
    check_point(0.0f, 2.95f);
    check_point(3.05f, 6.0f);
    std::cout << "\n";
    return (0);
}
