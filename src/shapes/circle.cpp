#include "circle.h"

Circle::Circle(std::unique_ptr<Point> center, size_t radius, Color color)
    : IShape(color),
    m_center{std::move(center)},
    m_radius{radius}
{}

void Circle::draw()
{
    // TODO: implement me
}