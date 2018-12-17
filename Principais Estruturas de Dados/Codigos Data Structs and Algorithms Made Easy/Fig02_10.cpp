#include <iostream>
using namespace std;

long gcd( long m, long n )
{
    while( n != 0 )
    {
        long rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

// Test program
int main( )
{
    cout << "gcd( 45, 35 ) = " << gcd( 45, 35 ) << endl;
    cout << "gcd( 1989, 1590 ) = " << gcd( 1989, 1590 ) << endl;
    return 0;
}
