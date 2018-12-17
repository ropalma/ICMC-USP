#include <iostream>
#include <sstream>
#include "CuckooHashTable.h"
using namespace std;


// Pre-c++11 style; not all compilers have new to_string function
template <typename Object>
string toString( Object x )
{
    ostringstream oss;
    oss << x;
    return oss.str( );
}


    // Simple main
int main( )
{
    const int NUMS = 2000000;
    const int GAP  =   37;
    const int ATTEMPTS = 1;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( int att = 0; att < ATTEMPTS; ++att )
    { 
        cout << "ATTEMPT: " << att << endl;
        
        HashTable<string,StringHashFamily<3>> h1;
        HashTable<string,StringHashFamily<3>> h2;
        
        for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        {
            if( !h1.insert( toString( i ) ) )
            {
                cout << "OOPS insert fails???!!!! " << i << endl;
            }
            
        }

        for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
            if( h1.insert( toString( i ) ) )
                cout << "INSERT OOPS!!! " << i << endl;
        
        h2 = h1;
        
        for( i = 1; i < NUMS; i += 2 )
            h2.remove( toString( i ) );
        
        for( i = 2; i < NUMS; i += 2 )
            if( !h2.contains( toString( i ) ) )
                cout << "Contains fails " << i << endl;
        
        for( i = 1; i < NUMS; i += 2 )
        {
            if( h2.contains( toString( i ) ) )
                cout << "CONTAINS OOPS!!! " <<  i << endl;
        }
        
        cout << "END OF ATTEMPT" << endl;
        
        if( h2.capacity( ) > NUMS * 4 )
            cout << "LARGE CAPACITY " << h2.capacity( ) << endl;
        
    }

    return 0;
}
