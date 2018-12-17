#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iterator>
#include <stdexcept>
using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::invalid_argument;
using std::sort;
  
void makeLCPArray( vector<int> & s, const vector<int> & sa, vector<int> & LCP );
void createSuffixArray( const string & str, vector<int> & sa, vector<int> & LCP );
void makeSuffixArray( const vector<int> & s, vector<int> & SA, int n, int K );
int assignNames( const vector<int> & s, vector<int> & s12, vector<int> & SA12,
                                int n0, int n12, int K );
void radixPass( const vector<int> & in, vector<int> & out,
                const vector<int> & s, int offset, int n, int K );
void radixPass( const vector<int> & in, vector<int> & out,
                const vector<int> & s, int n, int K );
void computeS12( vector<int> & s12, vector<int> & SA12, int n12, int K12 );
void computeS0( const vector<int> & s, vector<int> & s0,
                vector<int> & SA0, const vector<int> & SA12,
                            int n0, int n12, int K );
void merge( const vector<int> & s, const vector<int> & s12,
            vector<int> & SA, const vector<int> & SA0, const vector<int> & SA12,
                            int n, int n0, int n12, int t );
int getIndexIntoS( const vector<int> & SA12, int t, int n0 );
bool leq( int a1, int a2, int b1, int b2 );
bool leq( int a1, int a2, int a3, int b1, int b2, int b3 );
bool suffix12IsSmaller( const vector<int> & s, const vector<int> & s12,
                        const vector<int> & SA12, int n0, int i, int j, int t );
void printV( const vector<int> & a, const string & comment);
bool isPermutation( const vector<int> & SA, int n );
bool sleq( const vector<int> & s1, int start1, const vector<int> & s2, int start2 );
bool isSorted( const vector<int> & SA, const vector<int> & s, int n );
void assert0( bool cond );
int computeLCP( const string & s1, const string & s2 );
void createSuffixArraySlow( const string & str, vector<int> & SA, vector<int> & LCP );


/*
 * Create the LCP array from the suffix array
 * s is the input array populated from 0..N-1, with available pos N
 * sa is an already-computed suffix array 0..N-1
 * LCP is the resulting LCP array 0..N-1
 */
void makeLCPArray( vector<int> & s, const vector<int> & sa, vector<int> & LCP )
{
    int N = sa.size( );
    vector<int> rank( N );

    s[ N ] = -1;
    for( int i = 0; i < N; ++i )
        rank[ sa[ i ] ] = i;

    int h = 0;
    for( int i = 0; i < N; ++i )
        if( rank[ i ] > 0 )
        {
            int j = sa[ rank[ i ] - 1 ];

            while( s[ i + h ] == s[ j + h ] )
                ++h;

            LCP[ rank[ i ] ] = h;
            if( h > 0 )
                --h;
        }
}

/*
 * Fill in the suffix array information for String str
 * str is the input String
 * sa is an existing array to place the suffix array
 * LCP is an existing array to place the LCP information
 */
void createSuffixArray( const string & str, vector<int> & sa, vector<int> & LCP )
{
    if( sa.size( ) != str.length( ) || LCP.size( ) != str.length( ) )
        throw invalid_argument{ "Mismatched vector sizes" };
    
    int N = str.length( );

    vector<int> s( N + 3 );
    vector<int> SA( N + 3 );

    for( int i = 0; i < N; ++i )
        s[ i ] = str[ i ];

    makeSuffixArray( s, SA, N, 256 );

    for( int i = 0; i < N; ++i )
        sa[ i ] = SA[ i ];

    makeLCPArray( s, sa, LCP );
}

// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void makeSuffixArray( const vector<int> & s, vector<int> & SA, int n, int K )
{
    int n0 = ( n + 2 ) / 3;
    int n1 = ( n + 1 ) / 3;
    int n2 = n / 3;
    int t = n0 - n1;  // 1 iff n%3 == 1
    int n12 = n1 + n2 + t;

    vector<int> s12( n12 + 3 );
    vector<int> SA12( n12 + 3 );
    vector<int> s0( n0 );
    vector<int> SA0( n0 );

    // generate positions in s for items in s12
    // the "+t" adds a dummy mod 1 suffix if n%3 == 1
    // at that point, the size of s12 is n12
    for( int i = 0, j = 0; i < n + t; ++i )
        if( i % 3 != 0 )
            s12[ j++ ] = i;

    int K12 = assignNames( s, s12, SA12, n0, n12, K );

    computeS12( s12, SA12, n12, K12 );
    computeS0( s, s0, SA0, SA12, n0, n12, K );
    merge( s, s12, SA, SA0, SA12, n, n0, n12, t );
}


