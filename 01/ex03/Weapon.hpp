/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:42:05 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/27 11:21:42 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
public:
    // Member attr
    std::string type;
    // Member func
    std::string *getType(void);
    void setType(std::string type);
    // Constructor destructor
    Weapon(std::string type);
    ~Weapon();
};

#endif