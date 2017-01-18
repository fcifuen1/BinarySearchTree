/* 
 * File:   BinaryNode.h
 * Author: Federico Cifuentes-Urtubey
 * 
 * Definition of the BinaryNode class used for a Binary Search
 * Tree data structure
 */

#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <iostream>
using std::endl;

template <class T>
class BinaryNode
{
  public:
  
    // Default Constructor: sets left and right members to NULL
    BinaryNode();

    // Nondefault Constructor: sets data to val and left/right to NULL
    BinaryNode(T val);

    // Nondefault Constructor: creates a tree from an existing (sub)tree
    BinaryNode(T val, BinaryNode<T>* l, BinaryNode<T>* r);

    // Destructor: sets the left and right pointers to NULL
    ~BinaryNode();

    // Overloaded operator= : copies data from a BinaryNode
    const BinaryNode& operator=(const BinaryNode<T> &rhs);
  
    T data;		// Contained data
    BinaryNode* left;	// Pointer to the left subtree
    BinaryNode* right;	// Pointer to the right subtree
};

#include "BinaryNode.cpp"
#endif
