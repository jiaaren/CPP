#include <iostream>
#include <stdexcept>

class Parent
{
public:
    virtual ~Parent(void){};
};
class Child1 : public Parent
{
};
class Child2 : public Parent
{
};

class Unrelated
{
};

class Foo
{
private:
    float _v;

public:
    Foo(float const f) : _v(f){};

    float getV(void) const { return _v; }
    // creates instances of implicit casts
    operator float() { return _v; }
    operator int() { return static_cast<int>(_v); }
};

int main(void)
{
    {
        // Casting for classes, basically same rules apply
        Child1 a;

        Parent *b = &a;           // Implicit reinterpretation cast
        Parent *c = (Parent *)&a; // Explicit reinterpretation cast

        Parent *d = &a; // Implicit upcast -> ok

        // Child1 *e = d;           // Implicit demotion -> bad

        // No compilation issues, but may have run time issues...
        // since cannot differentiate between Child1 and Child2 during compilation...
        // d is essentially from Child1
        Child2 *f = (Child2 *)d; // Explicit demotion -> ok
    }

    {
        // Static cast -> simple types
        int a = 42;

        double b = a; // Implicit promotion - ok
        int c = b;    // Implicit demotion - bad
        int d = static_cast<int>(b);
    }
    {
        // Static cast -> classes
        Child1 a;
        Parent *b = &a;
        // this still compiles eventhough 'a' is created using Child1 instead of Child2
        Child2 *c = static_cast<Child2 *>(b);

        // will not compile with this
        // will not work with try/catch because this will be a compilation error
        try
        {
            // Unrelated *d = static_cast<Unrelated *>(b);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        // Dynamic cast
        Child1 a;
        Parent *b = &a; // Implicit upcast -> ok
        Child1 *c = dynamic_cast<Child1 *>(b);

        // failed dynamic casting using pointers since initial type (Child1 is differnet from Child2)
        Child2 *d = dynamic_cast<Child2 *>(b);
        if (!d)
            std::cout << "Dynamic cast failed\n";
        // failed dynamic casting using references since initial type (Child1 is differnet from Child2)
        try
        {
            Child2 &e = dynamic_cast<Child2 &>(*b);
        }
        catch (std::bad_cast &bc)
        {
            std::cout << "Dynamic cast failed " << bc.what() << "\n";
        }
    }
    {
        // Reinterpret cast
        float a = 120.012f;

        void *b = &a; // ok
        int *c = reinterpret_cast<int *>(&a);
        int &d = reinterpret_cast<int &>(a);
    }
    {
        // Const cast
        int a = 42;

        int const *b = &a;                          // implicit type qualifier cast
        int const *c = const_cast<int const *>(&a); // explicit type qualifier cast

        int const *d = &a; // implicit promotion - ok
        // int *e = d;      // implicit demotion - bad
        int *f = const_cast<int *>(d); // explicit demotion - ok
    }
    {
        // cast operators
        Foo a(42.042f);
        // implicit cast from Foo to float
        float b = a;
        // here there is an implicit cast from Foo to int
        int c = a;

        std::cout << a.getV() << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
    return (0);
}
