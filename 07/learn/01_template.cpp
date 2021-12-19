#include <iostream>

// not template
int max(int x, int y)
{
    return (x >= y ? x : y);
}

/*
    1. replace int with T
    - T would be a global type
    - however won't compile since T is not a C++ type

    2. Add template keyword -> tell compiler that we're writing a template
    - <typename T> to declare global template type

    3. Good practice to have function take in reference instead of copy (and also return value)
    - because our template not only takes in int/floats but classes as well.
    - save alot of memory because address only passed in, not a new copy

    4. Good function to have const for input and return value
    - especially if we're not modifying the inputted data
*/
template <typename T>
T const &max_t(T const &x, T const &y)
{
    return (x >= y ? x : y);
}

int foo(int x)
{
    printf("Long computing time\n");
    return x;
}

/*
    Syntax of calling templates
    - using <>
    - Can call using implicit or explicit (with <> ) instantiation
    - most of times implicit instantiation will not be good idea

*/
int main(void)
{
    int a = 42;
    int b = 0;
    printf("Max int (macro) is %i\n", max_t(a, b)); // Implicit instantiation
    float c = 42.42;
    float d = 142.42;
    printf("Max float (macro) is %f\n", max_t<float>(c, d)); // Explicit instantiation
    int e = 'a';
    int f = 'z';
    printf("Max char (macro) is %c\n", max_t<char>(e, f)); // Explicit instantiation

    // no problems with functions
    // this works similarly as normal functions
    printf("Max with func input (macro) is %i\n", max(foo(a), foo(b)));

    return (0);
}
