/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:48:14 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/28 14:25:36 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

// fix sequence, weapon then name... need to match HumanA.hpp
HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name)
{
    return;
}

HumanA::~HumanA(void)
{
    return;
}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with his " << this->weapon.type << std::endl;
}