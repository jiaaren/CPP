/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 00:51:49 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 23:49:58 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;

public:
    DiamondTrap(std::string const name);
    DiamondTrap(DiamondTrap const &dt);
    ~DiamondTrap(void);
    DiamondTrap &operator=(DiamondTrap const &rhs);
    void attack(const std::string &target);
    void whoAmI(void) const;
    // replaces ClapTrap's getFullName, need virtual
    virtual std::string getFullName(void) const;
    std::string getName(void) const;
};
