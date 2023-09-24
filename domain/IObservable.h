#pragma once

#include <memory>

#include "IObserver.h"

/**
 * @brief Represents observable pattern interface.
 */
class IObservable
{
public:
    /**
     * @brief Destructs instance of `IObservable`.
     */
    virtual ~IObservable() = default;

    /**
     * @brief Subscribe to an instance of `std::shared_ptr<IObserver>` to detect state changes.
     * 
     * @param std::shared_ptr<IObserver>& reference to instance of observer. 
     */
    virtual void subscribe(const std::shared_ptr<IObserver>&) = 0;

    /**
     * @brief Unsubscribe to an instance of `std::shared_ptr<IObserver>` to detect state changes.
     * 
     * @param std::shared_ptr<IObserver>& reference to instance of observer. 
     */
    virtual void unsubscribe(const std::shared_ptr<IObserver>&) = 0;

    /**
     * @brief Nofifies subsribers about state changes.
     */
    virtual void notify() = 0;
};