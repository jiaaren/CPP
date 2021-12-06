/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:28:25 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 11:37:58 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <iostream>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "colors.hpp"

bool read_integer(int *num)
{
    std::stringstream ss;
    std::string input;
    int i;

    std::getline(std::cin, input);
    ss.str(input);
    if (!(ss >> i))
        return (false);
    *num = i;
    return (true);
}

int main(void)
{
    PhoneBook phonebook;
    std::string input;
    int index;

    while (!std::cin.eof())
    {
        std::cout << BOLD(FBLU("Enter Command : "));
        std::getline(std::cin, input);
        if (input.compare("EXIT") == 0)
            return (0);
        else if (input.compare("ADD") == 0)
            phonebook.update_phonebook();
        else if (input.compare("SEARCH") == 0)
        {
            phonebook.display_contact_summaries();
            while (!std::cin.eof() && phonebook.num_updated != 0)
            {
                std::cout << BOLD(FBLU("Enter index   : "));
                if (read_integer(&index))
                    if (phonebook.display_contact_full(index))
                        break;
                std::cerr << FRED("Invalid, please enter appropriate index") << std::endl;
            }
        }
        else
            std::cerr << FRED("Invalid Command, please enter either ADD, SEARCH or EXIT")
                      << std::endl;
    }
    std::cout << std::endl;
    return (0);
}
