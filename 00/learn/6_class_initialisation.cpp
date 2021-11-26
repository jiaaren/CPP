#include <iostream>

class Sample1
{

public:
    char a1;
    int a2;
    float a3;

    // 1.
    Sample1(char b1, int b2, float b3);
    ~Sample1(void);
};

// 2. dont do this

// Sample1::Sample1(char b1, int b2, float b3)
// {
//     std::cout << "Constructor called" << std::endl;

//     this->a1 = b1;
//     this->a2 = a2;
//     this->a3 = a3;

//     std::cout << "a1: " << this->a1 << "a2: " << this->a2 << "a3: " << this->a3 << std::endl;

//     return;
// }

// 3. do this
Sample1::Sample1(char b1, int b2, float b3) : a1(b1), a2(b2), a3(b3)
{
    std::cout << "Constructor called" << std::endl;

    std::cout << "a1: " << this->a1 << "a2: " << this->a2 << "a3: " << this->a3 << std::endl;

    return;
}

// destructor
Sample1::~Sample1(void)
{
}

// 4. declare like this
int main(void)
{
    Sample1 instance('c', 42, 6.7799);
    Sample1 instance2('b', 100, 1.2345);

    return (0);
}