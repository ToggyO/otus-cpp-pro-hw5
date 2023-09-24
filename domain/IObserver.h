#pragma once

#include <memory>

/**
 * @brief Represents observer pattern interface.
 */
class IObserver
{
public:
    /**
     * @brief Destructs instance of `IObserver`.
     */
    virtual ~IObserver() = default;

    /**
     * @brief Callback action.
     */
    virtual void update() = 0; 
};