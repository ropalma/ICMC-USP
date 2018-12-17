#include <unordered_set>
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
using namespace std;

string toLower( const string & s )
{
    string copy = s;
    transform( copy.begin( ), copy.end( ), copy.begin( ), ptr_fun<int, int>( tolower ) );
    return copy;
}

bool equalsIgnoreCase( const string & lhs, const string & rhs )
{
    return toLower( lhs ) == toLower( rhs );
}

class CaseInsensitive
{
  public:
    size_t operator( ) ( const string & s ) const
    {  
        static hash<string> hf;
        return hf( toLower( s ) );
    }
    
    bool operator( ) ( const string & lhs, const string & rhs ) const
    {
        return equalsIgnoreCase( lhs, rhs );
    }
};

int main( )
{
    unordered_set<string,CaseInsensitive,CaseInsensitive> s;
    
    s.insert( "HELLO" );
    s.insert( "helLo" );
    s.insert( "WORLD" );
    s.insert( "world" );
    s.insert( "hello" );
    
    auto itr = s.begin( );
    
    while( itr != s.end( ) )
        cout << *itr++ << endl;
    
    return 0;
}
