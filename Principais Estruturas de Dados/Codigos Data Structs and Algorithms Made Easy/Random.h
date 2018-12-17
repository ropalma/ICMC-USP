#ifndef RANDOM_H
#define RANDOM_H

// Random class
// This code assumes 32-bit ints,
// which are standard on modern compilers.
//
// CONSTRUCTION: with (a) no initializer or (b) an integer
//     that specifies the initial state of the generator
//
// ******************PUBLIC OPERATIONS*********************
//     Return a random number according to some distribution:
// int randomInt( )                     --> Uniform, 1 to 2^31-1
// int random0_1( )                     --> Uniform, 0 to 1
// int randomInt( int low, int high )   --> Uniform low..high

class Random
{
  public:
    explicit Random( int initialValue = 1 );

    int randomInt( );
    int randomIntWRONG( );
    double random0_1( );
    int randomInt( int low, int high );

  private:
    int state;
};


#endif
