#include <stdio.h>

int max_int(int a, int b) { return (a >= b ? a : b); }
float max_float(float a, float b) { return (a >= b ? a : b); }
char max_char(char a, char b) { return (a >= b ? a : b); }

int foo(int x)
{
    printf("Long computing time\n");
    return x;
}

// make sure to enclose in
#define max(x, y) ((x) >= (y) ? (x) : (y))

int main(void)
{
    int a = 42;
    int b = 0;
    printf("Max int (funct) is %i\n", max_int(a, b));
    printf("Max int (macro) is %i\n", max(a, b));
    float c = 42.42;
    float d = 142.42;
    printf("Max float (funct) is %f\n", max_float(c, d));
    printf("Max float (macro) is %f\n", max(c, d));
    int e = 'a';
    int f = 'z';
    printf("Max char (funct) is %c\n", max_char(e, f));
    printf("Max char (macro) is %c\n", max(e, f));

    // `foo` will only be called twice
    printf("Max with func input (funct) is %i\n", max_int(foo(a), foo(b)));
    // `foo` will be called 3 times
    printf("Max with func input (macro) is %i\n", max(foo(a), foo(b)));

    return (0);
}
