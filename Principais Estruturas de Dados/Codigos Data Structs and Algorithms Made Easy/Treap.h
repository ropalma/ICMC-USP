#ifndef TREAP_H
#define TREAP_H

#include <climits>
#include "UniformRandom.h"
#include "dsexceptions.h"
#include <iostream>


using namespace std;

// Treap class
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class Treap
{
  public:
    Treap( )
    {
        nullNode = new TreapNode;
        nullNode->left = nullNode->right = nullNode;
        nullNode->priority = INT_MAX;
        root = nullNode;
    }

    Treap( const Treap & rhs )
    {
        nullNode = new TreapNode;
        nullNode->left = nullNode->right = nullNode;
        nullNode->priority = INT_MAX;
        root = clone( rhs.root );
    }

    ~Treap( )
    {
        makeEmpty( );
        delete nullNode;
    }
    

    Treap( Treap && rhs ) : root{ rhs.root }, nullNode{ rhs.nullNode }
    {
        rhs.root = nullptr;
        rhs.nullNode = nullptr;
    }

    
    /**
     * Deep copy.
     */
    Treap & operator=( const Treap & rhs )
    {
        Treap copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move.
     */
    Treap & operator=( Treap && rhs )
    {
        std::swap( root, rhs.root );
        std::swap( nullNode, rhs.nullNode );
        
        return *this;
    }

    const Comparable & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };

        TreapNode *ptr = root;
        while( ptr->left != nullNode )
            ptr = ptr->left;

        return ptr->element;
    }

    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };

        TreapNode *ptr = root;
        while( ptr->right != nullNode )
            ptr = ptr->right;

        return ptr->element;
    }

    bool contains( const Comparable & x ) const
    {
        TreapNode *current = root;
        nullNode->element = x;

        for( ; ; )
        {
            if( x < current->element )
                current = current->left;
            else if( current->element < x )
                current = current->right;
            else
                return current != nullNode;
        }
    }

    bool isEmpty( ) const
    {
        return root == nullNode;
    }

    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }

    void makeEmpty( )
    {
        makeEmpty( root );
    }

    void insert( const Comparable & x )
    {
        insert( x, root );
    }

    void insert( Comparable && x )
    {
        insert( std::move( x ), root );
    }

    void remove( const Comparable & x )
    {
        remove( x, root );
    }

  private:
    struct TreapNode
    {
        Comparable element;
        TreapNode *left;
        TreapNode *right;
        int        priority;

        TreapNode( ) : left{ nullptr }, right{ nullptr }, priority{ INT_MAX } { }
        
        TreapNode( const Comparable & e, TreapNode *lt, TreapNode *rt, int pr )
          : element{ e }, left{ lt }, right{ rt }, priority{ pr }
          { }
        
        TreapNode( Comparable && e, TreapNode *lt, TreapNode *rt, int pr )
          : element{ std::move( e ) }, left{ lt }, right{ rt }, priority{ pr }
          { }
    };

    TreapNode *root;
    TreapNode *nullNode;
    UniformRandom randomNums;

        // Recursive routines
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the tree.
     * Set the new root of the subtree.
     * (randomNums is a UniformRandom object that is a data member of Treap.)
     */
    void insert( const Comparable & x, TreapNode* & t )
    {
        if( t == nullNode )
            t = new TreapNode{ x, nullNode, nullNode, randomNums.nextInt( ) };
        else if( x < t->element )
        {
            insert( x, t->left );
            if( t->left->priority < t->priority )
                rotateWithLeftChild( t );
        }
        else if( t->element < x )
        {
            insert( x, t->right );
            if( t->right->priority < t->priority )
                rotateWithRightChild( t );
        }
        // else duplicate; do nothing
    }
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the tree.
     * Set the new root of the subtree.
     * (randomNums is a UniformRandom object that is a data member of Treap.)
     */
    void insert( Comparable && x, TreapNode* & t )
    {
        if( t == nullNode )
            t = new TreapNode{ std::move( x ), nullNode, nullNode, randomNums.nextInt( ) };
        else if( x < t->element )
        {
            insert( std::move( x ), t->left );
            if( t->left->priority < t->priority )
                rotateWithLeftChild( t );
        }
        else if( t->element < x )
        {
            insert( std::move( x ), t->right );
            if( t->right->priority < t->priority )
                rotateWithRightChild( t );
        }
        // else duplicate; do nothing
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the tree.
     * Set the new root of the subtree.
     */
    void remove( const Comparable & x, TreapNode * & t )
    {
        if( t != nullNode )
        {
            if( x < t->element )
                remove( x, t->left );
            else if( t->element < x )
                remove( x, t->right );
            else
            {
                    // Match found
                if( t->left->priority < t->right->priority )
                    rotateWithLeftChild( t );
                else
                    rotateWithRightChild( t );

                if( t != nullNode )      // Continue on down
                    remove( x, t );
                else
                {
                    delete t->left;
                    t->left = nullNode;  // At a leaf
                }
            }
        }
    }

    void makeEmpty( TreapNode * & t )
    {
        if( t != nullNode )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullNode;
    }

    void printTree( TreapNode *t ) const
    {
        if( t != nullNode )
        {
            printTree( t->left );
            cout << t->element << endl;
            printTree( t->right );
        }
    }

        // Rotations
    void rotateWithLeftChild( TreapNode * & k2 )
    {
        TreapNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }

    void rotateWithRightChild( TreapNode * & k1 )
    {
        TreapNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }

    TreapNode * clone( TreapNode * t ) const
    {
        if( t == t->left )  // Cannot test against nullNode!!!
            return nullNode;
        else
            return new TreapNode{ t->element, clone( t->left ), clone( t->right ), t->priority };
    }
};

#endif
