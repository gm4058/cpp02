#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    ~Point();
};

#endif

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}
Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}
Point::Point(const Point& other) : x(other.x), y(other.y) {}
Point::~Point() {}

