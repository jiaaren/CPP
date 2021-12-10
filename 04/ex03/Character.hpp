/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:38:22 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 23:57:47 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    // ok to set private? instead of protected?
private:
    std::string _name;
    int _held;
    AMateria *_slots[4];
    static int const _maxMateria;
    void _initialiseSlots(void);
    void _sortMateria(void);
    bool _hasMateria(int idx);
    void _clearMateria(void);

public:
    Character(std::string const &name);
    // ok for this to be character, think need to be or else cannot access materia
    Character(ICharacter const &c);
    virtual ~Character(void);
    virtual std::string const &getName(void) const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);
    AMateria *getSlot(int idx) const;
    int getHeld(void) const;
    ICharacter &operator=(ICharacter const &rhs);
};

#endif
