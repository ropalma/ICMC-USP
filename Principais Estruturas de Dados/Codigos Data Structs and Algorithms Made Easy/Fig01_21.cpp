#include <iostream>
#include <string>
using namespace std;


/**
 * A class for simulating a memory cell.
 */
template <typename Object>
class MemoryCell
{
  public:
    explicit MemoryCell( const Object & initialValue = Object{ } )
      : storedValue{ initialValue } { }
    const Object & read( ) const
      { return storedValue; }
    void write( const Object & x )
      { storedValue = x; }
    
  private:
    Object storedValue;
};

int main( )
{
    MemoryCell<int>    m1;
    MemoryCell<string> m2{ "hello" };

    m1.write( 37 );
    m2.write( m2.read( ) + " world" );
    cout << m1.read( ) << endl << m2.read( ) << endl;

    return 0;
}
