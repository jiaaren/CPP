#include <iostream>

class Sample
{
public:
    Sample();
    ~Sample();

    // get number of instances
    static int getNbInst(void);

private:
    static int _nbInst;
};

Sample::Sample()
{
    _nbInst++;
}

Sample::~Sample()
{
    _nbInst--;
}

// accssing variable using Sample::_nbInst;
int Sample::getNbInst(void)
{
    return Sample::_nbInst;
}

// static variable declaration
// even for private variables
int Sample::_nbInst = 0;

void check_instance()
{
    std::cout << "Instances: " << Sample::getNbInst() << std::endl;
}

int main(void)
{
    check_instance();
    Sample sample1;
    check_instance();
    Sample sample2;
    Sample sample3;
    check_instance();
    // call destructor
    sample1.~Sample();
    check_instance();
}