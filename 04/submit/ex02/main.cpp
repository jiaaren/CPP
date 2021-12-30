/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:10:33 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 01:34:59 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
    int tot = 100;
    AAnimal **animals = new AAnimal *[100];
    // initialise brain
    Brain::fillQuotes();
    // initialisation
    for (int i = 0; i < tot; i++)
    {
        std::cout << "<------" << i << "------>" << std::endl;
        if (i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
        animals[i]->makeSound();
        animals[i]->beDeep();
    }
    for (int i = 0; i < tot; i++)
    {
        std::cout << "<------" << i << "------>" << std::endl;
        delete animals[i];
    }
    delete[] animals;
    return (0);
}
