#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
public:
	Contact contacts[8];
	int num_updated;

	PhoneBook(void);
	~PhoneBook(void);
	void update_phonebook(void);
	void display_contact_summaries(void);
	bool display_contact_full(int index);
};

#endif