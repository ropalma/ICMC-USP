#include <iostream>
#include "matrix.h"
using namespace std;

const int NOT_A_VERTEX = -1;

/**
 * Compute all-shortest paths.
 * a contains the adjacency matrix with
 * a[ i ][ i ] presumed to be zero.
 * d contains the values of the shortest path.
 * Vertices are numbered starting at 0; all arrays
 * have equal dimension. A negative cycle exists if
 * d[ i ][ i ] is set to a negative value.
 * Actual path can be computed using path[ ][ ].
 * NOT_A_VERTEX is -1
 */
void allPairs( const matrix<int> & a,
               matrix<int> & d, matrix<int> & path ) 
{
    int n = a.numrows( );

    // Initialize d and path
    for( int i = 0; i < n; ++i )
        for( int j = 0; j < n; ++j )
        {
            d[ i ][ j ] = a[ i ][ j ];
            path[ i ][ j ] = NOT_A_VERTEX;
        }

    for( int k = 0; k < n; ++k )
        // Consider each vertex as an intermediate
        for( int i = 0; i < n; ++i )
            for( int j = 0; j < n; ++j )
                if( d[ i ][ k ] + d[ k ][ j ] < d[ i ][ j ] )
                {
                    // Update shortest path
                    d[ i ][ j ] = d[ i ][ k ] + d[ k ][ j ];
                    path[ i ][ j ] = k;
                }
}

int main( )
{
    matrix<int> a
    { {
        { 0, 2, -2, 2 },
        { 1000, 0, -3, 1000 },
        { 4, 1000, 0, 1000 },
        { 1000, -2, 3, 0 }
    } };

    matrix<int> d( 4, 4 );
    matrix<int> path( 4, 4 );

    allPairs( a, d, path );
    int i;
    for( i = 0; i < d.numrows( ); ++i )
    {
        for( int j = 0; j < d.numcols( ); ++j )
            cout << d[ i ][ j ] << "    " ;
        cout << endl;
    }
    for( i = 0; i < path.numrows( ); ++i )
    {
        for( int j = 0; j < path.numcols( ); ++j )
            cout << path[ i ][ j ] << "    " ;
        cout << endl;
    }

    return 0;
}
