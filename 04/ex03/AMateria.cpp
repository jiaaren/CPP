/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:06:48 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 23:39:57 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

// no constructor or destructor yet

AMateria::AMateria(std::string const &type) : _type(type)
{
    return;
}

AMateria::~AMateria(void)
{
    return;
}

std::string const &AMateria::getType(void) const
{
    return (this->_type);
}

// why need this, also silenced Werror flags
void AMateria::use(ICharacter &target)
{
    return;
}
