/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:48:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/28 14:28:15 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include "Weapon.hpp"

class HumanA
{
public:
    // Member attr
    Weapon &weapon;
    std::string name;
    // Member func
    void attack(void);
    // Constructor & destuctor
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
};

#endif