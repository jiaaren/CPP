/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:25:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 15:23:38 by jkhong           ###   ########.fr       */
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

Dog::~Dog(void)
{
    delete _brain;
    std::cout << "Dog destructed\n";
    return;
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
        std::cout << _brain->getIdea() << std::endl;
    return;
}
