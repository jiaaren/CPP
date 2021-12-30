/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:01:18 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/12 12:48:45 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Brain.hpp"

std::string Brain::_quotes[NUM_IDEAS];

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

Brain &Brain::operator=(Brain const &rhs)
{
    for (int i = 0; i < NUM_IDEAS; i++)
        _ideas[i] = rhs._ideas[i];
    return (*this);
}

std::string Brain::getRandIdea(void) const
{
    return ((this->_ideas)[rand() % NUM_IDEAS]);
}

std::string Brain::getIndexIdea(unsigned int i) const
{
    if (i >= NUM_IDEAS)
    {
        std::cout << "Index has to be between 0 and 100" << std::endl;
        return ("");
    }
    else
        return (_ideas[i]);
}

void Brain::fillBrain(void)
{
    int r = rand() % NUM_IDEAS;

    for (int i = 0; i < NUM_IDEAS; i++)
        (this->_ideas)[(r + i) % NUM_IDEAS] = Brain::_quotes[i];
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
