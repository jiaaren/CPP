/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:46:29 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 23:21:41 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

Karen::Karen(void)
{
    return;
}

Karen::~Karen(void)
{
    return;
}

void Karen::_debug(void)
{
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I just love it!" << std::endl;
}

void Karen::_info(void)
{
    std::cout << "I cannot believe adding extra bacon cost more money. "
              << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::_error(void)
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
    std::string complaints[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    e_level levels;

    levels = (e_level)0;
    for (int i = 0; i < 4; i++)
    {
        if (level.compare(complaints[i]) == 0)
            break;
        levels = (e_level)((int)levels + 1);
    }
    // default for no case match
    switch (levels)
    {
    case (DEBUG):
        this->_debug();
        break;
    case (INFO):
        this->_info();
        break;
    case (WARNING):
        this->_warning();
        break;
    case (ERROR):
        this->_error();
        break;
    default:
        break;
    }
    return;
}
