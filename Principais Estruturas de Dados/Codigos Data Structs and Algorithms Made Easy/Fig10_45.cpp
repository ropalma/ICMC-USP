#include <iostream>
#include <vector>
using namespace std;

double eval( int n )
{
    vector<double> c( n + 1 );

    c[ 0 ] = 1.0;
    for( int i = 1; i <= n; ++i )
    {
        double sum = 0.0;
        
        for( int j = 0; j < i; ++j )
            sum += c[ j ];
        c[ i ] =  2.0 * sum / i + i;
    }

    return c[ n ];
}

int main( )
{
    cout << "eval( 10 ) = " << eval( 10 ) << endl;
    return 0;
}