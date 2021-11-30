/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:46:29 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/28 22:53:34 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

void Karen::debug(void)
{
	std::cout << "[DEBUG]" << std::endl
			  << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
			  << "I just love it!" << std::endl;
}

void Karen::info(void)
{
	std::cout << "[INFO]" << std::endl
			  << "I cannot believe adding extra bacon cost more money." << std::endl
			  << "You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "[WARNING]" << std::endl
			  << "I think I deserve to have some extra bacon for free." << std::endl
			  << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(void)
{
	std::cout << "[ERROR]" << std::endl
			  << "This is unacceptable, I want to speak to the manager now." << std::endl;
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
		this->debug();
		std::cout << std::endl;
	case (INFO):
		this->info();
		std::cout << std::endl;
	case (WARNING):
		this->warning();
		std::cout << std::endl;
	case (ERROR):
		this->error();
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return;
}
