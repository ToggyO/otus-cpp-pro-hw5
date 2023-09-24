#include "document.h"

auto Document::get_comparer(const std::shared_ptr<IObserver> &ptr)
{
    return [&ptr](auto &wp)
    {
        auto shared = wp.lock();
        if (shared && ptr) { return shared == ptr; }
        return false;
    };
}

void Document::open(const std::string_view path)
{
    // TODO: implement me
}

void Document::save()
{
    // TODO: implement me
}

void Document::clear()
{
    // TODO: implement me
}

void Document::add_shape(std::unique_ptr<IShape> ptr)
{
    m_shapes.push_back(std::move(ptr));
}

void Document::remove_shape(std::unique_ptr<IShape> ptr)
{
    m_shapes.push_back(std::move(ptr));
}

std::list<std::unique_ptr<IShape>>::const_iterator Document::cbegin() const
{
    return m_shapes.cbegin();
}

std::list<std::unique_ptr<IShape>>::const_iterator Document::cend() const
{
    return m_shapes.end();
}

void Document::subscribe(const std::shared_ptr<IObserver>& ptr)
{
    m_observers.emplace_back(ptr);
}

void Document::unsubscribe(const std::shared_ptr<IObserver>& ptr)
{
    m_observers.remove_if(get_comparer(ptr));
}

void Document::notify()
{
    for (const auto &observer : m_observers)
    {
        // TODO: check or use iterators
        auto ptr = observer.lock();
        if (ptr)
        {
            ptr->update();
        }
        else
        {
            m_observers.remove_if(get_comparer(ptr));
        }
    }
}
