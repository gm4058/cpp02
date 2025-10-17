#include "Point.hpp"

static Fixed cross(Point const &a, Point const &b, Point const &c)
{
    Fixed x1 = b.getX() - a.getX();
    Fixed y1 = b.getY() - a.getY();
    Fixed x2 = c.getX() - a.getX();
    Fixed y2 = c.getY() - a.getY();
    return (x1 * y2 - y1 * x2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    Fixed cross1 = cross(a, b, point);
    Fixed cross2 = cross(b, c, point);
    Fixed cross3 = cross(c, a, point);

    bool has_neg = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
    bool has_pos = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);

    return !(has_neg && has_pos);
}


// ((has_neg && !has_pos) || (has_pos && !has_neg))
// -> !((has_neg && has_pos) || (!has_neg && !has_pos))
// -> !(has_neg && has_pos) && !(!has_neg && !has_pos)
// -> !(has_neg && has_pos) && (has_neg || has_pos)
// -> !(has_neg && has_pos)