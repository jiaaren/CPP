/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:25:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 00:44:44 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain)
{
    std::cout << "Dog constructed\n";
    return;
}

Dog::Dog(Dog const &d) : Animal("Dog"), _brain(new Brain)
{
    std::cout << "Dog constructed\n";
    *this = d;
    return;
}

Dog::~Dog(void)
{
    // have this instead of _brain->~Brain();
    delete _brain;
    std::cout << "Dog destructed\n";
    return;
}

Dog &Dog::operator=(Dog const &rhs)
{
    Animal::operator=(rhs);
    if (_brain)
        *_brain = *(rhs.getBrain());
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "woof woof" << std::endl;
    return;
}

void Dog::beDeep(void) const
{
    if (!_brain)
        std::cout << "uhhhhh woof?" << std::endl;
    else
        std::cout << _brain->getRandIdea() << std::endl;
    return;
}

Brain *Dog::getBrain(void) const
{
    return (_brain);
}
