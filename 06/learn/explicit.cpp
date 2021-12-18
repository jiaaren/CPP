#include <iostream>

class myImplicit
{
public:
    int i;
    /*implicit*/
    myImplicit(int i) : i(i) {}
};

class myExplicit
{
public:
    int i;
    /*implicit*/
    explicit myExplicit(int i) : i(i) {}
};

void printImplicit(myImplicit x)
{
    std::cout << "printImplicit function is called !\n";
}

void printExplicit(myExplicit x)
{
    std::cout << "printExplicit function is called !\n";
}

int main(void)
{
    printImplicit(2);

    // this will have an error, will need to first explicitly construct it
    // printExplicit(2);

    myExplicit a(4);
    printExplicit(a);
}