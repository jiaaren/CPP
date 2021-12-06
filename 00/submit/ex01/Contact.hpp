/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:39:02 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 21:22:23 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
private:
    // Class attributes
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    // Constructor and destructor
    Contact(void);
    ~Contact(void);

    // Member functions
    void convert_att(std::string str);
    void update_contact(void);
    void fast_update(void);
    void display_summary(int index);
    void display_contact(void);
};

#endif
