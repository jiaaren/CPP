/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:15:36 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 14:29:13 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_source[4];
    int _nSource;
    static int const _maxMateria;
    void _initialiseMateria(void);

public:
    MateriaSource(void);
    MateriaSource(MateriaSource const &ms);
    virtual ~MateriaSource(void);
    MateriaSource &operator=(MateriaSource const &rhs);
    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(std::string const &type);
    void showMateria(void) const;
    // getter
    AMateria *getMateria(int const idx) const;
    int getNSource(void) const;
};

#endif
