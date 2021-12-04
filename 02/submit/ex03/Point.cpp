#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : x(Fixed(0)), y(Fixed(0))
{
    return;
}

Point::Point(Point const &n) : x(n.x), y(n.y)
{
    return;
}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y))
{
    return;
}

Point::~Point(void)
{
    return;
}

// x and y are const, so need to return new value instead of returning *this
Point   Point::operator=(Point const &rhs)
{
    return (Point(rhs));
}
