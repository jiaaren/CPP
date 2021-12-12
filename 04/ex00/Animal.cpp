/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:12:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/12 10:06:03 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal(void) : _type("none")
{
    std::cout << "Animal constructed\n";
    return;
}

Animal::Animal(Animal const &a) : _type(a.getType())
{
    std::cout << "Animal constructed\n";
    return;
}

Animal::Animal(std::string const type) : _type(type)
{
    std::cout << "Animal constructed\n";
    return;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructed\n";
    return;
}

Animal &Animal::operator=(Animal const &rhs)
{
    setType(rhs.getType());
    return (*this);
}

std::string Animal::getType(void) const
{
    return (_type);
}

void Animal::setType(std::string const type)
{
    _type = type;
    return;
}

void Animal::makeSound(void) const
{
    std::cout << "beep boop" << std::endl;
    return;
}