// Assigns the new supercharacter names.
// At end of routine, SA will have indices into s, in sorted order
// and s12 will have new character names
// Returns the number of names assigned; note that if
// this value is the same as n12, then SA is a suffix array for s12.
int assignNames( const vector<int> & s, vector<int> & s12, vector<int> & SA12,
                 int n0, int n12, int K )
{
      // radix sort the new character trios
    radixPass( s12 , SA12, s, 2, n12, K );
    radixPass( SA12, s12 , s, 1, n12, K );  
    radixPass( s12 , SA12, s, 0, n12, K );

      // find lexicographic names of triples
    int name = 0;
    int c0 = -1, c1 = -1, c2 = -1;

    for( int i = 0; i < n12; ++i )
    {
        if( s[ SA12[ i ] ] != c0 || s[ SA12[ i ] + 1 ] != c1
                                    || s[ SA12[ i ] + 2 ] != c2 )
        { 
            ++name;
            c0 = s[ SA12[ i ] ];
            c1 = s[ SA12[ i ] + 1 ];
            c2 = s[ SA12[ i ] + 2 ];
        }

        if( SA12[ i ] % 3 == 1 )
            s12[ SA12[ i ] / 3 ]      = name;   // S1
        else
            s12[ SA12[ i ] / 3 + n0 ] = name;   // S2
    }

    return name;
}


// stably sort in[0..n-1] with indices into s that has keys in 0..K
// into out[0..n-1]; sort is relative to offset into s
// uses counting radix sort
void radixPass( const vector<int> & in, vector<int> & out,
                const vector<int> & s, int offset, int n, int K ) 
{ 
    vector<int> count( K + 2 );                  // counter array

    for( int i = 0; i < n; ++i )
        ++count[ s[ in[ i ] + offset ] + 1 ];    // count occurrences

    for( int i = 1; i <= K + 1; ++i )            // compute exclusive sums
        count[ i ] += count[ i - 1 ];

    for( int i = 0; i < n; ++i )
        out[ count[ s[ in[ i ] + offset ] ]++ ] = in[ i ];      // sort
} 

// stably sort in[0..n-1] with indices into s that has keys in 0..K
// into out[0..n-1]
// uses counting radix sort
void radixPass( const vector<int> & in, vector<int> & out,
                const vector<int> & s, int n, int K ) 
{ 
    radixPass( in, out, s, 0, n, K );
}


// Compute the suffix array for s12, placing result into SA12
void computeS12( vector<int> & s12, vector<int> & SA12, int n12, int K12 )
{
    if( K12 == n12 ) // if unique names, don't need recursion
        for( int i = 0; i < n12; ++i )
            SA12[ s12[i] - 1 ] = i; 
    else
    {
        makeSuffixArray( s12, SA12, n12, K12 );
          // store unique names in s12 using the suffix array 
        for( int i = 0; i < n12; ++i )
            s12[ SA12[ i ] ] = i + 1;
    }
}

void computeS0( const vector<int> & s, vector<int> & s0,
                vector<int> & SA0, const vector<int> & SA12,
                            int n0, int n12, int K )
{
    for( int i = 0, j = 0; i < n12; ++i )
        if( SA12[ i ] < n0 )
            s0[ j++ ] = 3 * SA12[ i ];

    radixPass( s0, SA0, s, n0, K );
}


// merge sorted SA0 suffixes and sorted SA12 suffixes
void merge( const vector<int> & s, const vector<int> & s12,
            vector<int> & SA, const vector<int> & SA0, const vector<int> & SA12,
            int n, int n0, int n12, int t )
{      
    int p = 0, k = 0;

    while( t != n12 && p != n0 )
    {
        int i = getIndexIntoS( SA12, t, n0 ); // S12
        int j = SA0[ p ];                     // S0

        if( suffix12IsSmaller( s, s12, SA12, n0, i, j, t ) )
        { 
            SA[ k++ ] = i;
            ++t;
        }
        else
        { 
            SA[ k++ ] = j;
            ++p;
        }  
    } 

    while( p < n0 )
        SA[ k++ ] = SA0[ p++ ];
    while( t < n12 )
        SA[ k++ ] = getIndexIntoS( SA12, t++, n0 ); 
}

