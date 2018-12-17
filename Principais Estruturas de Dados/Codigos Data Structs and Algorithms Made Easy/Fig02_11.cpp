#include <iostream>
using namespace std;

bool isEven( int n )
{
    return n % 2 == 0;
}

long long pow( long long x, int n )
{
    if( n == 0 )
        return 1;
    if( n == 1 )
        return x;
    if( isEven( n ) )
        return pow( x * x, n / 2 );
    else
        return pow( x * x, n / 2 ) * x;
}

// Test program
int main( )
{
    cout << "2^61 = " << pow( 2, 61 ) << endl;
    cout << "2^62 = " << pow( 2, 62 ) << endl;
    
    return 0;
}
