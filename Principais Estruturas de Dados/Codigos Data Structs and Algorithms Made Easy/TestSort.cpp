#include <iostream>
#include "Sort.h"
#include <vector>
#include <string>
#include "UniformRandom.h"

using namespace std;

void checkSort( const vector<string> & a )
{
    for( int i = 0; i < a.size( ); ++i )
        if( a[ i ].length( ) != i )
            cout << "Error at " << i << endl;
    cout << "Finished checksort" << endl;
}


template <typename AnyType>
void permute( vector<AnyType> & a )
{
    static UniformRandom r;

    for( int j = 1; j < a.size( ); ++j )
        swap( a[ j ], a[ r.nextInt( 0, j ) ] );
}


int main( )
{
    const int NUM_ITEMS = 1000;

    vector<string> a( NUM_ITEMS );        // This input adds factor of N to running time
    for( int i = 1; i < a.size( ); ++i )  // but we want to test std::move logic
        a[ i ] = a[ i - 1 ] + 'a';

    for( int theSeed = 0; theSeed < 10; ++theSeed )
    {
        permute( a );
        insertionSort( a );
        checkSort( a );

        permute( a );
        insertionSort( begin( a ), end( a ) );
        checkSort( a );

        permute( a );
        heapsort( a );
        checkSort( a );

        permute( a );
        shellsort( a );
        checkSort( a );

        permute( a );
        mergeSort( a );
        checkSort( a );
        
        permute( a );
        quicksort( a );
        checkSort( a );

        permute( a );
        SORT( a );
        checkSort( a );

        permute( a );
        quickSelect( a, NUM_ITEMS / 2 );
        cout << a[ NUM_ITEMS / 2 - 1 ].length( ) << " " << NUM_ITEMS / 2 << endl;
    }

    cout << "Checking SORT, Fig 7.13" << endl;
    int N = NUM_ITEMS * NUM_ITEMS;
    vector<int> b( N );
    for( int i = 0; i < N; ++i )
        b[ i ] = i;
    permute( b );
    SORT( b );
    for( int i = 0; i < N; ++i )
        if( b[ i ] != i )
            cout << "OOPS!!" << endl;
    
    return 0;
}
