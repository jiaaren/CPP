#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
public:
    // Class attributes
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

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