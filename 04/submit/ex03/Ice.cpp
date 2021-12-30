/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:14:04 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 23:30:41 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice")
{
    return;
}

AMateria *Ice::clone(void) const
{
    return (new Ice);
}

void Ice::use(ICharacter &target)
{
    std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\""
              << std::endl;
    return;
}
