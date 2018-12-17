#include <iostream>
#include "matrix.h"

using namespace std;

/**
 * Standard matrix multiplication.
 * Arrays start at 0.
 * Assumes a and b are square.
 */
matrix<int> operator*( const matrix<int> & a, const matrix<int> & b )
{
    int n = a.numrows( );
    matrix<int> c{ n, n };

    for( int i = 0; i < n; ++i )    // Initialization
        for( int j = 0; j < n; ++j )
            c[ i ][ j ] = 0;

    for( int i = 0; i < n; ++i )
        for( int j = 0; j < n; ++j )
            for( int k = 0; k < n; ++k )
                c[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];

    return c;
}

int main( )
{
    matrix<int> a { { 1, 2 }, { 3, 4 } };
    matrix<int> c = a * a;

    cout << c[ 0 ][ 0 ] << " " << c[ 0 ][ 1 ] << endl <<
                        c[ 1 ][ 0 ] << " " << c[ 1 ][ 1 ] << endl;

    return 0;
}
