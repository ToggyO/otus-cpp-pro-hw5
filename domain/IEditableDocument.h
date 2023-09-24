#pragma once

#include <list>
#include <memory>

#include "IShape.h"

/**
 * @brief Represents editor document model interface with possibility to manage drawable objects.
 */
class IEditableDocument
{
public:
    /**
     * @brief Adds a new shape to the document model.
     * 
     * @param unique pointer to `IShape` object.
     */
    virtual void add_shape(std::unique_ptr<IShape>) = 0;

    /**
     * @brief Removes a new shape to the document model.
     * 
     * @param unique pointer to `IShape` object.
     */
    virtual void remove_shape(std::unique_ptr<IShape>) = 0;

    /**
     * @brief Returns an iterator to first position of container, that contains shapes.
     */
    virtual std::list<std::unique_ptr<IShape>>::const_iterator cbegin() const = 0;

    /**
     * @brief Returns an iterator to last position of container, that contains shapes.
     */
    virtual std::list<std::unique_ptr<IShape>>::const_iterator cend() const = 0;

};