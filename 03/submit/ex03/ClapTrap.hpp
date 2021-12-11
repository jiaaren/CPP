/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 01:17:47 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 23:39:54 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
    // changed to protected
protected:
    std::string _name;
    std::string _clapName;
    int _maxHp;
    int _maxEp;
    int _maxAtk;
    int _hp;
    int _ep;
    int _atk;

public:
    ClapTrap(std::string const name);
    ~ClapTrap(void);
    ClapTrap(ClapTrap const &ct);
    ClapTrap &operator=(ClapTrap const &rhs);
    bool check_ep(unsigned int const amount) const;
    void reduce_ep(unsigned int const amount);
    void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    // getters
    std::string getName(void) const;
    std::string getClapName(void) const;
    // added virtual for ex03, dont't think this is necessary
    // to make sure to read DiamondTrap getFullName
    virtual std::string getFullName(void) const;
    int getHp(void) const;
    int getEp(void) const;
    int getAtk(void) const;
    int getMaxHp(void) const;
    int getMaxEp(void) const;
};

#endif
