/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:51:35 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 16:25:59 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

int main(void)
{
    Point a(1.0f, 1.0f);
    Point b(100.0f, 60.0f);
    Point c(50.0f, 4.0f);

    for (int i = 0; i < 65; i++)
    {
        for (int j = 0; j < 120; j++)
        {
            if (bsp(a, b, c, Point((float)j, (float)i)))
                std::cout << ' ';
            else
                std::cout << '@';
        }
        std::cout << std::endl;
    }
    return (0);
}
