#include <iostream>

using namespace std;

class Sample
{
public:
    Sample();
    // ~Sample();

    // naming convention
    int getFoo(void) const; // getter may only read-only, const good practice
    void setFoo(int i);

    // compare lesson
    int compare(Sample *other) const;

private:
    int _foo;
};

Sample::Sample(void)
{
    this->_foo = 0;
}

int Sample::getFoo(void) const
{
    return (this->_foo);
}

/*
    Improvement
    - return type to boolean -> to inform user if successful set/update operation
    - print or log error message
*/
void Sample::setFoo(int i)
{
    if (i >= 0)
        this->_foo = i;
    return;
}

int Sample::compare(Sample *other) const
{
    return (other->getFoo() - this->_foo);
}

int main(void)
{
    Sample sample;
    cout << sample.getFoo() << std::endl;

    sample.setFoo(42);
    cout << sample.getFoo() << std::endl;

    // not changed because -42 is less than 0
    sample.setFoo(-42);
    cout << sample.getFoo() << std::endl;

    Sample sample2;
    sample2.setFoo(42);
    // 0 equals match
    cout << sample.compare(&sample2) << std::endl;
}