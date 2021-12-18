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
    - Does static cast handle interpreting Max and min values of ints and floats?

    TODO:
    - check if input is a double/number
    - precision of floats and doubles?
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

// to check if double is more than max int/min int
// no way to check for cast limits?
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
std::string give_char(double d)
{
    char tmp;
    std::stringstream ss;
    std::string str;

    if (!check_possible(d) || d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
        return ("impossible");
    else if (!std::isprint(d))
        return ("Non displayable");
    tmp = static_cast<char>(d);
    ss << tmp;
    ss >> str;
    return (str);
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

    std::cout << "char: " << give_char(d) << "\n";
    std::cout << "int: " << give_int(d) << "\n";
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}