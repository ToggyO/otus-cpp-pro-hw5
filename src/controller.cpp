#include "circle.h"
#include "controller.h"
#include "point.h"

Controller::Controller(const std::shared_ptr<IDocument> &doc)
    : m_document_ptr{doc}
{}

void Controller::add_point(size_t x, size_t y)
{
    m_document_ptr->add_shape(std::make_unique<Point>(x, y));
}

void Controller::add_circle(const Point &point, size_t radius)
{
    m_document_ptr->add_shape(
        std::make_unique<Circle>(
            Circle(std::make_unique<Point>(Point(point)),
            std::forward<size_t>(radius))));
}
