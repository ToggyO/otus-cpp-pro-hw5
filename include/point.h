#pragma once

#include <cstddef>

#include "color.h"
#include "IShape.h"

/**
 * @brief Represents a simple point shape.
*/
class Point : public IShape
{
public:
    /**
     * @brief Creates new instance of `Point`.
     * 
     * @param size_t x coordinate.
     * 
     * @param size_t y coordinate.
     * 
     * @param Color shape color.
     */
    Point(size_t, size_t, Color = Color::Default);

    /**
     * @copydoc IShape::draw()
     * 
     * Draws the point.
     */
    void draw() override;

private:
    size_t m_x;
    size_t m_y;
};
