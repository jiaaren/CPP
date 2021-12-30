/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:43:46 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 23:10:20 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

/*
    // https://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
    // increment by length of replacement just to avoid from reiterating throught the whole string again using .find

    // read all character (including whitespace)
    https://stackoverflow.com/questions/116951/using-fstream-to-read-every-character-including-spaces-and-newline
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
    std::stringstream ss;
    ss << ifs.rdbuf();

    std::string contents(ss.str());

    int rep_len = std::strlen(argv[2]);
    size_t pos = 0;
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
    ifs.close();
    ofs.close();
    return (0);
}
