#include <iostream>

using namespace std;

class Sample
{
public:
    // why const in middle?
    const int pi;
    int num;

    Sample(const int n);
    ~Sample();

    void print(void) const;
};

Sample::Sample(int const n) : pi(n)
{
    return;
}

Sample::~Sample(void)
{
    return;
}

void Sample::print(void) const
{
    cout << "this->pi is " << this->pi << endl;
    // uncommenting this would result in read only error
    // this->pi = 42;
}

int main(void)
{
    Sample sample(3.14);
    sample.print();
}
