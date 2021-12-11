/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 00:51:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 12:51:46 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

// no default constructor exists for class "ClapTrap"
// if virtual keyword present
DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    ClapTrap::_name = name + " DiamondTrap";
    this->_clapName = "DiamondTrap";
    DiamondTrap::_name = name;
    this->_hp = FragTrap::_hp;
    this->_ep = ScavTrap::_ep;
    this->_atk = FragTrap::_atk;
    std::cout << "DiamondTrap " << name << " initiated" << std::endl;
    return;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
    return;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->_name << " destroyed" << std::endl;
    return;
}

std::string DiamondTrap::getFullName(void) const
{
    return (this->_clapName + " " + this->_name);
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << "I am " << this->getFullName() << std::endl;
    return;
}
