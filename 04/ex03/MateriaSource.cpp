/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:55:38 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 23:06:20 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

int const MateriaSource::_maxMateria = 4;

MateriaSource::MateriaSource(void) : _nSource(0)
{
    std::cout << "Materia source initiated" << std::endl;
    for (int i = 0; i < _maxMateria; i++)
        (this->_source)[i] = NULL;
    return;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "Materia source destructed" << std::endl;
    for (int i = 0; i < _maxMateria; i++)
        if ((this->_source)[i])
            delete (this->_source)[i];
    return;
}

void MateriaSource::learnMateria(AMateria *m)
{
    (this->_source)[this->_nSource] = m;
    (this->_nSource)++;
    std::cout << "Source learned materia " << m->getType() << std::endl;
    return;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < this->_nSource; i++)
    {
        if ((this->_source[i])->getType() != type)
            continue;
        std::cout << "Source created materia " << (this->_source[i])->getType() << std::endl;
        return (this->_source[i]->clone());
    }
    return (NULL);
}
