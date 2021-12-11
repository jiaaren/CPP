/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:41:39 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 23:26:41 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
protected:
    int const _trapMaxHp;
    int const _trapMaxEp;
    int const _trapMaxAtk;

public:
    ScavTrap(std::string const name);
    ScavTrap(ScavTrap const &st);
    ~ScavTrap(void);
    ScavTrap &operator=(ScavTrap const &rhs);
    void attack(std::string const &target);
    void guardGate(void);
};

#endif
