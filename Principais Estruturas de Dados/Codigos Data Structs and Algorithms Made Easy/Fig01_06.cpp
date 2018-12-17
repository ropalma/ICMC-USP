
#include <iostream>
using namespace std;

/**
 * A class for simulating an integer memory cell.
 */
class IntCell
{
  public:
    explicit IntCell( int initialValue = 0 )
      : storedValue{ initialValue } { }
    int read( ) const
      { return storedValue; }
    void write( int x )
      { storedValue = x; }
  private:
    int storedValue;
};

int main( )
{
    IntCell m;

    m.write( 5 );
    cout << "Cell contents: " << m.read( ) << endl;

    return 0;
}
