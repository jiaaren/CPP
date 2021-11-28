/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:48:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/28 14:43:26 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB
{
public:
    // Member attr
    Weapon *weapon;
    std::string name;
    // Member func
    void setWeapon(Weapon &weapon);
    void attack(void);
    // Constructor & destuctor
    HumanB(std::string name);
    ~HumanB();
};

#endif