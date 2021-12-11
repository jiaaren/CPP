/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 00:51:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 23:59:12 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

// no default constructor exists for class "ClapTrap"
// if virtual keyword present
DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + " DiamondTrap"),
                                                   FragTrap(name + " DiamondTrap"),
                                                   ScavTrap(name + " DiamondTrap"),
                                                   _name(name)
{
    _clapName = "DiamondTrap";
    _hp = _maxHp = FragTrap::_trapMaxHp;
    _ep = _maxEp = ScavTrap::_trapMaxEp;
    _atk = FragTrap::_trapMaxAtk;
    std::cout << "DiamondTrap " << name << " initiated" << std::endl;
    return;
}

// use default getName because it already has "DiamondTrap" appended towards end of it
// use DiamondTrap getName for local _name
DiamondTrap::DiamondTrap(DiamondTrap const &dt) : ClapTrap(getName()),
                                                  FragTrap(getName()),
                                                  ScavTrap(getName()),
                                                  _name(dt.DiamondTrap::getName())
{
    *this = dt;
    return;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
    return;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
    return;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
    ClapTrap::operator=(rhs);
    // redundant for fragtrap and scavtrap because they do not have non-const attributes
    // FragTrap::operator=(rhs);
    // ScavTrap::operator=(rhs);

    // to specify DiamondTrap or else will refer to ClapTrap's getName
    _name = rhs.DiamondTrap::getName();
    return (*this);
}

std::string DiamondTrap::getFullName(void) const
{
    return (_clapName + " " + _name);
}

std::string DiamondTrap::getName(void) const
{
    return (_name);
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << "I am " << getFullName() << std::endl;
    return;
}
