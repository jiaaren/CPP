/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:53:59 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/27 01:54:00 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Dummy constructor
Zombie::Zombie(void)
{
    return;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->name << " is now dead!" << std::endl;
    return;
}

void Zombie::announce(void)
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}