#include <iostream>

int main(void)
{
    // Lesson 1
    int a = 42;   
    double b = a;               // Implicit conversion cast
    double c = (double)a;       // Explicit conversion cast

    double d = a;               // Implicit promotion -> ok
    int e = d;                  // Implicit demotion -> hazardous
    int f = (int)d;             // Explicit demotion -> ok
    return(0);
}