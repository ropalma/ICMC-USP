#include "dsexceptions.h"
#include "List.h"
#include "Vector.h"

#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

static const int NUMS_PER_LINE = 14;


template <typename Object>
class Stack 
{
  public:
    bool isEmpty( ) const
      { return theList.empty( ); }
    const Object & top( ) const
      { return theList.front( ); }
    void push( const Object & x )
      { theList.push_front( x ); }
    void pop( Object & x )
      { x = theList.front( ); theList.pop_front( ); }
  private:
    List<Object> theList;
};

template <typename Object>
class Queue
{
  public:
    bool isEmpty( ) const
      { return theList.empty( ); }
    const Object & getFront( ) const
      { return theList.front( ); }
    void enqueue( const Object & x )
      { theList.push_back( x ); }
    void dequeue( Object & x )
      { x = theList.front( ); theList.pop_front( ); }
  private:
    List<Object> theList;
};

template <typename Collection>
void printCollection( const Collection & c )
{
    cout << "Collection contains: " << c.size( ) << " items" << endl;
    int i = 1;

    if( c.empty( ) )
        cout << "Empty container." << endl;
    else
    {
        for( auto x : c  )
        {
            cout << x << " ";
            if( i++ % NUMS_PER_LINE == 0 )
                cout << endl;
        }
        cout << endl;

        if( c.size( ) > NUMS_PER_LINE )
            return;
        cout << "In reverse: " << endl;
        for( auto ritr = end( c ); ritr != begin( c ); )
            cout << *--ritr << " ";
        cout << endl << endl;
    }
}


int jos( int people, int passes, List<int> & order )
{
    List<int> theList;
    List<int>::iterator p = begin( theList );
    List<int>::iterator tmp;
    Stack<int> s;
    Queue<int> q;

    order = List<int>{ };

    int i;
    for( i = people; i >= 1; --i )
        p = theList.insert( p, i );

    while( people-- != 1 )
    {
        for( i = 0; i < passes; ++i )
            if( ++p == end( theList ) )
                p = begin( theList );

        order.push_back( *p );
        s.push( *p );
        q.enqueue( *p );
        tmp = p;
        if( ++p == end( theList ) )
            p = begin( theList);
        theList.erase( tmp );
    }

    if( order.size( ) % 2 == 0 )
    {
        s.push( 0 );
        q.enqueue( 0 );
    }

    while( !s.isEmpty( ) && !q.isEmpty( ) )
    {
        int x, y;
        s.pop( x );
        q.dequeue( y );
        if( x == y )
            cout << "Middle removed is " << x << endl;
    }
    cout << "Only unremoved is ";
    return *begin( theList );
}

    
void nonsense( int people, int passes )
{
    List<int> lastFew, theList;

    cout << jos( people, passes, lastFew ) << endl;
    
    cout << "(Removal order) ";
    printCollection( lastFew );
}


class CompareList
{
public:
    bool operator() ( const List<int> & lhs, const List<int> & rhs ) const
    { return lhs.size( ) < rhs.size( ); }
};

// Call by value, to test copy constructor
void print( const Vector<List<int>> arr )
{
    int N = arr.size( );
    
    for( int i = 0; i < N; ++i )
    {
        cout << "arr[" << i << "]:";
        
        for( auto x : arr[ i ] )
            cout << " " << x;
        
        cout << endl;
    }
}

int main( )
{
    const int N = 20;
    Vector<List<int>> arr( N );
    List<int> lst;
    
    for( int i = N - 1; i > 0; --i )
    {
        lst.push_front( i );
        arr[ i ] = lst;
    }

    print( arr );
    
    clock_t start = clock( );
    std::sort( begin( arr ), end( arr ), CompareList{ } );
    clock_t end = clock( );
    cout << "Sorting time: " << ( end - start ) << endl;
    
    print( arr );
    
    nonsense( 12, 0 );
    nonsense( 12, 1 );
  //  nonsense( 3737, 37 );
    
    return 0;
}
