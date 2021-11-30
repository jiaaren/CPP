/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:43:46 by jkhong            #+#    #+#             */
/*   Updated: 2021/11/28 20:44:36 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "./replace FILENAME str1 str2" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	// access using string.data()
	std::ifstream ifs(filename.data());
	std::ofstream ofs((filename + (std::string) ".replace").data());
	std::string contents;
	int rep_len = std::strlen(argv[2]);
	size_t pos = 0;

	while (!ifs.eof())
	{
		std::getline(ifs, contents);

		while (true)
		{
			pos = contents.find(argv[2], pos);
			// npos represents -1
			if (pos == std::string::npos)
				break;
			contents.erase(pos, rep_len);
			contents.insert(pos, argv[3]);
			// https://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
			// increment by length of replacement just to avoid from reiterating throught the whole string again using .find
			pos += rep_len;
		}
		ofs << contents << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}