/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:25:53 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/09 18:34:56 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat constructed\n";
    return;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructed\n";
    return;
}

void Cat::makeSound(void) const
{
    std::cout << "meow meow" << std::endl;
    return;
}