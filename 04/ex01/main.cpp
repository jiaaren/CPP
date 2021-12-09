/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:10:33 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 02:22:24 by jkhong           ###   ########.fr       */
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
    Animal *animals[tot];
    Animal *a;
    // initialisation
    for (int i = 0; i < tot; i++)
    {
        std::cout << "<------" << i << "------>" << std::endl;
        if (i % 2 == 0)
            a = new Cat();
        else
            a = new Dog();
        animals[i] = a;
    }
    for (int i = 0; i < tot; i++)
    {
        std::cout << "<------" << i << "------>" << std::endl;
        delete animals[i];
    }
    return (0);
}
