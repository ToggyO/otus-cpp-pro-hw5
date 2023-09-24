#include "point.h"

Point::Point(size_t x, size_t y, Color color)
    : IShape(color),
    m_x{x},
    m_y{y}
{}

void Point::draw()
{
    // TODO: implement me
}