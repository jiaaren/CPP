/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:29:47 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/27 10:29:48 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string stringREF = *stringPTR;

	// https://coderedirect.com/questions/535704/address-of-each-character-of-stdstring
	// tried doing &str -> but this actually just refers to the addess of the string class
	// don't be confused about looking at the address of a class
	std::cout << "Memory of string (str)       " << (void *)&(str[0]) << std::endl;
	std::cout << "Memory of string (stringPTR) " << (void *)&(*stringPTR)[0] << std::endl;
	std::cout << "Memory of string (stringREF) " << (void *)&(stringREF[0]) << std::endl;
	return (0);
}