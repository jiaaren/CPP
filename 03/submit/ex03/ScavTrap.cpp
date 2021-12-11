/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:41:37 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 12:14:58 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
    // don't think we can intiialise through above for derived variables
    this->_hp = 100;
    this->_ep = 50;
    this->_atk = 20;
    this->_clapName = "ScavTrap";
    std::cout << "ScavTrap " << name << " initiated" << std::endl;
    return;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
    return;
}

void ScavTrap::attack(std::string const &target)
{
    if (this->check_ep(this->_atk))
    {
        std::cout << this->getFullName() << " tickles "
                  << target << " for " << this->_atk << " damage" << std::endl;
        this->reduce_ep(this->_atk);
    }
    return;
}

void ScavTrap::guardGate(void)
{
    std::cout << this->getFullName() << " has entered 'Gate keeper' mode"
              << std::endl;
    if (this->_ep < 50)
    {
        std::cout << this->getFullName() << " restores " << (50 - this->_ep) << " energy points. ";
        this->_ep = 50;
        std::cout << "Now with " << this->_ep << " ep" << std::endl;
    }
    return;
}
