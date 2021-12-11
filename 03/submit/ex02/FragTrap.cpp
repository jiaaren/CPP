/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:41:37 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 12:21:12 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
    this->_hp = 100;
    this->_ep = 100;
    this->_atk = 30;
    this->_clapName = "FragTrap";
    std::cout << "FragTrap " << name << " initiated" << std::endl;
    return;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
    return;
}

void FragTrap::attack(std::string const &target)
{
    if (this->check_ep(this->_atk))
    {
        std::cout << this->getFullName() << " hugs "
                  << target << " for " << this->_atk << " damage" << std::endl;
        this->reduce_ep(this->_atk);
    }
    return;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << this->getFullName() << " requests high fives from its comrades"
              << std::endl;
    if (!this->check_ep(25))
        std::cout << this->getFullName() << " receives no responses :(" << std::endl;
    else
    {
        std::cout << this->getFullName() << " feels validated :)" << std::endl;
        this->reduce_ep(25);
    }
    return;
}

#endif
