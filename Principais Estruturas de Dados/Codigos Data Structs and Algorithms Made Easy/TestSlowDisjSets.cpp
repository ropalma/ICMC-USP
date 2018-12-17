// DisjSets class
//
// CONSTRUCTION: with int representing initial number of sets
//
// ******************PUBLIC OPERATIONS*********************
// void union( root1, root2 ) --> Merge two sets
// int find( x )              --> Return set containing x
// ******************ERRORS********************************
// No error checking is performed

#include <iostream>
#include <vector>
using namespace std;

/**
 * Disjoint set class.
 * Does not use union heuristics or path compression.
 * Elements in the set are numbered starting at 0.
 */
class DisjSets
{
    public:
        DisjSets( int numElements );
    
        int find( int x ) const;
        void setUnion( int root1, int root2 );

    private:
        vector<int> s;
};

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjSets::DisjSets( int numElements ) : s( numElements )
{
    for( auto & link : s )
        link = -1;
}

/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 */
void DisjSets::setUnion( int root1, int root2 )
{
    s[ root2 ] = root1;
}

/**
 * Perform a find.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find( int x ) const
{
    if( s[ x ] < 0 )
        return x;
    else
        return find( s[ x ] );
}

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
            ds.setUnion( set1, set2 );
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
