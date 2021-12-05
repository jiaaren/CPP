/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 00:51:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 01:33:02 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

// no default constructor exists for class "ClapTrap"
// if virtual keyword present
DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name), FragTrap(name), ScavTrap(name), _clap_name("DiamondTrap")
{
    ClapTrap::_name = _name + _clap_name;
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

void DiamondTrap::whoAmI(void) const
{
    std::cout << "I am " << this->_clap_name << " " << this->_name << std::endl;
    return;
}