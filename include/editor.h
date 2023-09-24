#pragma once

#include <list>
#include <memory>

#include "IDocument.h"
#include "IObserver.h"
#include "point.h"

/**
 * @brief Represents editor view state.
 */
class Editor : public std::enable_shared_from_this<Editor>, public IObserver
{
public:
    Editor(const Editor &) = delete;
    Editor(Editor &&) = default;

    Editor& operator=(const Editor &) = delete;
    Editor& operator=(Editor &&) = default;

    /**
     * @brief Creates new instance of `Editor`.
     *
     * @param std::shared_ptr<IDocument> shared pointer to document model.
     */
    explicit Editor(const std::shared_ptr<IDocument> &);

    /**
     * @copydoc IObserver::update
     * 
     * Callback action.
     */
    void update(); 

    /**
     * @brief Draw new objects. Change editor's view state.
     */
    void draw();

private:
    std::shared_ptr<IDocument> m_model;
};
