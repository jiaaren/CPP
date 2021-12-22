#include "Base.hpp"

int main(void)
{
    Base *b1 = generate();
    identify(b1);
    identify(*b1);

    delete b1;
    return (0);
}
