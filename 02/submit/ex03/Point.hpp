#include "Fixed.hpp"

class Point
{
public:
    Point(void);
    Point(Point const &p);
    Point(const float x, const float y);
    ~Point(void);

    Point operator=(Point const &rhs);

private:
    Fixed const x;
    Fixed const y;
};
