/* 
 * File:   BST.h
 * Author: Federico Cifuentes-Urtubey
 * 
 * Definition of the BST class used for a Binary Search
 * Tree data structure
 */

#ifndef BST_H
#define BST_H

#include "BinaryNode.h" // <iostream>, std::endl
#include "ItemError.h"  // <string>

#include <vector>   // Used in nthElement()

template <class T>
class BST
{
  public:
    
    // Default constructor: sets members to NULL
    BST();

    // Copy constructor: calls cloneTree() to copy a BST
    BST(const BST<T> &rhs);

    // Default destructor: calls empty() to clear the BST
    ~BST();
    
    // Bootstrap function for insertion
    void insert(const T value);

    // Bootstrap function for removal
    void remove(const T value);
  
    // Returns the smallest element in the BST
    T findMin(BinaryNode<T>* t);

    // Returns the largest element in the BST
    T findMax(BinaryNode<T>* t);
    
    // Returns true if the root is NULL, otherwise false
    bool isEmpty() const;

    // Returns true if a certain element is in the BST, otherwise false
    bool contains(T find) const;

    // Bootstrap function to find the nth element of the BST
    T nthElement(int n);
      
    // Prints the BST in sorted order; prints nothing if the BST is empty
    void printTree(BinaryNode<T>* t, ostream &out) const;
    
    // Overloaded operator= : copies contents from a BST
    const BST& operator=(const BST<T> &rhs);

  private:
  
    // Clears the BST by deleting all nodes
    void empty(BinaryNode<T>* t);

    // Inserts a new element into the BST, does nothing if it's a duplicate
    void insert(const T value, BinaryNode<T>* t);

    // Removes an element if found, does nothing if it doesn't exist
    void remove(const T value, BinaryNode<T>* t);

    // Returns the nth element of the tree (from sorted order)
    T nthElement(int n, BinaryNode<T>* t);

    // Helper function for nthElement()
    void inOrderTraversal(vector<T> &v, BinaryNode<T>* t);

    // Returns true if the BST contains element 'find'
    bool contains(const T find, BinaryNode<T>* t) const;

    // Recursively creates a deep copy of a BST 
    BinaryNode<T>* cloneTree(const BinaryNode<T>* t);
  
    BinaryNode<T>* root;   // Pointer to the root of the BST
};

#include "BST.cpp"
#endif