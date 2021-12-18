#include "Base.hpp"

int main(void)
{
    Base base;
    Base *b1 = base.generate();
    base.identify(b1);
    base.identify(*b1);

    delete b1;
    return (0);
}