#include <iostream>
#include <vector>
using namespace std;

/**
 * Quick illustration of a two-dimensional tree.
 * No abstraction here.
 */
template <typename Comparable>
class KdTree
{
  public:
    KdTree( ) : root( nullptr ) { }

    void insert( const vector<Comparable> & x )
    {
        insert( x, root, 0 );
    }

    /**
     * Print items satisfying
     * low[ 0 ] <= x[ 0 ] <= high[ 0 ] and
     * low[ 1 ] <= x[ 1 ] <= high[ 1 ]
     */
    void printRange( const vector<Comparable> & low, 
                        const vector<Comparable> & high ) const
    {
        printRange( low, high, root, 0 );
    }

  private:
    struct KdNode
    {
        vector<Comparable> data;
        KdNode            *left;
        KdNode            *right;

        KdNode( const vector<Comparable> & item )
          : data( item ), left( nullptr ), right( nullptr ) { }
    };

    KdNode *root;

    void insert( const vector<Comparable> & x, KdNode * & t, int level )
    {
        if( t == nullptr )
            t = new KdNode( x );
        else if( x[ level ] < t->data[ level ] )
            insert( x, t->left, 1 - level );
        else
            insert( x, t->right, 1 - level );
    }

    void printRange( const vector<Comparable> & low,
                     const vector<Comparable> & high,
                     KdNode *t, int level ) const
    {
        if( t != nullptr )
        {
            if( low[ 0 ] <= t->data[ 0 ] && high[ 0 ] >= t->data[ 0 ] && 
                low[ 1 ] <= t->data[ 1 ] && high[ 1 ] >= t->data[ 1 ] )
                cout << "(" << t->data[ 0 ] << "," 
                            << t->data[ 1 ] << ")" << endl;

            if( low[ level ] <= t->data[ level ] )
                printRange( low, high, t->left, 1 - level );
            if( high[ level ] >= t->data[ level ] )
                printRange( low, high, t->right, 1 - level );
        }
    }
};

// Test program
int main( )
{
    KdTree<int> t;
    
    cout << "Starting program" << endl;
    for( int i = 300; i < 370; ++i )
    {
        vector<int> it( 2 );
        it[ 0 ] =  i;
        it[ 1 ] =  2500 - i;
        t.insert( it );
    }

    vector<int> low( 2 ), high( 2 );
    low[ 0 ] = 70;
    low[ 1 ] = 2186;
    high[ 0 ] = 1200;
    high[ 1 ] = 2200;

    t.printRange( low, high );

    return 0;
}
