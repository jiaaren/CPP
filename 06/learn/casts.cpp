#include <iostream>

int main(void)
{
    // Lesson 1
    {
        int a = 42;
        double b = a;         // Implicit conversion cast
        double c = (double)a; // Explicit conversion cast

        double d = a;   // Implicit promotion -> ok
        int e = d;      // Implicit demotion -> hazardous
        int f = (int)d; // Explicit demotion -> ok
    }
    {
        // Lesson 2 - reinterpretation
        float a = 420.042f;
        void *b = &a;         // Implicit reinterpretation cast
        void *c = (void *)&a; // Explicit reinterpretation cast

        void *d = &a; // Implicit promotion (i.e. specific pointer to generic) = ok
        // int *e = d;          // Implciit demotion (i.e. generic to specific) - bad
        int *f = (int *)d; // Explicit demotion - ok
        // NOTE: reinterpretation doesn't `cast`, floats will not be read properly as an int
        // float: 420.042, int: 1137837408
        std::cout << "float: " << a << ", int: " << *f << "\n";
    }
    {
        // Lesson 3 - type qualifier cast
        int a = 42;

        int const *b = &a;              // implicit type qualifier cast
        int const *c = (int const *)&a; // explicit type qualifier cast

        int const *d = &a; // implicit promotion - ok
        // int *e = d;      // implicit demotion - bad
        int *f = (int *)d; // explicit demotion - ok
    }
}