/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:41:37 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 23:33:07 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const name) : ClapTrap(name),
                                             _trapMaxHp(100), _trapMaxEp(100), _trapMaxAtk(30)
{
    _hp = _maxHp = _trapMaxHp;
    _ep = _maxEp = _trapMaxEp;
    _atk = _trapMaxAtk;
    _clapName = "FragTrap";
    std::cout << "FragTrap " << _name << " initiated" << std::endl;
    return;
}

FragTrap::FragTrap(FragTrap const &st) : ClapTrap(st),
                                         _trapMaxHp(100), _trapMaxEp(20), _trapMaxAtk(20)
{
    *this = st;
    return;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << _name << " destroyed" << std::endl;
    return;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
    ClapTrap::operator=(rhs);
    return (*this);
}

void FragTrap::attack(std::string const &target)
{
    if (check_ep(_atk))
    {
        std::cout << getFullName() << " hugs "
                  << target << " for " << _atk << " damage" << std::endl;
        reduce_ep(_atk);
    }
    return;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << getFullName() << " requests high fives from its comrades"
              << std::endl;
    if (!check_ep(25))
        std::cout << getFullName() << " receives no responses :(" << std::endl;
    else
    {
        std::cout << getFullName() << " feels validated :)" << std::endl;
        reduce_ep(25);
    }
    return;
}
