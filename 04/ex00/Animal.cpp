/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:12:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 18:22:19 by jkhong           ###   ########.fr       */
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

Animal::~Animal(void)
{
    std::cout << "Animal destructed\n";
    return;
}

Animal &Animal::operator=(Animal &rhs)
{
    this->setType(rhs.getType());
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

void Animal::setType(std::string const type)
{
    this->_type = type;
    return;
}