/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:42:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 22:30:23 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    return;
}

Weapon::~Weapon(void)
{
    return;
}

void Weapon::setType(std::string const type)
{
    this->_type = type;
    return;
}

std::string Weapon::getType(void) const
{
    return (this->_type);
}
