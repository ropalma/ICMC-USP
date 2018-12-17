#include <iostream>
#include <vector>
using namespace std;

/**
 * Print container from start up to but not including end.
 */
template <typename Iterator>
void print( Iterator start, Iterator end, ostream & out = cout )
{
    if( start == end )
        return;

    out << *start++ << endl;   // Print and advance start
    print( start, end, out );
}

/**
 * Print container from start up to but not including end.
 */
template <typename Iterator>
void print2( Iterator start, Iterator end, ostream & out = cout )
{
    while( true )
    {
        if( start == end )
            return;

        out << *start++ << endl;   // Print and advance start
    }
}

int main( )
{
    int N = 50000;
    vector<int> v;

    for( int i = 0; i < N; ++i )
        v.push_back( i );

    print( begin( v ), end( v ) );
    //print2( begin( v ), end( v ) );

    return 0;
}
