/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:56:12 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/11 11:56:13 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap bot("Clappy");
    bot.attack("bucket");
    bot.takeDamage(5);
    bot.beRepaired(5);
    bot.takeDamage(20);
    bot.beRepaired(5);
    return (1);
}