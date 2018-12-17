#ifndef PAIRING_HEAP_H
#define PAIRING_HEAP_H
#include "dsexceptions.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Pairing heap class
//
// CONSTRUCTION: with no parameters
//
// ******************PUBLIC OPERATIONS*********************
// PairNode & insert( x ) --> Insert x
// deleteMin( minItem )   --> Remove (and optionally return) smallest item
// Comparable findMin( )  --> Return smallest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void decreaseKey( Position p, newVal )
//                        --> Decrease value in Position p
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class PairingHeap
{
  private:     
    struct PairNode;
    
  public:
    PairingHeap( )
    {
        root = nullptr;
    }

    ~PairingHeap( )
    {
        makeEmpty( );
    }

    
    PairingHeap( const PairingHeap & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    PairingHeap( PairingHeap && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    

    /**
     * Deep copy.
     */
    PairingHeap & operator=( const PairingHeap & rhs )
    {
        PairingHeap copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move.
     */
    PairingHeap & operator=( PairingHeap && rhs )
    {
        std::swap( root, rhs.root );
        
        return *this;
    }
    
    
    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return root->element;
    }

    typedef PairNode * Position;

    /**
     * Insert item x into the priority queue, maintaining heap order.
     * Return the Position  (a pointer to the node) containing the new item.
     */
    Position insert( const Comparable & x )
    {
        PairNode *newNode = new PairNode{ x };

        if( root == nullptr )
            root = newNode;
        else
            compareAndLink( root, newNode );
        return newNode;
    }

    /**
     * Insert item x into the priority queue, maintaining heap order.
     * Return the Position  (a pointer to the node) containing the new item.
     */
    Position insert( Comparable && x )
    {
        PairNode *newNode = new PairNode{ std::move( x ) };

        if( root == nullptr )
            root = newNode;
        else
            compareAndLink( root, newNode );
        return newNode;
    }

    /**
     * Remove the smallest item from the priority queue
     * or throw UnderflowException if empty.
     */
    void deleteMin( )
    {
        if( isEmpty( ) )
            throw UnderflowException{ };

        PairNode *oldRoot = root;

        if( root->leftChild == nullptr )
            root = nullptr;
        else
            root = combineSiblings( root->leftChild );

        delete oldRoot;
    }

    /**
     * Remove the smallest item from the priority queue.
     * Pass back the smallest item via minItem, or throw UnderflowException if empty.
     */
    void deleteMin( Comparable & minItem )
    {
        minItem = findMin( );
        deleteMin( );
    }

    void makeEmpty( )
    {
        reclaimMemory( root );
        root = nullptr;
    }

    /**
     * Change the value of the item stored in the pairing heap.
     * Throw invalid_argument if newVal is larger than
     *    currently stored value.
     * p is a Position returned by insert.
     * newVal is the new value, which must be smaller
     *    than the currently stored value.
     */
    void decreaseKey( Position p, const Comparable & newVal )
    {
        if( p->element < newVal )
            throw invalid_argument( "newVal too large" );
        
        p->element = newVal;
        if( p != root )
        {
            if( p->nextSibling != nullptr )
                p->nextSibling->prev = p->prev;
            if( p->prev->leftChild == p )
                p->prev->leftChild = p->nextSibling;
            else
                p->prev->nextSibling = p->nextSibling;

            p->nextSibling = nullptr;
            compareAndLink( root, p );
        }
    }

    /**
     * Change the value of the item stored in the pairing heap.
     * Throw invalid_argument if newVal is larger than
     *    currently stored value.
     * p is a Position returned by insert.
     * newVal is the new value, which must be smaller
     *    than the currently stored value.
     */
    void decreaseKey( Position p, Comparable && newVal )
    {
        if( p->element < newVal )
            throw invalid_argument( "newVal too large" );

        p->element = std::move( newVal );
        if( p != root )
        {
            if( p->nextSibling != nullptr )
                p->nextSibling->prev = p->prev;
            if( p->prev->leftChild == p )
                p->prev->leftChild = p->nextSibling;
            else
                p->prev->nextSibling = p->nextSibling;

            p->nextSibling = nullptr;
            compareAndLink( root, p );
        }
    }

  private:
    struct PairNode
    {
        Comparable   element;
        PairNode    *leftChild;
        PairNode    *nextSibling;
        PairNode    *prev;

        PairNode( const Comparable & theElement ) : element{ theElement },
            leftChild{ nullptr }, nextSibling{ nullptr }, prev{ nullptr } { }
        
        PairNode( Comparable && theElement ) : element( std::move( theElement ) ),
            leftChild{ nullptr }, nextSibling{ nullptr }, prev{ nullptr } { }
    };

    PairNode *root;

    /**
     * Internal method to make the tree empty.
     * WARNING: This is prone to running out of stack space.
     */
    void reclaimMemory( PairNode *t )
    {
        if( t != nullptr )
        {
            reclaimMemory( t->leftChild );
            reclaimMemory( t->nextSibling );
            delete t;
        }
    }

    /**
     * Internal method that is the basic operation to maintain order.
     * Links first and second together to satisfy heap order.
     * first is root of tree 1, which may not be nullptr.
     *    first->nextSibling MUST be nullptr on entry.
     * second is root of tree 2, which may be nullptr.
     * first becomes the result of the tree merge.
     */
    void compareAndLink( PairNode * & first, PairNode *second )
    {
        if( second == nullptr )
            return;

        if( second->element < first->element )
        {
            // Attach first as leftmost child of second
            second->prev = first->prev;
            first->prev = second;
            first->nextSibling = second->leftChild;
            if( first->nextSibling != nullptr )
                first->nextSibling->prev = first;
            second->leftChild = first;
            first = second;
        }
        else
        {
            // Attach second as leftmost child of first
            second->prev = first;
            first->nextSibling = second->nextSibling;
            if( first->nextSibling != nullptr )
                first->nextSibling->prev = first;
            second->nextSibling = first->leftChild;
            if( second->nextSibling != nullptr )
                second->nextSibling->prev = second;
            first->leftChild = second;
        }
    }

    /**
     * Internal method that implements two-pass merging.
     * firstSibling the root of the conglomerate and is assumed not nullptr.
     */
    PairNode * combineSiblings( PairNode *firstSibling )
    {
        if( firstSibling->nextSibling == nullptr )
            return firstSibling;

            // Allocate the array
        static vector<PairNode *> treeArray( 5 );

            // Store the subtrees in an array
        int numSiblings = 0;
        for( ; firstSibling != nullptr; ++numSiblings )
        {
            if( numSiblings == treeArray.size( ) )
                treeArray.resize( numSiblings * 2 );
            treeArray[ numSiblings ] = firstSibling;
            firstSibling->prev->nextSibling = nullptr;  // break links
            firstSibling = firstSibling->nextSibling;
        }
        if( numSiblings == treeArray.size( ) )
            treeArray.resize( numSiblings + 1 );
        treeArray[ numSiblings ] = nullptr;

            // Combine subtrees two at a time, going left to right
        int i = 0;
        for( ; i + 1 < numSiblings; i += 2 )
            compareAndLink( treeArray[ i ], treeArray[ i + 1 ] );

        int j = i - 2;

            // j has the result of last compareAndLink.
            // If an odd number of trees, get the last one.
        if( j == numSiblings - 3 )
            compareAndLink( treeArray[ j ], treeArray[ j + 2 ] );

            // Now go right to left, merging last tree with
            // next to last. The result becomes the new last.
        for( ; j >= 2; j -= 2 )
            compareAndLink( treeArray[ j - 2 ], treeArray[ j ] );
        return treeArray[ 0 ];
    }

    /**
     * Internal method to clone subtree.
     * WARNING: This is prone to running out of stack space.
     */
    PairNode * clone( PairNode *t )
    {
        if( t == nullptr ) 
            return nullptr;
        else
        {
            PairNode *p = new PairNode{ t->element };
            if( ( p->leftChild = clone( t->leftChild ) ) != nullptr )
                p->leftChild->prev = p;
            if( ( p->nextSibling = clone( t->nextSibling ) ) != nullptr )
                p->nextSibling->prev = p;
            return p;
        }
    }
};

#endif
