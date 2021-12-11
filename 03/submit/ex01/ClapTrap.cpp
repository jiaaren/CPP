/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:32:16 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 22:55:50 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const name) : _name(name), _clapName("ClapTrap"),
                                             _maxHp(10), _maxEp(10),
                                             _hp(_maxHp), _ep(_maxEp), _atk(0)
{
    std::cout << "ClapTrap " << _name << " initiated" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const &ct)
{
    *this = ct;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
    return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    _name = rhs.getName();
    _clapName = rhs.getClapName();
    _hp = rhs.getHp();
    _ep = rhs.getEp();
    _atk = rhs.getAtk();
    _maxHp = rhs.getMaxHp();
    _maxEp = rhs.getMaxEp();
    return (*this);
}

std::string ClapTrap::getFullName(void) const
{
    return (_clapName + " " + _name);
}

bool ClapTrap::check_ep(unsigned int const amount) const
{
    if ((unsigned int)(_ep) < amount)
    {
        std::cout
            << getFullName() << " has insufficient energy points. "
            << amount - _ep << " more required" << std::endl;
        return (false);
    }
    return (true);
}

void ClapTrap::reduce_ep(unsigned int const amount)
{
    if ((unsigned int)(_ep) >= amount)
    {
        _ep -= amount;
        std::cout << "* " << _ep << "(-" << amount << ") "
                  << "energy points remaining" << std::endl;
    }
}

void ClapTrap::attack(std::string const &target)
{
    if (check_ep(_atk))
    {
        std::cout << getFullName() << " attacks "
                  << target << " for " << _atk << " damage" << std::endl;
        reduce_ep(_atk);
    }
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    int damage;

    if (_hp <= 0)
    {
        std::cout << getFullName()
                  << " does not have any health!" << std::endl;
        return;
    }
    damage = (unsigned int)_hp < amount ? _hp : amount;
    _hp -= damage;
    std::cout << getFullName() << " takes "
              << damage << " amount(s) of damage. "
              << "Now with " << _hp << " health" << std::endl;
    return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (check_ep(amount))
    {
        _hp += amount;
        std::cout << getFullName() << " gets repaired for " << amount << ". "
                  << "Now with " << _hp << " health" << std::endl;
        reduce_ep(amount);
    }
    return;
}

std::string ClapTrap::getName(void) const
{
    return (_name);
}

std::string ClapTrap::getClapName(void) const
{
    return (_clapName);
}

int ClapTrap::getHp(void) const
{
    return (_hp);
}

int ClapTrap::getEp(void) const
{
    return (_ep);
}

int ClapTrap::getAtk(void) const
{
    return (_atk);
}

int ClapTrap::getMaxHp(void) const
{
    return (_maxHp);
}

int ClapTrap::getMaxEp(void) const
{
    return (_maxEp);
}
