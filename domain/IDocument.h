#pragma once

#include <string_view>

#include "IEditableDocument.h"
#include "IObservable.h"

/**
 * @brief Represents editor document model interface.
 */
class IDocument : public IEditableDocument, public IObservable
{
public:
    /**
     * @brief Opens a document from a file at the specified file path.
     * 
     * @param Path to file
     */
    virtual void open(const std::string_view) = 0;

    /**
     * @brief Saves the document model state.
     */
    virtual void save() = 0;

    /**
     * @brief Clears the document model state.
     */
    virtual void clear() = 0;
};