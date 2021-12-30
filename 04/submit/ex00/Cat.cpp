/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:25:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/12 12:08:06 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat constructed\n";
    return;
}

Cat::Cat(Cat const &c) : Animal("Cat")
{
    std::cout << "Cat constructed\n";
    *this = c;
    return;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructed\n";
    return;
}

Cat &Cat::operator=(Cat const &rhs)
{
    (void)rhs;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "meow meow" << std::endl;
    return;
}
