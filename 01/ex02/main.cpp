/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:29:47 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/29 00:25:23 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // https://coderedirect.com/questions/535704/address-of-each-character-of-stdstring
    // https://www.quora.com/How-do-references-work-in-C++
    // tried doing &str -> but this actually just refers to the addess of the string class
    // don't be confused about looking at the address of a class
    std::cout << "Memory of string (str)       " << (void *)&(str[0]) << std::endl;
    std::cout << "Memory of string (stringPTR) " << (void *)&(*stringPTR)[0] << std::endl;
    std::cout << "Memory of string (stringREF) " << (void *)&(stringREF[0]) << std::endl;

    // to remove during submission
    // void *addr = &(stringREF[0]);
    // std::cout << ((char *)addr)[0] << std::endl;
    return (0);
}