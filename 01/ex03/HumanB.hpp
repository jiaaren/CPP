/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:48:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 22:37:48 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
    Weapon *_weapon;
    std::string _name;

public:
    HumanB(std::string name);
    ~HumanB(void);
    void setWeapon(Weapon &weapon);
    void attack(void) const;
};

#endif