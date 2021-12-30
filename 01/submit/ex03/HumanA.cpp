/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:48:14 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 22:34:19 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name)
{
    return;
}

HumanA::~HumanA(void)
{
    return;
}

void HumanA::attack(void) const
{
    std::cout << this->_name << " attacks with his "
              << this->_weapon.getType() << std::endl;
    return;
}
