#pragma

#include <list>
#include <vector>

#include "IDocument.h"

/**
 * @brief Represents editor document model implementation.
 */
class Document : public IDocument
{
public:
    Document() = default;
    Document(const Document &) = delete;
    Document(Document &&) = default;

    Document& operator=(const Document &) = delete;
    Document& operator=(Document &&) = default;

    /**
     * @copydoc IDocument::open(const std::string_view))
     * 
     * Opens a document from a file at the specified file path.
     */
    virtual void open(const std::string_view) override;

    /**
     * @copydoc IDocument::save()
     * 
     * Saves the document model state.
     */
    virtual void save() override;

    /**
     * @copydoc IDocument::clear()
     * 
     * Clears the document model state.
     */
    virtual void clear() override;

    /**
     * @copydoc IEditableDocument::add_shape(std::unique_ptr<IShape>)
     * 
     * Adds a new shape to the document model.
     */
    virtual void add_shape(std::unique_ptr<IShape>) override;

    /**
     * @copydoc IEditableDocument::remove_shape(std::unique_ptr<IShape>)
     * 
     * Removes a new shape to the document model.
     */
    virtual void remove_shape(std::unique_ptr<IShape>) override;

    /**
     * @copydoc std::vector<std::unique_ptr<IShape>>::const_iterator IEditableDocument::cbegin() 
     * 
     * @brief Returns an iterator to first position of container, that contains shapes.
     */
    [[nodiscard]] std::list<std::unique_ptr<IShape>>::const_iterator cbegin() const;

    /**
     * @copydoc std::vector<std::unique_ptr<IShape>>::const_iterator IEditableDocument::cend() 
     * 
     * @brief Returns an iterator to last position of container, that contains shapes.
     */
    [[nodiscard]] std::list<std::unique_ptr<IShape>>::const_iterator cend() const;

    /**
     * @copydoc IObserver::subscribe(const std::shared_ptr<IObserver>&)
     * 
     * Subscribe to an instance of `std::shared_ptr<IObserver>` to detect state changes.
     */
    virtual void subscribe(const std::shared_ptr<IObserver>&) override;

    /**
     * @copydoc IObserver::unsubscribe(const std::shared_ptr<IObserver>&)
     * 
     * Unsubscribe to an instance of `std::shared_ptr<IObserver>` to detect state changes.
     */
    virtual void unsubscribe(const std::shared_ptr<IObserver>& ptr) override;

    /**
     * @copydoc IObserver::update
     * 
     * Nofifies subsribers about state changes.
     */
    virtual void notify() override;

protected:
    /**
     * @static
     *
     * @protected
     * 
     * @brief Creates a comparer lamda.
     * 
     * @param ptr instance of shared pointer to compare with
     */
    auto static get_comparer(const std::shared_ptr<IObserver> &ptr);

    std::list<std::weak_ptr<IObserver>> m_observers;

    std::list<std::unique_ptr<IShape>> m_shapes;
};
