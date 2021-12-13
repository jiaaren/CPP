/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:38:22 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/13 11:29:16 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    int _held;
    AMateria *_slots[4];
    static int const _maxMateria;
    void _initialiseSlots(void);
    void _clearMateria(void);
    void _sortMateria(void);
    bool _hasMateria(int idx);

public:
    // canonical + extra for interface
    Character(void);
    Character(std::string const &name);
    Character(Character const &c);
    Character(ICharacter const &c);
    Character &operator=(Character const &rhs);
    virtual ICharacter &operator=(ICharacter const &rhs);
    ~Character(void);
    // getters
    virtual std::string const &getName(void) const;
    AMateria *getSlot(int idx) const;
    int getHeld(void) const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);
};

#endif
