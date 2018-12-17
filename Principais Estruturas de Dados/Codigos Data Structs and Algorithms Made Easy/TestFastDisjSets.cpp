#include <iostream>
#include "DisjSets.h"
using namespace std;

// Test main; all finds on same output line should be identical
int main( )
{
    int numElements = 128;
    int numInSameSet = 16;

    DisjSets ds{ numElements };
    int set1, set2;

    for( int k = 1; k < numInSameSet; k *= 2 )
    {
        for( int j = 0; j + k < numElements; j += 2 * k )
        {
            set1 = ds.find( j );
            set2 = ds.find( j + k );
            ds.unionSets( set1, set2 );
        }
    }

    for( int i = 0; i < numElements; ++i )
    {
        cout << ds.find( i ) << "*";
        if( i % numInSameSet == numInSameSet - 1 )
            cout << endl;
    }
    cout << endl;

    return 0;
}
