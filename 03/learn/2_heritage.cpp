#include <string>

class Quadruped
{
private:
    std::string name; // only accessible from quadraped object

protected:
    Leg legs[4]; // accessible from quadraped or derived object

public:
    void run(); // accessible from wherever
};

class Dog : public Quadruped // can access run() and legs
{
};