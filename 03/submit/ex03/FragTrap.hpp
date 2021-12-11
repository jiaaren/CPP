/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:41:39 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 23:37:38 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

// changed to public
class FragTrap : virtual public ClapTrap
{
protected:
    int const _trapMaxHp;
    int const _trapMaxEp;
    int const _trapMaxAtk;

public:
    FragTrap(std::string const name);
    FragTrap(FragTrap const &ft);
    ~FragTrap(void);
    FragTrap &operator=(FragTrap const &rhs);
    void attack(std::string const &target);
    void highFivesGuys(void);
};

#endif
