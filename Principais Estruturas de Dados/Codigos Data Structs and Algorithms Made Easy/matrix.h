#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <initializer_list>
using namespace std;

template <typename Object>
class matrix
{
  public:
    matrix( int rows, int cols ) : array( rows )
    {
        for( auto & thisRow : array )
            thisRow.resize( cols );
    }

    matrix( initializer_list<vector<Object>> lst ) : array( lst.size( ) )
    {
        int i = 0;
        for( auto & v : lst )
            array[ i++ ] = std::move( v );
    }

    matrix( const vector<vector<Object>> & v ) : array{ v }
      { } 
    matrix( vector<vector<Object>> && v ) : array{ std::move( v ) }
      { }
    
    const vector<Object> & operator[]( int row ) const
      { return array[ row ]; }
    vector<Object> & operator[]( int row )
      { return array[ row ]; }

    int numrows( ) const
      { return array.size( ); }
    int numcols( ) const
      { return numrows( ) ? array[ 0 ].size( ) : 0; }
  private:
    vector<vector<Object>> array;
};

#endif


