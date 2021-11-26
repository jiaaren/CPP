#include <stdbool.h>
#include <iostream>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

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

	while (true)
	{
		std::cout << "Enter Command: ";
		std::getline(std::cin, input);
		if (input.compare("EXIT") == 0)
			return (0);
		else if (input.compare("ADD") == 0)
			phonebook.update_phonebook();
		else if (input.compare("SEARCH") == 0)
		{
			phonebook.display_contact_summaries();
			while (phonebook.num_updated != 0)
			{
				std::cout << "Enter index: ";
				if (read_integer(&index))
					if (phonebook.display_contact_full(index))
						break;
			}
		}
	}
	return (0);
}