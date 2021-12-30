/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:25:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/12 12:08:35 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog constructed\n";
    return;
}

Dog::Dog(Dog const &c) : Animal("Dog")
{
    std::cout << "Dog constructed\n";
    *this = c;
    return;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructed\n";
    return;
}

Dog &Dog::operator=(Dog const &rhs)
{
    (void)rhs;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "woof woof" << std::endl;
    return;
}
