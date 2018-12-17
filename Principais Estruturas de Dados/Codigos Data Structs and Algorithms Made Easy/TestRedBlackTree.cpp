#include <iostream>
#include "RedBlackTree.h"
using namespace std;

    // Test program
int main( )
{
    const int NEG_INF = -9999;
    RedBlackTree<int> t{ NEG_INF };
    int NUMS = 400000;
    const int GAP  =   37;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        t.insert( i );

    if( NUMS < 40 )
        t.printTree( );
    if( t.findMin( ) != 1 || t.findMax( ) != NUMS - 1 )
        cout << "FindMin or FindMax error!" << endl;

    for( i = 1; i < NUMS; ++i )
        if( !t.contains( i ) )
            cout << "Find error1!" << endl;
    if( t.contains( 0 ) )
        cout << "Oops!" << endl;

    
    RedBlackTree<int> t2{ NEG_INF };
    t2 = t;

    for( i = 1; i < NUMS; ++i )
        if( !t2.contains( i ) )
            cout << "Find error1!" << endl;
    if( t2.contains( 0 ) )
        cout << "Oops!" << endl;

    cout << "Test complete..." << endl;
    return 0;
}
