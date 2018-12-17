#include <iostream>
#include "Random.h"
using namespace std;

typedef long long HugeInt;

/**
 * Function that implements the basic primality test.
 * If witness does not return 1, n is definitely composite.
 * Do this by computing a^i (mod n) and looking for
 * non-trivial square roots of 1 along the way.
 */
HugeInt witness( const HugeInt & a, const HugeInt & i, const HugeInt & n )
{
    if( i == 0 )
        return 1;

    HugeInt x = witness( a, i / 2, n );
    if( x == 0 )    // If n is recursively composite, stop
        return 0;

    // n is not prime if we find a non-trivial square root of 1
    HugeInt y = ( x * x ) % n;
    if( y == 1 && x != 1 && x != n - 1 )
        return 0;

    if( i % 2 != 0 )
        y = ( a * y ) % n;

    return y;
}

/**
 * The number of witnesses queried in randomized primality test.
 */
const int TRIALS = 5;

/**
 * Randomized primality test.
 * Adjust TRIALS to increase confidence level.
 * n is the number to test.
 * If return value is false, n is definitely not prime.
 * If return value is true,  n is probably prime.
 */
bool isPrime( const HugeInt & n )
{
    Random r;

      // Note: need n to be small to be compatible with randomInt
    for( int counter = 0; counter < TRIALS; ++counter )
        if( witness( r.randomInt( 2, n - 2 ), n - 1, n ) != 1 )
            return false;

    return true;
}

int main( )
{
    for( int i = 101; i < 200; i += 2 )
        if( isPrime( i ) )
            cout << i << " is prime" << endl;

    return 0;
}
