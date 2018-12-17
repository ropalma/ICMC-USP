#ifndef MEMORY_CELL_H
#define MEMORY_CELL_H

/**
 * A class for simulating a memory cell.
 */
template <typename Object>
class MemoryCell
{
  public:
    explicit MemoryCell( const Object & initialValue = Object{ } );
    const Object & read( ) const;
    void write( const Object & x );

  private:
    Object storedValue;
};

#endif
