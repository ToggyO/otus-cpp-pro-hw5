#pragma once

#include "color.h"

/**
 * @brief Represents editor shape interface.
 */
class IShape
{
public:
    /**
     * @brief Creates new instance of `IShape`.
     */
    IShape() : IShape(Color::Default) {}

    /**
     * @brief Creates new instance of `IShape`.
     * 
     * @param Color shape color.
     */
    IShape(Color color) : m_color(color) {}

    virtual ~IShape() = default;

    /**
     * @brief Draws shape on a view.
     */
    virtual void draw() = 0;

private:
    Color m_color;
};