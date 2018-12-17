#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Square
{
  public:
    explicit Square( double s = 0.0 ) : side{ s }
      { }
    
    double getSide( ) const
      { return side; }
    double getArea( ) const
      { return side * side; }
    double getPerimeter( ) const
      { return 4 * side; }

    void print( ostream & out = cout ) const
      { out << "(square " << getSide( ) << ")"; }
    bool operator< ( const Square & rhs ) const
      { return getSide( ) < rhs.getSide( ); }

  private:
    double side;
};

    // Define an output operator for Square
ostream & operator<< ( ostream & out, const Square & rhs )
{
    rhs.print( out );
    return out;
}

/**
 * Return the maximum item in array a.
 * Assumes a.size( ) > 0.
 * Comparable objects must provide operator< and operator=
 */
template <typename Comparable>
const Comparable & findMax( const vector<Comparable> & a )
{
    int maxIndex = 0;

    for( int i = 1; i < a.size( ); ++i )
        if( a[ maxIndex ] < a[ i ] )
            maxIndex = i;
    
    return a[ maxIndex ];
}

int main( )
{
    vector<Square> v = { Square{ 3.0 }, Square{ 2.0 }, Square{ 2.5 } };
    
    cout << "Largest square: " << findMax( v ) << endl;

    return 0;
}
