/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:43:46 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 22:55:50 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

/*
    // https://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
    // increment by length of replacement just to avoid from reiterating throught the whole string again using .find
*/
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
    if (!ifs)
    {
        std::cout << "file read failed" << std::endl;
        return (2);
    }
    std::ofstream ofs((filename + (std::string) ".replace").data());
    std::string contents;
    int rep_len = std::strlen(argv[2]);
    size_t pos;

    while (!ifs.eof())
    {
        std::getline(ifs, contents);
        pos = 0;
        while (true)
        {
            pos = contents.find(argv[2], pos);
            // npos represents -1 (18446744073709551615, 2^64)
            if (pos == std::string::npos)
                break;
            contents.erase(pos, rep_len);
            contents.insert(pos, argv[3]);
            pos += rep_len;
        }
        ofs << contents << std::endl;
        contents.clear();
    }
    ifs.close();
    ofs.close();
    return (0);
}
