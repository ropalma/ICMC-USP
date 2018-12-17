
#include <list>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

template <typename Container>
void removeEveryOtherItem( Container & lst )
{
    auto itr = lst.begin( );
    while( itr != lst.end( ) )
    {
        itr = lst.erase( itr );
        if( itr != lst.end( ) )
            ++itr;
    }
}

template <typename Container>
void print( const Container & c, ostream & out = cout )
{
    if( c.empty( ) )
        out << "(empty)";
    else
    {
        auto itr = begin( c );
        out << "[ " << *itr++;   // Print first item

        while( itr != end( c ) )
            out << ", " << *itr++;
        out << " ]" << endl;
    }
}

int main( )
{
    list<int> lst;
    for( int i = 0; i < 9; ++i )
        lst.push_back( i );

    removeEveryOtherItem( lst );
    print( lst, cout );

   
/*
    clock_t start, end;

    for( int N = 100001; N <= 5000000; N *= 2 )
    {
        list<int> lst;
        vector<int> vec;

        for( int i = 0; i < N; ++i )
        {
            lst.push_back( i );
            vec.push_back( i );
        }


        start = clock( );
        removeEveryOtherItem( lst );
        end = clock( );
        cout << "list " << N << " " << double(end-start)/CLOCKS_PER_SEC << endl;

        start = clock( );
        removeEveryOtherItem( vec );
        end = clock( );
        cout << "vector " << N << " " << double(end-start)/CLOCKS_PER_SEC << endl;

    }
*/
    

    return 0;
}

