/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:39:13 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/30 20:39:13 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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