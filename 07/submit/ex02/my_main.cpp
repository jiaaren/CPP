#include <iostream>
#include "Array.hpp"

void print(std::string str)
{
    std::cout << str << "\n";
}

template <typename T>
void print_val(Array<T> a)
{
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
}

int main(void)
{
    print("<---- Construction with no parameter, creates empty array ---->");
    Array<int> empty;
    std::cout << "Length of empty array: " << empty.size() << "\n";
    print("\n** Attempting to access empty array: (exception thrown) ");
    try
    {
        empty[0];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    print("<---- Construction of array initilaised by default ---->");
    print("** Int array of length 10");
    Array<int> int_arr(10);
    print_val<int>(int_arr);
    print("\n** Float array of length 10");
    Array<float> float_arr(10);
    print_val<float>(float_arr);
    print("\n** Bool array of length 10");
    Array<bool> bool_arr(10);
    print_val<bool>(bool_arr);

    print("\n<---- [] operator to update values ---->");
    print("Updated int_arr[0] to 100");
    print("Updated int_arr[5] to 250");
    print("Updated int_arr[9] to -50");
    int_arr[0] = 100;
    int_arr[5] = 250;
    int_arr[9] = -50;
    print_val<int>(int_arr);

    print("\n<---- Assignment operator ---->");
    print("** Created new array and assigned with previous array, and then Modified previous array");
    Array<int> tmp_int_arr(10);
    tmp_int_arr = int_arr;
    // modified previous array
    int_arr[3] = 42;
    print(">>>> Original array");
    print_val<int>(int_arr);
    print(">>>> New array");
    print_val<int>(tmp_int_arr);
    print("\n** Assignment of array of different size (initialised new array of size 3)");
    print("Before: ");
    Array<int> size_three(3);
    print_val<int>(size_three);
    size_three = int_arr;
    print("After: ");
    print_val<int>(size_three);
    print("\n** Assignment of array of zero size");
    print("Before: ");
    print_val<int>(size_three);
    size_three = empty;
    print("After: ");
    print_val<int>(size_three);
    std::cout << "Length of empty array: " << size_three.size() << "\n";
    print("** Attempting to access empty array: (exception thrown) ");
    try
    {
        size_three[0];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    print("\n<---- Copy constructor ---->");
    Array<int> copy_int_arr(int_arr);
    print_val<int>(copy_int_arr);
    print("\n<---- Modifying copy (no changes to original) ---->");
    copy_int_arr[8] = 1234567890;
    print(">>>> Original array");
    print_val<int>(int_arr);
    print(">>>> Copied array");
    print_val<int>(copy_int_arr);

    print("\n<---- Test bounds of [] operator ---->");
    print("** Out of bounds ( > size )  - index 10");
    try
    {
        int_arr[10];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    print("\n** Out of bounds ( < size )  - index -1");
    try
    {
        int_arr[-1];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    print("\n<---- Returning size of array ---->");
    print("** Test with size 0");
    Array<bool> b(0);
    std::cout << "Bool array has size " << b.size() << "\n";
    print("** Test with size 5");
    Array<char> c(5);
    std::cout << "Char array has size " << c.size() << "\n";
    print("** Test with size 100");
    Array<float> f(100);
    std::cout << "Float array has size " << f.size() << "\n";

    return (0);
}
