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
	// int rep_len = std::strlen(argv[2]);
	// int torep_len = std::strlen(argv[3]);
	// int pos = 0;

	while (!ifs.eof())
	{
		std::getline(ifs, contents);
		std::cout << contents << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}