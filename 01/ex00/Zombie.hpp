/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:53:37 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/27 01:53:37 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);

private:
    std::string name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif