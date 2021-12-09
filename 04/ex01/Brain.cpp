/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:01:18 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 02:06:40 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain constructed\n";
    return;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructed\n";
    return;
}
