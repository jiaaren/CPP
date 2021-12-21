#include <iostream>
#include <iomanip>

// when must i include the <> beside pair
// generic template
template <typename T, typename U>
class Pair
{
public:
    Pair<T, U>(T const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs)
    {
        std::cout << "Generic template\n";
    }
    ~Pair<T, U>(void) {}
    T const &_lhs;
    U const &_rhs;

private:
    // keep this private
    Pair<T, U>(void);
};

// partial specialized template
template <typename U>
// here now ?
class Pair<int, U>
{
public:
    Pair<int, U>(int const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs)
    {
        std::cout << "Int partial specialization\n";
    }
    ~Pair<int, U>(void) {}
    int const &_lhs;
    U const &_rhs;

private:
    // keept his private
    Pair<int, U>(void);
};

// full specialized template (empty typename)
template <>
// here now ?
class Pair<bool, bool>
{
public:
    Pair<bool, bool>(bool lhs, bool rhs)
    {
        std::cout << "Bool/bool full specialization\n";
        _n = 0;
        // bit shift left, != is OR, cast to int and then bitshirt left
        _n |= static_cast<int>(lhs) << 0; // no need to shift
        _n |= static_cast<int>(rhs) << 1; // shift 1 bit to left
        return;
    }
    ~Pair<bool, bool>(void) {}
    // basically AND operator to check if first bit is true
    bool getlhs(void) const { return (_n & 0x01); }
    // basically AND operator to check if 2nd bit is true
    bool getrhs(void) const { return (_n & 0x02); }
    int _n;

private:
    // keep this private
    Pair<bool, bool>(void);
};

// ostream template no need partial or full, since it will be the same (except for <bool,bool>) for all other pairs
template <typename T, typename U>
std::ostream &operator<<(std::ostream &o, Pair<T, U> &p)
{
    o << "Pair( " << p._lhs << ", " << p._rhs << " )";
    return (o);
}

// ?? no need template here?
std::ostream &operator<<(std::ostream &o, Pair<bool, bool> &p)
{
    o << std::boolalpha << "Pair( " << p.getlhs() << ", " << p.getrhs() << " )";
    return (o);
}

int main(void)
{
    // generic template
    Pair<float, int> a(42.42f, 100);
    std::cout << a << "\n\n";

    // Partial specialization
    Pair<int, char> b(100, 'A');
    std::cout << b << "\n\n";

    // Full specialization
    Pair<bool, bool> c(false, true);
    std::cout << c << "\n\n";

    // Note: This doesn't call full specialization since not both parameters are bool
    Pair<float, bool> d(42.42f, true);
    std::cout << d << "\n\n";
}
