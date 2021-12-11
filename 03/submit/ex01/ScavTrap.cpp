/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:41:37 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 23:27:08 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name),
                                             _trapMaxHp(100), _trapMaxEp(50), _trapMaxAtk(20)
{
    _hp = _maxHp = _trapMaxHp;
    _ep = _maxEp = _trapMaxEp;
    _atk = _trapMaxAtk;
    _clapName = "ScavTrap";
    std::cout << "ScavTrap " << name << " initiated" << std::endl;
    return;
}

// initialise base class as well
// https://stackoverflow.com/questions/25056430/how-do-i-call-parent-class-copy-constructors
ScavTrap::ScavTrap(ScavTrap const &st) : ClapTrap(st),
                                         _trapMaxHp(100), _trapMaxEp(20), _trapMaxAtk(20)
{
    *this = st;
    return;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << _name << " destroyed" << std::endl;
    return;
}

// https://stackoverflow.com/questions/4734846/calling-operators-of-base-class-safe
ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
    ClapTrap::operator=(rhs);
    return (*this);
}

void ScavTrap::attack(std::string const &target)
{
    if (check_ep(_atk))
    {
        std::cout << getFullName() << " tickles "
                  << target << " for " << _atk << " damage" << std::endl;
        reduce_ep(_atk);
    }
    return;
}

void ScavTrap::guardGate(void)
{
    std::cout << getFullName() << " has entered 'Gate keeper' mode"
              << std::endl;
    if (_ep < ClapTrap::_maxEp)
    {
        std::cout << getFullName() << " restores " << (_maxEp - _ep) << " energy points. ";
        _ep = ClapTrap::_maxEp;
        std::cout << "Now with " << _ep << " ep" << std::endl;
    }
    return;
}
