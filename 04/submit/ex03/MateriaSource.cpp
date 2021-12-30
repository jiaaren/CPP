/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:55:38 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 14:36:16 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

int const MateriaSource::_maxMateria = 4;

void MateriaSource::_initialiseMateria(void)
{
    for (int i = 0; i < _maxMateria; i++)
        _source[i] = NULL;
    return;
}

MateriaSource::MateriaSource(void) : _nSource(0)
{
    std::cout << "Materia source initiated" << std::endl;
    _initialiseMateria();
    return;
}

MateriaSource::MateriaSource(MateriaSource const &ms) : _nSource(0)
{
    std::cout << "Materia source initiated" << std::endl;
    _initialiseMateria();
    *this = ms;
    return;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "Materia source destructed" << std::endl;
    for (int i = 0; i < _maxMateria; i++)
        if (_source[i])
            delete _source[i];
    return;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
    for (int i = 0; i < _nSource; i++)
        if (_source[i])
            delete _source[i];
    for (int i = 0; i < _maxMateria; i++)
        if (rhs.getMateria(i))
            _source[i] = rhs.getMateria(i)->clone();
    _nSource = rhs.getNSource();
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (m == NULL)
        std::cout << "Invalid materia inputted" << std::endl;
    else if (_nSource >= 4)
        std::cout << "Max materia already learned by source " << std::endl;
    else
    {
        _source[_nSource] = m;
        _nSource++;
        std::cout << "Source learned materia " << m->getType() << std::endl;
    }
    return;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < _nSource; i++)
    {
        if ((_source[i])->getType() != type)
            continue;
        std::cout << "Source created materia " << (_source[i])->getType() << std::endl;
        return (_source[i]->clone());
    }
    std::cout << "Materia " << type << " not found in source, please try another materia type" << std::endl;
    return (NULL);
}

void MateriaSource::showMateria(void) const
{
    for (int i = 0; i < _nSource; i++)
        std::cout << "Index " << i << " stores " << _source[i]->getType() << std::endl;
    return;
}

AMateria *MateriaSource::getMateria(int const idx) const
{
    if (idx < 0 || idx >= 4)
        return (NULL);
    return (_source[idx]);
}

int MateriaSource::getNSource(void) const
{
    return (_nSource);
}
