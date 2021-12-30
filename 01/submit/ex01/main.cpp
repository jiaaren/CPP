/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:54:04 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/07 15:34:26 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    int num_zomb;

    num_zomb = 5;
    Zombie *horde = zombieHorde(num_zomb, "James");
    for (int i = 0; i < num_zomb; i++)
        horde[i].announce();
    for (int i = 0; i < num_zomb; i++)
        std::cout << (void *)&(horde[i]) << std::endl;
    delete[] horde;
    return (0);
}
