/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:45:54 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 23:57:45 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

int const Character::_maxMateria = 4;

void Character::_initialiseSlots(void)
{
    for (int i = 0; i < _maxMateria; i++)
        (this->_slots)[i] = NULL;
    return;
}

void Character::_clearMateria(void)
{
    for (int i = 0; i < _maxMateria; i++)
    {
        if ((this->_slots)[i])
            delete (this->_slots)[i];
        (this->_slots)[i] = NULL;
    }
    this->_held = 0;
    return;
}

Character::Character(std::string const &name) : _name(name), _held(0)
{
    std::cout << this->_name << " is alive!" << std::endl;
    this->_initialiseSlots();
    return;
}

Character::Character(ICharacter const &c) : _name(c.getName()), _held(0)
{
    // upcasting
    Character &x = (Character &)c;
    std::cout << this->_name << " is cloned!" << std::endl;
    this->_initialiseSlots();
    for (int i = 0; i < _maxMateria; i++)
        if (x.getSlot(i))
            (this->_slots)[i] = x.getSlot(i)->clone();
    return;
}

ICharacter &Character::operator=(ICharacter const &rhs)
{
    // upcasting
    Character &x = (Character &)rhs;
    std::cout << this->_name << " copied " << x.getName() << std::endl;
    this->_clearMateria();
    for (int i = 0; i < _maxMateria; i++)
        if (x.getSlot(i))
            (this->_slots)[i] = x.getSlot(i)->clone();
    this->_name = x.getName();
    this->_held = x.getHeld();
    return (*this);
}

Character::~Character(void)
{
    this->_clearMateria();
    std::cout << this->_name << " perishes..." << std::endl;
    return;
}

std::string const &Character::getName(void) const
{
    return (this->_name);
}

void Character::equip(AMateria *m)
{
    if (this->_held >= 4)
        std::cout << "Inventory full!" << std::endl;
    else
    {
        (this->_slots)[this->_held] = m;
        (this->_held)++;
    }
    return;
}

void Character::_sortMateria(void)
{
    for (int i = 0; i < _maxMateria && (this->_slots)[i] == NULL; i++)
    {
        for (int j = i + 1; j < _maxMateria && (this->_slots)[j]; j++)
        {
            (this->_slots)[i] = (this->_slots)[j];
            (this->_slots)[j] = NULL;
        }
    }
    return;
}

bool Character::_hasMateria(int idx)
{
    if (idx < 0 || idx >= 4 || !(this->_slots)[idx])
    {
        std::cout << "Materia not found" << std::endl;
        return (false);
    }
    return (true);
}

void Character::unequip(int idx)
{
    if (!(this->_hasMateria(idx)))
        return;
    (this->_slots)[idx] = NULL;
    std::cout << "Unequiped materia!" << std::endl;
    this->_sortMateria();
    (this->_held)--;
}

void Character::use(int idx, ICharacter &target)
{
    if (!(this->_hasMateria(idx)))
        return;
    (this->_slots)[idx]->use(target);
    return;
}

AMateria *Character::getSlot(int idx) const
{
    return ((this->_slots)[idx]);
}

int Character::getHeld(void) const
{
    return (this->_held);
}
