#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : x(Fixed(0)), y(Fixed(0))
{
    return;
}

Point::Point(Point const &n) : x(n.getX()), y(n.getY())
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

Point &Point::operator=(Point const &rhs)
{
    *this = rhs;
    return (*this);
}

Fixed Point::getX(void) const
{
    return (this->x);
}

Fixed Point::getY(void) const
{
    return (this->y);
}
