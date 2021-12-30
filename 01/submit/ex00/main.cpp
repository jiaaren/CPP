/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:53:44 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 21:58:53 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *heap_zombo = newZombie("Heap Zombo");
    randomChump("Stack zombo");
    heap_zombo->announce();
    delete heap_zombo;
    return (0);
}
