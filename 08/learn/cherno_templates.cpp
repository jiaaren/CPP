#include <iostream>

// combining typanem and data type
template <typename T, int N>
class Array
{
private:
    T arr[N];

public:
    int getSize() { return N; }
};

int main(void)
{
    Array<int, 5> x;
    std::cout << x.getSize() << "\n";
}