/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:12:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 15:23:20 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal(std::string const type) : _type(type)
{
    std::cout << "Animal constructed\n";
    return;
}

AAnimal::~AAnimal(void)
{
    std::cout << "Animal destructed\n";
    return;
}

AAnimal &AAnimal::operator=(AAnimal &rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (this->_type);
}

void AAnimal::setType(std::string const type)
{
    this->_type = type;
    return;
}
