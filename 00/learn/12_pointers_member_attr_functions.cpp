#include <iostream>

using namespace std;

class Sample
{
public:
    int foo;

    Sample();
    ~Sample();

    void bar(void) const;
};

// initialise foo to 0
Sample::Sample(void) : foo(0)
{
    return;
}

Sample::~Sample(void)
{
    return;
}

void Sample::bar(void) const
{
    cout << "bar function called" << endl;
}

int main(void)
{
    Sample sample;
    Sample *sampleptr = &sample;

    cout << sample.foo << endl;

    // declaring ptr to attribute;
    int Sample::*p = NULL;
    p = &Sample::foo;

    // assigning using p with .
    sample.*p = 42;
    // changes foo value
    cout << sample.foo << endl;
    // assigning using p with ->
    sampleptr->*p = 21;
    cout << sample.foo << endl;

    // declaring ptr to function
    void (Sample::*f)(void) const;
    f = &Sample::bar;

    // calling using .
    (sample.*f)();
    // callring using ->
    (sampleptr->*f)();
}