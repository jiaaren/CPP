/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:38:58 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 11:37:36 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

// Constructor
Contact::Contact(void)
{
    return;
}

// Destructor
Contact::~Contact(void)
{
    return;
}

void Contact::update_contact(void)
{
    // https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
    std::cout << "First name    : ";
    std::getline(std::cin, this->first_name);
    std::cout << "Last name     : ";
    std::getline(std::cin, this->last_name);
    std::cout << "Nickname      : ";
    std::getline(std::cin, this->nickname);
    std::cout << "Phone number  : ";
    std::getline(std::cin, this->phone_number);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, this->darkest_secret);
}

void Contact::fast_update(void)
{
    std::string dummy;
    std::cout << "Enter dummy data: ";
    std::getline(std::cin, dummy);
    this->first_name = dummy;
    this->last_name = dummy;
    this->nickname = dummy;
    this->phone_number = dummy;
    this->darkest_secret = dummy;
}

void Contact::convert_att(std::string str)
{
    if (str.length() > 10)
    {
        str.resize(9);
        str = str + ".";
    }
    // https://www.cplusplus.com/reference/iomanip/setw/
    std::cout << std::setw(10) << str;
}

// Member function
void Contact::display_summary(int index)
{
    std::stringstream ss;
    std::string int_str;

    ss << index;
    ss >> int_str;
    this->convert_att(int_str);
    std::cout << "|";
    this->convert_att(this->first_name);
    std::cout << "|";
    this->convert_att(this->last_name);
    std::cout << "|";
    this->convert_att(this->nickname);
    std::cout << std::endl;
}

void Contact::display_contact(void)
{
    std::cout << std::setw(16) << "First Name: ";
    std::cout << this->first_name << std::endl;
    std::cout << std::setw(16) << "Last Name: ";
    std::cout << this->last_name << std::endl;
    std::cout << std::setw(16) << "Nickname: ";
    std::cout << this->nickname << std::endl;
    std::cout << std::setw(16) << "Phone number: ";
    std::cout << this->phone_number << std::endl;
    std::cout << std::setw(16) << "Darkest Secret: ";
    std::cout << this->darkest_secret << std::endl;
}
