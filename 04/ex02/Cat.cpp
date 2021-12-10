/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:25:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 16:56:50 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : AAnimal("Cat"), _brain(new Brain)
{
    std::cout << "Cat constructed\n";
    return;
}

Cat::~Cat(void)
{
    delete _brain;
    std::cout << "Cat destructed\n";
    return;
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
        std::cout << _brain->getIdea() << std::endl;
    return;
}
