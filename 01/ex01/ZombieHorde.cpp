/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:53:52 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/27 02:17:41 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    std::stringstream ss;
    std::string tmp;

    if (!N)
        return (NULL);
    // works now because of dummy constructor
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        ss << (i + 1);
        ss >> tmp;
        // clearing string stream -> needed this or else kept printing one only
        ss.clear();
        // removing this or else would have double destructor
        // horde[i] = Zombie(name + " " + tmp);
        horde[i].update_name(name + " " + tmp);
    }
    return (horde);
}