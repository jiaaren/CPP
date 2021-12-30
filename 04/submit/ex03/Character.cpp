/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:45:54 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 15:17:01 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

int const Character::_maxMateria = 4;

Character::Character(void) : _name("(nil)"), _held(0)
{
    std::cout << "Character initiated withh empty name" << std::endl;
    _initialiseSlots();
    return;
}

Character::Character(std::string const &name) : _name(name), _held(0)
{
    std::cout << _name << " is alive!" << std::endl;
    _initialiseSlots();
    return;
}

Character::Character(Character const &c) : _name(c.getName()), _held(0)
{
    std::cout << _name << " is alive!" << std::endl;
    _initialiseSlots();
    *this = c;
    return;
}

Character::Character(ICharacter const &c) : _name(c.getName()), _held(0)
{
    std::cout << _name << " is alive!" << std::endl;
    _initialiseSlots();
    // uses ICharacter overloaded assignment operator
    Character::operator=(c);
    return;
}

Character &Character::operator=(Character const &rhs)
{
    _clearMateria();
    for (int i = 0; i < _maxMateria; i++)
        if (rhs.getSlot(i))
            _slots[i] = rhs.getSlot(i)->clone();
    _name = rhs.getName();
    _held = rhs.getHeld();
    return (*this);
}

ICharacter &Character::operator=(ICharacter const &rhs)
{
    // uses Character overloaded assignment operator
    *this = *(Character *)&rhs;
    return (*this);
}

Character::~Character(void)
{
    std::cout << _name << " perishes..." << std::endl;
    _clearMateria();
    return;
}

void Character::_initialiseSlots(void)
{
    for (int i = 0; i < _maxMateria; i++)
        _slots[i] = NULL;
    return;
}

void Character::_clearMateria(void)
{
    for (int i = 0; i < _maxMateria; i++)
    {
        if ((_slots[i]))
            delete (_slots[i]);
        _slots[i] = NULL;
    }
    _held = 0;
    return;
}

std::string const &Character::getName(void) const
{
    return (_name);
}

void Character::equip(AMateria *m)
{
    if (_held >= 4)
        std::cout << "Inventory full!" << std::endl;
    else
    {
        _slots[_held] = m;
        (_held)++;
        std::cout << m->getType() << " materia equipped" << std::endl;
    }
    return;
}

void Character::_sortMateria(void)
{
    for (int i = 0; i < _maxMateria; i++)
    {
        if (_slots[i] != NULL)
            continue;
        for (int j = i + 1; j < _maxMateria; j++)
        {
            if (_slots[j] == NULL)
                continue;
            _slots[i] = _slots[j];
            _slots[j] = NULL;
            // need break to avoid replacing empty more than once
            break;
        }
    }
    return;
}

bool Character::_hasMateria(int idx)
{
    if (idx < 0 || idx >= 4 || !_slots[idx])
    {
        std::cout << "Materia not found" << std::endl;
        return (false);
    }
    return (true);
}

void Character::unequip(int idx)
{
    if (!(_hasMateria(idx)))
        return;
    std::cout << "Unequiped " << _slots[idx]->getType() << " materia!" << std::endl;
    _slots[idx] = NULL;
    _sortMateria();
    _held--;
}

void Character::use(int idx, ICharacter &target)
{
    if (!(_hasMateria(idx)))
        return;
    _slots[idx]->use(target);
    return;
}

AMateria *Character::getSlot(int idx) const
{
    return (_slots[idx]);
}

int Character::getHeld(void) const
{
    return (_held);
}
