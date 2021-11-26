#include <functional>
#include <iostream>
#include <vector>

int const amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
size_t amounts_size(sizeof(amounts) / sizeof(int));
int what(40);

// Declaring int vector
typedef std::vector<int> int_t;
int_t int_v = {1, 2, 3, 4};

int main(void)
{
    std::cout << amounts_size << std::endl;
    std::cout << what << std::endl;

    int_t::iterator it = int_v.begin();
    for (it; it != int_v.end(); it++)
        std::cout << *it << std::endl;
}