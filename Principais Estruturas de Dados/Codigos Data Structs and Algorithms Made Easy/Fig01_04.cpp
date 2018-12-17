#include <iostream>
using namespace std;

void printDigit( int n )
{
    cout << n;
}

void printOut( int n )  // Print nonnegative n
{
    if( n >= 10 )
        printOut( n / 10 );
    printDigit( n % 10 );
}

int main(  )
{
    printOut( 1369 );
    cout << endl;
    return 0;
}
