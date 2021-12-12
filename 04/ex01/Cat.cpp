/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:25:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/12 12:27:41 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain)
{
    std::cout << "Cat constructed\n";
    return;
}

Cat::Cat(Cat const &c) : Animal("Cat"), _brain(new Brain)
{
    std::cout << "Cat constructed\n";
    *this = c;
    return;
}

Cat::~Cat(void)
{
    delete _brain;
    std::cout << "Cat destructed\n";
    return;
}

Cat &Cat::operator=(Cat const &rhs)
{
    Animal::operator=(rhs);
    if (_brain)
        *_brain = *(rhs.getBrain());
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "meow meow" << std::endl;
    return;
}

void Cat::beDeep(void) const
{
    if (!_brain)
        std::cout << "uhhhhh meow?" << std::endl;
    else
        std::cout << _brain->getRandIdea() << std::endl;
    return;
}

Brain *Cat::getBrain(void) const
{
    return (_brain);
}
