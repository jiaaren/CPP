/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:16:48 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 23:59:33 by jkhong           ###   ########.fr       */
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

    // DiamondTrap bot2("Poob");
    // bot2.attack("slime");
    // bot2.takeDamage(5);
    // bot2.beRepaired(10);
    // bot2.takeDamage(20);
    // bot2 = bot;
    // bot2.beRepaired(1);
    // bot2.attack("goomba");
    // bot2.guardGate();
    // bot2.highFivesGuys();
    // bot2.attack("goomba");
    // bot2.whoAmI();
    return (0);
}
