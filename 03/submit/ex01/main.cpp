/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:16:48 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 00:40:27 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    ScavTrap bot("Scappy");
    bot.attack("slime");
    bot.takeDamage(5);
    bot.beRepaired(10);
    bot.takeDamage(20);
    bot.beRepaired(1);
    bot.attack("goomba");
    bot.guardGate();
    bot.attack("goomba");
    return (0);
}