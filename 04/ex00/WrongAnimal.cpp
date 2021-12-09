/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:12:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 18:33:42 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("none")
{
    std::cout << "WrongAnimal constructed\n";
    return;
}

WrongAnimal::WrongAnimal(WrongAnimal const &a) : _type(a.getType())
{
    std::cout << "WrongAnimal constructed\n";
    return;
}

WrongAnimal::WrongAnimal(std::string const type) : _type(type)
{
    std::cout << "WrongAnimal constructed\n";
    return;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructed\n";
    return;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

void WrongAnimal::setType(std::string const type)
{
    this->_type = type;
    return;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "beep boop" << std::endl;
    return;
}
