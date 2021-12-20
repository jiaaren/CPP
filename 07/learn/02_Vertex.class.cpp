#include <iostream>
#include <iomanip>

// can rename file as .tpp but vscode doesn't propertly detect it

// default type as float
template <typename T = float>
class Vertex
{
public:
    // don't i need to declare Vertex<T>?
    Vertex(T const &x, T const &y, T const &z) : _x(x), _y(y), _z(z){};
    ~Vertex(void){};

private:
    T const _x;
    T const _y;
    T const _z;
    // including default constructor as private
    // forces user to use parametized constructor above
    Vertex(void);
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Vertex<T> const &v);

int main(void)
{
    Vertex<int> v1(1, 2, 3);
    // uses default type as float
    // c++ uses implicit conversion to convert int inputted to float
    Vertex<> v2(1, 2, 3);
}
