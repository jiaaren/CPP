/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:14:14 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 23:30:49 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
    return;
}

AMateria *Cure::clone(void) const
{
    return (new Cure);
}

void Cure::use(ICharacter &target)
{
    std::cout << "Cure: \"* heals " << target.getName() << "'s wounds *\""
              << std::endl;
    return;
}
