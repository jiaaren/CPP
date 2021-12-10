/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:01:18 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/10 15:14:20 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Brain.hpp"

std::string Brain::_quotes[100];

Brain::Brain(void)
{
    std::cout << "Brain constructed\n";
    fillBrain();
    return;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructed\n";
    return;
}

std::string Brain::getIdea(void) const
{
    return ((this->_ideas)[rand() % 100]);
}

void Brain::fillBrain(void)
{
    int r = rand() % 100;

    for (int i = 0; i < 100; i++)
        (this->_ideas)[(r + i) % 100] = Brain::_quotes[i];
}

void Brain::fillQuotes(void)
{
    std::ifstream ifs("quotes.txt");
    std::string str;
    int index = 0;

    if (!ifs)
        return;
    while (std::getline(ifs, str))
        Brain::_quotes[index++] = str;
    ifs.close();
}
