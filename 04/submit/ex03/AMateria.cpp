/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:06:48 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 02:26:26 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(void) : _type("(nil)")
{
    std::cout << "Materia type yet to be initialised" << std::endl;
    return;
}

AMateria::AMateria(AMateria const &m) : _type(m.getType())
{
    std::cout << "Materia " << _type << " created" << std::endl;
    return;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "Materia " << _type << " created" << std::endl;
    return;
}

AMateria::~AMateria(void)
{
    std::cout << "Materia " << _type << " destructed" << std::endl;
    return;
}

AMateria &AMateria::operator=(AMateria const &rhs)
{
    _type = rhs.getType();
    return (*this);
}

std::string const &AMateria::getType(void) const
{
    return (_type);
}

// why need this, also silenced Werror flags
void AMateria::use(ICharacter &target)
{
    (void)target;
    return;
}
