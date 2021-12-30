/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:29:47 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 22:25:11 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// https://coderedirect.com/questions/535704/address-of-each-character-of-stdstring
// https://www.quora.com/How-do-references-work-in-C++
// to not confused between pointer of data and pointer of string class
int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory of string (str)       " << (void *)(str.data()) << std::endl;
    std::cout << "Memory of string (str)       " << (void *)&(str[0]) << std::endl;
    std::cout << "Memory of string (stringPTR) " << (void *)&(*stringPTR)[0] << std::endl;
    std::cout << "Memory of string (stringREF) " << (void *)&(stringREF[0]) << std::endl;
    return (0);
}
