/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 01:17:47 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 17:33:54 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
private:
    std::string _name;
    std::string _clapName;
    int _hp;
    int _ep;
    int _atk;

public:
    ClapTrap(std::string const name);
    ~ClapTrap(void);
    std::string getFullName(void) const;
    bool check_ep(unsigned int const amount) const;
    void reduce_ep(unsigned int const amount);
    void attack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
