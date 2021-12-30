/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:39:13 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/30 18:32:38 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void update_phonebook(void);
    void display_contact_summaries(void);
    bool display_contact_full(int index);
    int num_updated;
};

#endif
