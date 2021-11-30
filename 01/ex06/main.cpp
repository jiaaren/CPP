/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:25:42 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/28 22:53:53 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "./karenFilter [log level]" << std::endl;
        return (1);
    }
    Karen karen;
    karen.complain(argv[1]);
    return (0);
}