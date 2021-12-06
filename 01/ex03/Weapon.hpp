/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:42:05 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 22:30:12 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
    std::string _type;

public:
    Weapon(std::string type);
    ~Weapon(void);
    std::string getType(void) const;
    void setType(std::string const type);
};

#endif
