/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:28:28 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 11:38:06 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
    this->num_updated = 0;
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

void PhoneBook::update_phonebook(void)
{
    int index;

    index = this->num_updated % 8;
    (this->contacts)[index].update_contact();
    this->num_updated += 1;
}

void PhoneBook::display_contact_summaries(void)
{
    int to_cycle;

    to_cycle = this->num_updated <= 8 ? this->num_updated : 8;
    std::cout << "╭―――――――――――――――――――――――――――――――――――――――――╮" << std::endl
              << "│        crappy phonebook summary         │" << std::endl
              << "╰―――――――――――――――――――――――――――――――――――――――――╯" << std::endl
              << "index     |first name|last name |nickname  " << std::endl;
    for (int i = 0; i < to_cycle; i++)
        (this->contacts)[i].display_summary(i + 1);
}

bool PhoneBook::display_contact_full(int index)
{
    if (this->num_updated < 8)
        if (index > this->num_updated)
            return (false);
    if (index < 1 || index > 8)
        return (false);
    std::cout << "╭―――――――――――――――――――――――――――――――――――――――――╮" << std::endl
              << "│             contact details             │" << std::endl
              << "╰―――――――――――――――――――――――――――――――――――――――――╯" << std::endl;
    (this->contacts)[index - 1].display_contact();
    std::cout << std::endl;
    return (true);
}
