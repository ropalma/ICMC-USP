#include "Random.h"

static const int A = 48271;
static const int M = 2147483647;
static const int Q = M / A;
static const int R = M % A;

/**
 * Construct with initialValue for the state.
 */
Random::Random( int initialValue )
{
    if( initialValue < 0 )
        initialValue += M;

    state = initialValue;
    if( state == 0 )
        state = 1;
}

/**
 * Return a pseudorandom int, and change the
 * internal state.
 */
int Random::randomInt( )
{
    int tmpState = A * ( state % Q ) - R * ( state / Q );

    if( tmpState >= 0 )
        state = tmpState;
    else
        state = tmpState + M;

    return state;
}

/**
 * Return a pseudorandom int, and change the
 * internal state. DOES NOT WORK.
 */
int Random::randomIntWRONG( )
{
    return state = ( A * state ) % M;
}

/**
 * Return a pseudorandom double in the open range 0..1
 * and change the internal state.
 */
double Random::random0_1( )
{
    return static_cast<double>( randomInt( ) ) / M;
}

/**
 * Return an int in the closed range [low,high], and
 * change the internal state. This is a poor implementation and
 * will be biased toward some numbers, especially if the range is large.
 */
int Random::randomInt( int low, int high )
{
    double partitionSize = static_cast<double>( M ) / ( high - low + 1 );

    return static_cast<int>( randomInt( ) / partitionSize ) + low;
}
