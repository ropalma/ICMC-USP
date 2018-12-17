#include <iostream>
#include <climits>
#include "matrix.h"
using namespace std;

const int INFINITY = INT_MAX;

/**
 * Compute optimal ordering of matrix multiplication.
 * c contains the number of columns for each of the n matrices.
 * c[ 0 ] is the number of rows in matrix 1.
 * The minimum number of multiplications is left in m[ 1 ][ n ].
 * Actual ordering is computed via another procedure using lastChange.
 * m and lastChange are indexed starting at 1, instead of 0.
 * Note: Entries below main diagonals of m and lastChange
 * are meaningless and uninitialized.
 */
void optMatrix( const vector<int> & c,
                matrix<int> & m, matrix<int> & lastChange ) 
{
    int n = c.size( ) - 1;

    for( int left = 1; left <= n; ++left )
        m[ left ][ left ] = 0;
    for( int k = 1; k < n; ++k )   // k is right - left
        for( int left = 1; left <= n - k; ++left )
        {
            // For each position
            int right = left + k;
            m[ left ][ right ] = INFINITY;
            for( int i = left; i < right; ++i )
            {
                int thisCost = m[ left ][  i ] + m[ i + 1 ][ right ]
                        + c[ left - 1 ] * c[ i ] * c[ right ];
                
                if( thisCost < m[ left ][ right ] )  // Update min
                {
                    m[ left ][ right ] = thisCost;
                    lastChange[ left ][ right ] = i;
                }
            }
        }
}

int main( )
{
    vector<int> c = { 50, 10, 40, 30, 5 };
    matrix<int> m( 5, 5 );
    matrix<int>lastChange( 5, 5 );

    optMatrix( c, m, lastChange );

    int i;
    for( i = 1; i < m.numrows( ); ++i )
    {
        for( int j = 1; j < m.numcols( ); ++j )
            cout << m[ i ][ j ] << "    ";
        cout << endl;
    }
    for( i = 1; i < lastChange.numrows( ); ++i )
    {
        for( int j = 1; j < lastChange.numcols( ); ++j )
            cout << lastChange[ i ][ j ] << "    ";
        cout << endl;
    }

    return 0;
}
