/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:48:07 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 22:34:18 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
    Weapon &_weapon;
    std::string _name;

public:
    HumanA(std::string const name, Weapon &weapon);
    ~HumanA(void);
    void attack(void) const;
};

#endif
