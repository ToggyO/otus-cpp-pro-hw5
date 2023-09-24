#pragma  once

#include <memory>

#include "IDocument.h"

// TODO: copy/move ctors
/**
 * @brief Erditro actions handler.
 */
class Controller
{
public:
    /**
     * @brief Creates new instanse of `Controller`
     *
     * @param std::shared_ptr<IDocument> shared pointer to document model.
     */
    explicit Controller(const std::shared_ptr<IDocument> &);

    Controller(const Controller &) = delete;
    Controller(Controller &&) = default;

    Controller& operator=(const Controller &) = delete;
    Controller& operator=(Controller &&) = default;

    /**
     * @brief Creates new instance of `Editor`.
     *
     * @param size_t x-coordinate.
     *
     * @param size_t y-coordinate.
     *
     */
    void add_point(size_t, size_t);

    /**
     * @brief Creates new instance of `Editor`.
     *
     * @param size_t instanse of point.
     *
     * @param size_t circle radius.
     *
     */
    void add_circle(const Point &, size_t);

private:
    std::shared_ptr<IDocument> m_document_ptr;
};
