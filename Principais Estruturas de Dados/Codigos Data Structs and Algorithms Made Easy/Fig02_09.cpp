#include <iostream>
#include <vector>
using namespace std;

const int NOT_FOUND = -1;

/**
 * Performs the standard binary search using two comparisons per level.
 * Returns index where item is found or -1 if not found
 */
template <typename Comparable>
int binarySearch( const vector<Comparable> & a, const Comparable & x )
{
    int low = 0, high = a.size( ) - 1;

    while( low <= high )
    {
        int mid = ( low + high ) / 2;

        if( a[ mid ] < x )
            low = mid + 1;
        else if( a[ mid ] > x )
            high = mid - 1;
        else
            return mid;   // Found
    }
    return NOT_FOUND;     // NOT_FOUND is defined as -1
}

// Test program
int main( )
{
    const int SIZE = 8;
    vector<int> a( SIZE );

    for( int i = 0; i < SIZE; ++i )
        a[ i ] = i * 2;

    for( int j = 0; j < SIZE * 2; ++j )
        cout << "Found " << j << " at " << binarySearch( a, j ) << endl;
    
    return 0;
}
