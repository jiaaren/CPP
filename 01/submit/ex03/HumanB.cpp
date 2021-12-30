/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:48:14 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 22:35:57 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    return;
}

HumanB::~HumanB(void)
{
    return;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    return;
}

void HumanB::attack(void) const
{
    std::cout << this->_name << " attacks with his "
              << this->_weapon->getType() << std::endl;
    return;
}
