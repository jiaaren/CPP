/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:53:37 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 21:57:38 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
public:
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    void announce(void) const;
    std::string getName(void) const;
    void setName(std::string const name);

private:
    std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
