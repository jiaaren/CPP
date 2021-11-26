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
    (this->contacts)[index].fast_update();
    this->num_updated += 1;
}

void PhoneBook::display_contact_summaries(void)
{
    int to_cycle;

    to_cycle = this->num_updated <= 8 ? this->num_updated : 8;
    std::cout << "index     |first name|last name |nickname  " << std::endl;
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
    (this->contacts)[index - 1].display_contact();
    return (true);
}