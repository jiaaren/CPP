/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:42:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/27 10:58:43 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
    return;
}

Weapon::~Weapon(void)
{
    return;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

std::string *Weapon::getType(void)
{
    return (&this->type);
}