/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:53:27 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 22:08:12 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) : _name("(nameless)")
{
    return;
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Zombie " << this->_name << " is risen from the dead!" << std::endl;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->_name << " is now (officially) dead!" << std::endl;
    return;
}

void Zombie::announce(void) const
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}

std::string Zombie::getName(void) const
{
    return (this->_name);
}

void Zombie::setName(std::string const name)
{
    this->_name = name;
    return;
}
