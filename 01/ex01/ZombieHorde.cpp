/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:53:52 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/07 15:34:22 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include "Zombie.hpp"

Zombie *zombieHorde(unsigned int N, std::string name)
{
    std::stringstream ss;
    std::string tmp;

    if (!N)
        return (NULL);
    // constructed using default empty constructor
    // https://www.cs.fsu.edu/~myers/cop3330/notes/dma.html
    Zombie *horde = new Zombie[N];
    for (unsigned int i = 0; i < N; i++)
    {
        ss << (i + 1);
        ss >> tmp;
        // clearing string stream -> needed this or else kept printing one only
        ss.clear();
        horde[i].setName(name + "-" + tmp);
    }
    return (horde);
}
