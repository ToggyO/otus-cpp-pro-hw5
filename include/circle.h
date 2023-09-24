#pragma once

#include <cstddef>
#include <memory>

#include "IShape.h"
#include "point.h"

/**
 * @brief Represents a circle shape.
*/
class Circle : public IShape
{
public:
    /**
     * @brief Creates new instance of `Circle`.
     * 
     * @param std::unique_ptr<Point> unique pointer to cicle center.
     * 
     * @param size_t cirle radius.
     * 
     * @param Color shape color.
     */
    Circle(std::unique_ptr<Point>, size_t, Color = Color::Default);

    Circle(const Circle &) = delete;
    Circle(Circle &&) = default;

    Circle& operator=(const Circle &) = delete;
    Circle& operator=(Circle &&) = default;

    /**
     * @copydoc IShape::draw()
     * Draws the circle.
     */
    void draw() override;

private:
    std::unique_ptr<Point> m_center;
    size_t m_radius;
};