int getIndexIntoS( const vector<int> & SA12, int t, int n0 )
{
    if( SA12[ t ] < n0 )
        return SA12[ t ] * 3 + 1;
    else
        return ( SA12[ t ] - n0 ) * 3 + 2;
}

  // True if [a1 a2] <= [b1 b2]
bool leq( int a1, int a2, int b1, int b2 )
    { return a1 < b1 || a1 == b1 && a2 <= b2; }

  // True if [a1 a2] <= [b1 b2 b3]
bool leq( int a1, int a2, int a3, int b1, int b2, int b3 )
    { return a1 < b1 || a1 == b1 && leq( a2, a3,b2, b3 ); }

bool suffix12IsSmaller( const vector<int> & s, const vector<int> & s12,
                        const vector<int> & SA12, int n0, int i, int j, int t )
{
    if( SA12[ t ] < n0 )  // s1 vs s0; can break tie after 1 character
        return leq( s[ i ], s12[ SA12[ t ] + n0 ],
                    s[ j ], s12[ j / 3 ] );
    else                  // s2 vs s0; can break tie after 2 characters
        return leq( s[ i ], s[ i + 1 ], s12[ SA12[ t ] - n0 + 1 ],
                    s[ j ], s[ j + 1 ], s12[ j / 3 + n0 ] );
}

void printV( const vector<int> & a, const string & comment)
{
    cout << comment << ":";
    for( int i = 0; i < a.size( ); ++i )  // use old loop style for old compilers
        cout << a[ i ] << " ";

    cout << endl;
}

bool isPermutation( const vector<int> & SA, int n )
{
    vector<bool> seen( n );

    for( int i = 0; i < n; ++i )
        seen[ i ] = false;

    for( int i = 0; i < n; ++i )
        seen[ SA[ i ] ] = true;

    for( int i = 0; i < n; ++i )
        if( !seen[ i ] )
            return false;

    return true;
}

bool sleq( const vector<int> & s1, int start1, const vector<int> & s2, int start2 )
{
    for( int i = start1, j = start2; ; ++i, ++j )
    {
        if( s1[ i ] < s2[ j ] )
            return true;

        if( s1[ i ] > s2[ j ] )
            return false;
    }
} 

// is SA a sorted suffix array for s?
bool isSorted( const vector<int> & SA, const vector<int> & s, int n )
{
    for( int i = 0; i < n-1; ++i )
        if( !sleq( s, SA[ i ], s, SA[ i + 1 ] ) )
            return false;

    return true;  
}



void assert0( bool cond )
{
    if( !cond )
        throw "ASSERTION EXCEPTION";
}


int main( )
{
    const string abr = "banana";
    vector<int> sufarr( abr.length( ) );
    vector<int> LCP( abr.length( ) );


    createSuffixArraySlow( "banana", sufarr, LCP );

    cout << "SLOW ALGORITHM" << endl;
    for( int i = 0; i < abr.length( ); ++i )
        cout << i << " " << sufarr[ i ] << " " << LCP[ i ] << endl;

    cout << "FAST ALGORITHM" << endl;
    createSuffixArray( "banana", sufarr, LCP );

    for( int i = 0; i < abr.length( ); ++i )
        cout << i << " " << sufarr[ i ] << " " << LCP[ i ] << endl;
    
    return 0;
}


/*
 * Returns the LCP for any two strings
 */
int computeLCP( const string & s1, const string & s2 )
{
    int i = 0;

    while( i < s1.length( ) && i < s2.length( ) && s1[ i ] == s2[ i ] )
        ++i;

    return i;
}

/*
 * Fill in the suffix array and LCP information for String str
 * str is the input String
 * SA is an existing array to place the suffix array
 * LCP is an existing array to place the LCP information
 */
void createSuffixArraySlow( const string & str, vector<int> & SA, vector<int> & LCP )
{
    if( SA.size( ) != str.length( ) || LCP.size( ) != str.length( ) )
        throw invalid_argument{ "Mismatched vector sizes" };

    size_t N = str.length( );

    vector<const char *> suffixes( N );
    const char *cstr = str.c_str( );

    for( int i = 0; i < N; ++i )
        suffixes[ i ] = cstr + i; 

    sort( begin( suffixes ), end( suffixes ),
      [] ( const char *s1, const char *s2 ) { return strcmp( s1, s2 ) < 0; } );

    for( int i = 0; i < N; ++i )
        SA[ i ] = suffixes[ i ] - cstr;

    LCP[ 0 ] = 0;
    for( int i = 1; i < N; ++i )
        LCP[ i ] = computeLCP( suffixes[ i - 1 ], suffixes[ i ] );
}

