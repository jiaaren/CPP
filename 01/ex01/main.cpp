/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:54:04 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/27 02:03:15 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int num_zomb;

    num_zomb = 5;
    Zombie *horde = zombieHorde(num_zomb, "James");
    for (int i = 0; i < num_zomb; i++)
        horde[i].announce();
    // freeing -> delete[], not delete horde[]
    // noticed that destructor is called twice.. because i've initialised the zombie twice previously
    delete[] horde;
    return (0);
}