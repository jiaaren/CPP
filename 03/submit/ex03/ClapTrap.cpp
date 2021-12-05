/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:32:16 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/05 16:01:53 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const name) : _name(name), _hp(10), _ep(10), _atk(0)
{
    std::cout << "ClapTrap " << name << " initiated" << std::endl;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
    return;
}

bool ClapTrap::check_ep(unsigned int const amount) const
{
    if ((unsigned int)(this->_ep) < amount)
    {
        std::cout << "Insufficient energy points. "
                  << amount - this->_ep << " more required" << std::endl;
        return (false);
    }
    return (true);
}

void ClapTrap::reduce_ep(unsigned int const amount)
{
    if ((unsigned int)(this->_ep) >= amount)
    {
        this->_ep -= amount;
        std::cout << this->_ep << "(-" << amount << ") "
                  << "energy points remaining" << std::endl;
    }
}

void ClapTrap::attack(std::string const &target)
{
    if (this->check_ep(this->_atk))
    {
        std::cout << "ClapTrap " << this->_name << " attacks "
                  << target << " for " << this->_atk << " damage" << std::endl;
        this->reduce_ep(this->_atk);
    }
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hp <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " does not have any health!" << std::endl;
        return;
    }
    int damage = (unsigned int)(this->_hp) < amount ? this->_hp : amount;
    this->_hp -= damage;
    std::cout << "ClapTrap " << this->_name << " takes "
              << damage << " amount(s) of damage. "
              << "Now with " << this->_hp << " health" << std::endl;
    return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->check_ep(amount))
    {
        this->_hp += amount;
        std::cout << "ClapTrap " << this->_name << " gets repaired for " << amount << ". "
                  << "Now with " << this->_hp << " health" << std::endl;
        this->reduce_ep(amount);
    }
    return;
}