#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{
    return;
}

Point::Point(Point const &n) : _x(n.getX()), _y(n.getY())
{
    return;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
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
    return (this->_x);
}

Fixed Point::getY(void) const
{
    return (this->_y);
}
