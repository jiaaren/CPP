/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 01:17:47 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 00:34:12 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
    // updated to protected
protected:
    std::string _name;
    // hitpoints
    int _hp;
    // energy points
    int _ep;
    // attack
    int _atk;

public:
    ClapTrap(std::string const name);
    ~ClapTrap(void);
    bool check_ep(unsigned int const amount) const;
    void reduce_ep(unsigned int const amount);
    void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif