/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_deepcopy.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:12:39 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 14:57:59 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void print(std::string str)
{
    std::cout << str << std::endl;
}

int main(void)
{
    // Initialise Brain
    Brain::fillQuotes();
    print("<--- Test Dog --->");
    Animal *d1 = new Dog();
    d1->makeSound();
    d1->beDeep();

    Animal *d2 = new Dog();
    d2->makeSound();
    d2->beDeep();

    print("\n<--- Test Upcast to Dog (expect different output) --->");
    // upcast to derived class
    Dog *dd1 = (Dog *)d1;
    Dog *dd2 = (Dog *)d2;
    print(dd1->getBrain()->getIndexIdea(0));
    print(dd2->getBrain()->getIndexIdea(0));

    print("\n<--- Test Assignment (expect same output) --->");
    *dd2 = *dd1;
    print(dd1->getBrain()->getIndexIdea(0));
    print(dd2->getBrain()->getIndexIdea(0));

    print("\n<--- Test Copy Constructor (expect same output as above) --->");
    Dog dd3 = *dd1;
    print(dd3.getType());
    dd3.makeSound();
    print(dd3.getBrain()->getIndexIdea(0));

    delete d1;
    delete d2;
    // no need to explicitly call destructor, however needed to make sure that
    // Dog.cpp deletes dynamically allocated brain
    // dd3.~Dog();
    print("\n<-- End Test Dog -->\n");

    print("<--- Test Cat --->");
    Animal *c1 = new Cat();
    c1->makeSound();
    c1->beDeep();

    Animal *c2 = new Cat();
    c2->makeSound();
    c2->beDeep();

    print("\n<--- Test Upcast to Cat (expect different output) --->");
    // upcast to derived class
    Cat *cc1 = (Cat *)c1;
    Cat *cc2 = (Cat *)c2;
    print(cc1->getBrain()->getIndexIdea(0));
    print(cc2->getBrain()->getIndexIdea(0));

    print("\n<--- Test Assignment (expect same output) --->");
    *cc2 = *cc1;
    print(cc1->getBrain()->getIndexIdea(0));
    print(cc2->getBrain()->getIndexIdea(0));

    print("\n<--- Test Copy Constructor (expect same output as above) --->");
    Cat cc3 = *cc1;
    print(cc3.getType());
    cc3.makeSound();
    print(cc3.getBrain()->getIndexIdea(0));

    delete c1;
    delete c2;
    return (0);
}
