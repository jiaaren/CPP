/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:53:48 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/27 01:53:49 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
public:
    // dummy constructor
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void);

private:
    std::string name;
};

// ex00
Zombie *newZombie(std::string name);
void randomChump(std::string name);

// ex01
Zombie *zombieHorde(int N, std::string name);

#endif