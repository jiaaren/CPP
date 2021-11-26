/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:53:44 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/27 01:53:44 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *heap_zombo = newZombie("Heap Zombo");
    heap_zombo->announce();
    randomChump("Stack zombo");
    delete heap_zombo;
    return (0);
}