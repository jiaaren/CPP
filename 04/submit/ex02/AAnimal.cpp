/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:12:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 01:32:24 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("none")
{
    std::cout << "AAnimal constructed\n";
    return;
}

AAnimal::AAnimal(AAnimal const &a) : _type(a.getType())
{
    std::cout << "AAnimal constructed\n";
    return;
}

AAnimal::AAnimal(std::string const type) : _type(type)
{
    std::cout << "AAnimal constructed\n";
    return;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal destructed\n";
    return;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
    setType(rhs.getType());
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (_type);
}

void AAnimal::setType(std::string const type)
{
    _type = type;
    return;
}

void AAnimal::makeSound(void) const
{
    std::cout << "beep boop" << std::endl;
    return;
}

void AAnimal::beDeep(void) const
{
    std::cout << "???" << std::endl;
    return;
}
