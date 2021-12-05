/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:16:48 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 01:33:12 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap bot("Boop");
    bot.attack("slime");
    bot.takeDamage(5);
    bot.beRepaired(10);
    bot.takeDamage(20);
    bot.beRepaired(1);
    bot.attack("goomba");
    bot.guardGate();
    bot.highFivesGuys();
    bot.attack("goomba");
    bot.whoAmI();
    return (0);
}