#include "MemoryCell.h"

/**
 * Construct the MemoryCell with initialValue
 */
template <typename Object>
MemoryCell<Object>::MemoryCell( const Object & initialValue )
    : storedValue( initialValue )
{
}

/**
 * Return the stored value
 */
template <typename Object>
const Object & MemoryCell<Object>::read( ) const
{
    return storedValue;
}

/**
 * Store x.
 */
template <typename Object>
void MemoryCell<Object>::write( const Object & x )
{
    storedValue = x;
}

