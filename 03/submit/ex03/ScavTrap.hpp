/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:41:39 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 01:11:39 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>
#include "ClapTrap.hpp"

// included virtual for ex03
class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap(std::string const name);
    ~ScavTrap();

    void attack(std::string const &target);
    void guardGate(void);
};

#endif