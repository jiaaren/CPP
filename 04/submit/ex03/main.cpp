/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:05:59 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 15:15:49 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void print(std::string str)
{
    std::cout << str << std::endl;
    return;
}

int main(void)
{
    print("<---- Creating MateriaSource and learn 2 Materia instances ---->");
    IMateriaSource *src = new MateriaSource;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    print("\n<---- Creating new character and equipping Materia ---->");
    ICharacter *me = new Character("me");

    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    print("");
    tmp = src->createMateria("cure");
    me->equip(tmp);

    print("\n<---- Creating new character bob and attack/heal bob ---->");
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    print("\n<---- Testing orthodox canonical functions ---->");
    print("** Copy constructor based on 'me' - accepts ICharacter arg (stored in variable bill)");
    ICharacter *bill = new Character(*me);
    print("** Killing off original 'me'");
    delete me;
    print("** Having 'bill' use materia on bob");
    bill->use(0, *bob);
    bill->use(1, *bob);
    bill->use(2, *bob);

    print("\n** Copy constructor based on 'bill' - accepts Character arg (stored in variable ken)");
    Character *ken = new Character(*(Character *)bill);
    print("** Killing off original 'bill'");
    delete bill;
    print("** Having 'ken' use materia on bob");
    ken->use(0, *bob);
    ken->use(1, *bob);
    ken->use(3, *bob);

    print("\n** Testing assignment operator");
    print("** Character pointer");
    Character *c = new Character("c");
    *c = *ken;
    print("** Having 'c' use materia on bob");
    c->use(0, *bob);
    c->use(1, *bob);
    c->use(4, *bob);
    delete c;

    print("\n** ICharacter pointer");
    ICharacter *ic = new Character("ic");
    *ic = *ken;
    print("** Having 'ic' use materia on bob");
    ic->use(0, *bob);
    ic->use(1, *bob);
    ic->use(2, *bob);
    delete ic;
    delete ken;

    print("\n<---- Testing equipment ---->");
    ICharacter *test = new Character("test");
    print("** Accessing materias that do not exist (use)");
    test->use(0, *bob);
    test->use(1, *bob);
    test->use(2, *bob);
    test->use(-1, *bob);
    test->use(10, *bob);

    print("\n** Accessing materias that do not exist (unequip)");
    test->unequip(0);
    test->unequip(1);
    test->unequip(2);
    test->unequip(-1);
    test->unequip(10);

    print("\n** Accessing some materias that exist");
    AMateria *tmp1 = src->createMateria("ice");
    test->equip(tmp1);
    AMateria *tmp2 = src->createMateria("cure");
    print("");
    test->equip(tmp2);
    test->use(0, *bob);
    test->use(1, *bob);
    test->use(2, *bob);
    test->use(3, *bob);
    test->use(-1, *bob);

    print("\n** Equipping max materia and using materia");
    test->equip(tmp1);
    test->equip(tmp2);
    test->equip(tmp1);
    test->use(2, *bob);
    test->use(3, *bob);

    print("\n** Unequipping materia and accessing them subsequently");
    test->unequip(3);
    test->use(3, *bob);
    test->unequip(0);
    test->use(2, *bob);

    print("\n** Using remaining materia");
    print("\n** Expect order to change");
    test->use(0, *bob);
    test->use(1, *bob);
    test->use(2, *bob);
    test->use(3, *bob);

    delete test;
    delete bob;

    print("\n<---- Testing Materia Source functions ---->");
    print("\n** Max materia");
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    AMateria *max = new Ice();
    src->learnMateria(max);
    delete max;

    print("\n** Create materia");
    AMateria *tmp_m;
    tmp_m = src->createMateria("fire");
    tmp_m = src->createMateria("cure");
    delete tmp_m;

    print("\n** Empty source");
    MateriaSource ms;
    ms.showMateria();
    ms.createMateria("ice");

    print("\n<---- Testing Materia Source orthodox ---->");
    print("\n** Copy constructor");
    IMateriaSource *src2 = new MateriaSource(*(MateriaSource *)src);
    ((MateriaSource *)src2)->showMateria();

    print("\n** Assignment constructor");
    IMateriaSource *src3 = new MateriaSource();
    *(MateriaSource *)src3 = *(MateriaSource *)src;
    ((MateriaSource *)src3)->showMateria();

    print("\n<---- END ---->");
    delete src3;
    delete src2;
    delete src;
    return (0);
}
