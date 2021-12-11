/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:16:48 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 17:34:43 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
    FragTrap bot("Fraggy");
    bot.attack("slime");
    bot.takeDamage(5);
    bot.beRepaired(10);
    bot.takeDamage(20);
    bot.beRepaired(1);
    bot.attack("goomba");
    bot.highFivesGuys();
    bot.attack("goomba");
    return (0);
}
