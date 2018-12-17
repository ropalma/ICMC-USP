#ifndef CUCKOO_HASH_TABLE_H
#define CUCKOO_HASH_TABLE_H

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include "UniformRandom.h"
using namespace std;

template <typename AnyType>
class CuckooHashFamily
{
  public:
    size_t hash( const AnyType & x, int which ) const;
    int getNumberOfFunctions( );
    void generateNewFunctions( );
};

template <int count>
class StringHashFamily
{
  public:
    StringHashFamily( ) : MULTIPLIERS( count )
    {
        generateNewFunctions( );
    }
    
    int getNumberOfFunctions( ) const
    {
        return count;
    }
    
    void generateNewFunctions( )
    {
        for( auto & mult : MULTIPLIERS )
            mult = r.nextInt( );
    }
    
    size_t hash( const string & x, int which ) const
    {
        const int multiplier = MULTIPLIERS[ which ];
        size_t hashVal = 0;

        for( auto ch : x )
            hashVal = multiplier * hashVal + ch;
        
        return hashVal;
    }

  private:
    vector<int> MULTIPLIERS;
    UniformRandom r;
};



int nextPrime( int n );


#define MAX_LOAD 0.40  /* g++ 4.6 does not support static const double */

// CuckooHashing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hashCode( string str ) --> Global method to hash strings

template <typename AnyType, typename HashFamily>
class HashTable
{
  public:
    explicit HashTable( int size = 101 ) : array( nextPrime( size ) )
    {
        numHashFunctions = hashFunctions.getNumberOfFunctions( );
        rehashes = 0;
        makeEmpty( );
    }

    bool contains( const AnyType & x ) const
    {
        return findPos( x ) != -1;
    }

    void makeEmpty( )
    {
        currentSize = 0;
        for( auto & entry : array )
            entry.isActive = false;
    }

    bool insert( const AnyType & x )
    {
        if( contains( x ) ) 
            return false;
        
        if( currentSize >= array.size( ) * MAX_LOAD )
            expand( );
        
        return insertHelper1( x );
    }
    
    bool insert( AnyType && x )
    {
        if( contains( x ) ) 
            return false;
        
        if( currentSize >= array.size( ) * MAX_LOAD )
            expand( );
        
        return insertHelper1( std::move( x ) );
    }

    int size( ) const
    {
        return currentSize;
    }
    
    int capacity( ) const
    {
        return array.size( );
    }
    
    bool remove( const AnyType & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].isActive = false;
        return true;
    }

  private:
      
    struct HashEntry
    {
        AnyType element;
        bool isActive;

        HashEntry( const AnyType & e = AnyType( ), bool a = false )
          : element{ e }, isActive{ a } { }    

        HashEntry( AnyType && e, bool a = false )
          : element{ std::move( e ) }, isActive{ a } { }
    };
    
    vector<HashEntry> array;
    int currentSize;
    int numHashFunctions;
    int rehashes;
    UniformRandom r;
    HashFamily hashFunctions;

  //  static const double MAX_LOAD = 0.40;  // Not supported in g++ 4.6
    static const int ALLOWED_REHASHES = 5;
    
    bool insertHelper1( const AnyType & xx )
    {
        const int COUNT_LIMIT = 100;
        AnyType x = xx;
        
        while( true )
        {
            int lastPos = -1;
            int pos;
            
            for( int count = 0; count < COUNT_LIMIT; ++count )
            {
                for( int i = 0; i < numHashFunctions; ++i )
                {
                    pos = myhash( x, i );
                    
                    if( !isActive( pos ) )
                    {
                        array[ pos ] = std::move( HashEntry{ std::move( x ), true } );
                        ++currentSize;
                        return true;
                    }
                }
                
                // None of the spots are available. Kick out random one
                int i = 0;
                do
                {
                    pos = myhash( x, r.nextInt( numHashFunctions ) );
                } while( pos == lastPos && i++ < 5 );
              
                lastPos = pos;
                std::swap( x, array[ pos ].element );
            }
            
            if( ++rehashes > ALLOWED_REHASHES )
            {
                expand( );     // Make the table bigger
                rehashes = 0;
            }
            else
                rehash( );
        }
    }
    
    bool insertHelper1( AnyType && x )
    {
        const int COUNT_LIMIT = 100;
        
        while( true )
        {
            int lastPos = -1;
            int pos;
            
            for( int count = 0; count < COUNT_LIMIT; ++count )
            {
                for( int i = 0; i < numHashFunctions; ++i )
                {
                    pos = myhash( x, i );
                    
                    if( !isActive( pos ) )
                    {
                        array[ pos ] = std::move( HashEntry{ std::move( x ), true } );
                        ++currentSize;
                        return true;
                    }
                }
                
                // None of the spots are available. Kick out random one
                int i = 0;
                do
                {
                    pos = myhash( x, r.nextInt( numHashFunctions ) );
                } while( pos == lastPos && i++ < 5 );
              
                lastPos = pos;
                std::swap( x, array[ pos ].element );
            }
            
            if( ++rehashes > ALLOWED_REHASHES )
            {
                expand( );     // Make the table bigger
                rehashes = 0;
            }
            else
                rehash( );
        }
    }

    bool isActive( int currentPos ) const
      {  return currentPos != -1 &&  array[ currentPos ].isActive; }

    // Method that search all hash function places
    int findPos( const AnyType & x ) const
    {
        for( int i = 0; i < numHashFunctions; ++i )
        {
            int pos = myhash( x, i );
            
            if( isActive( pos ) && array[ pos ].element == x )
                return pos;
        }

        return -1;
    }

    void expand( )
    {
        rehash( static_cast<int>( array.size( ) / MAX_LOAD ) );
    }
    
    void rehash( )
    {
        hashFunctions.generateNewFunctions( );
        rehash( array.size( ) );
    }
    
    void rehash( int newSize )
    {
        vector<HashEntry> oldArray = array;

            // Create new double-sized, empty table
        array.resize( nextPrime( newSize ) );
        for( auto & entry : array )
            entry.isActive = false;
        
            // Copy table over
        currentSize = 0;
        for( auto & entry : oldArray )
            if( entry.isActive )
                insert( std::move( entry.element ) );
    }
    
    
    size_t myhash( const AnyType & x, int which ) const
    {
        return hashFunctions.hash( x, which ) % array.size( );
    }
};


#endif
