#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <sstream>
#include <string>

/*
    First step: to convert into type at highest hierarchy, i.e. double
    Other consdierations:
    - To also consider input of printable characters, which are only represntable by char
    - To consider min and max values
*/

double give_double(std::string input)
{
    std::stringstream ss;
    double tmp;

    if (input == "inf" || input == "+inf")
        return (+std::numeric_limits<float>::infinity());
    else if (input == "-inf")
        return (-std::numeric_limits<float>::infinity());
    else if (input == "nan")
        return (std::numeric_limits<float>::quiet_NaN());
    // remove f from end of string
    if (input[input.length() - 1] == 'f')
        input[input.length() - 1] = '\0';
    ss << input;
    ss >> tmp;
    return (tmp);
}

// checks if double is nan or inf
bool check_possible(double d)
{
    if (std::isnan(d) || std::isinf(d))
        return (false);
    return (true);
}

// to check if double is more than max int/min int, does not process char to int conversions
std::string give_int(double d)
{
    int tmp;
    std::stringstream ss;
    std::string str;

    if (!check_possible(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        return ("impossible");
    tmp = static_cast<int>(d);
    ss << tmp;
    ss >> str;
    return (str);
}

// -128 to 127 -> 256 max for a char
// displayable -> 32 ' ' to 126 ~
std::string give_char(double d, std::string input)
{
    std::string tmp;

    // check for char input, does not process for non printable and digits
    if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
        tmp = input[0];
    else
    {
        if (!check_possible(d) || d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
            return ("impossible");
        else if (!std::isprint(d))
            return ("Non displayable");
        tmp = static_cast<char>(d);
    }
    return ("'" + tmp + "'");
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "./convert [str_rep of value]\n";
        return (1);
    }
    double d = give_double(argv[1]);
    float f = static_cast<float>(d);

    std::cout << "char: " << give_char(d, argv[1]) << "\n";
    std::cout << "int: " << give_int(d) << "\n";
    // print minimum precision if integer value inputted
    if (static_cast<int>(d) == d)
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
        return (0);
    }
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << "\n";
    return (0);
}
