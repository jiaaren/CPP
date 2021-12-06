/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:53:10 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 21:47:43 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    // parentheses for declaration of zombie after memory allocation
    Zombie *zombie = new Zombie(name);
    return (zombie);
}
