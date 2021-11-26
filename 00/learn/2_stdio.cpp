// https://www.cplusplus.com/reference/iostream/

#include <iostream>

int main(void)
{
    char buff[512];

    // (i) outputting hello world, (ii) adding new line
    std::cout << "Hello world!" << std::endl;

    std::cout << "Input a word:";
    // (iii) User to enter word
    std::cin >> buff;
    std::cout << "[" << buff << "]" << std::endl;

    return (0);
}