#include <iostream>

class Sample
{

public:
    int publicFoo;
    Sample(void);
    ~Sample(void);

    void publicBar(void) const;
    int get_privateFoo(void) const;

private:
    int _privateFoo;
    void _privateBar(void) const;
};

Sample::Sample(void)
{
    this->publicFoo = 0;
    this->_privateFoo = 0;
}

Sample::~Sample(void)
{
    return;
}

void Sample::publicBar(void) const
{
    std::cout << "public bar function called" << std::endl;
}

int Sample::get_privateFoo(void) const
{
    return (this->_privateFoo);
}

void Sample::_privateBar(void) const
{
    std::cout << "private bar function called" << std::endl;
}

int main(void)
{
    Sample sample;

    sample.publicFoo = 42;
    std::cout << sample.publicFoo << std::endl;
    sample.publicBar();

    std::cout << sample.get_privateFoo() << std::endl;
    // comment for error
    // sample._privateFoo = 100;
    // sample._privateBar();
}