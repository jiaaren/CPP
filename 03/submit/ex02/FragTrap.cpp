/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:41:37 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 00:53:59 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
    // don't think we can intiialise through above for derived variables
    this->_hp = 100;
    this->_ep = 100;
    this->_atk = 30;
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
        std::cout << "FragTrap " << this->_name << " attacks "
                  << target << " for " << this->_atk << " damage" << std::endl;
        this->reduce_ep(this->_atk);
    }
    return;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " requests high fives from its comrades"
              << std::endl;
    if (!this->check_ep(25))
        std::cout << "FragTrap " << this->_name << " receives no responses :(" << std::endl;
    else
    {
        std::cout << "FragTrap " << this->_name << " feels validated :)" << std::endl;
        this->reduce_ep(25);
    }
    return;
}

#endif
