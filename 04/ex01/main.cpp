/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:10:33 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 16:54:49 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
    int tot = 100;
    Animal **animals = new Animal *[100];
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
