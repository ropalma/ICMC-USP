#include "Vector.h"
#include <iostream>
#include <algorithm>
using namespace std;

void print( const Vector<Vector<int>> arr )
{
    int N = arr.size( );
    
    for( int i = 0; i < N; ++i )
    {
        cout << "arr[" << i << "]:";
        
        for( int j = 0; j < arr[ i ].size( ); ++j )
            cout << " " << arr[ i ][ j ];
        
        cout << endl;
    }
}

class CompareVector
{
public:
    bool operator() ( const Vector<int> & lhs, const Vector<int> & rhs ) const
    { return lhs.size( ) < rhs.size( ); }
};

int main( )
{
    const int N = 20;
    Vector<Vector<int>> arr( N );
    Vector<int> v;
    
    for( int i = N - 1; i > 0; --i )
    {
        v.push_back( i );
        arr[ i ] = v;
    }

    print( arr );
    
    clock_t start = clock( );
    std::sort( begin( arr ), end( arr ), CompareVector{ } );
    clock_t end = clock( );
    cout << "Sorting time: " << ( end - start ) << endl;
    
    print( arr );
    
    return 0;
}

