/*
 * File:   BST.cpp
 * Author: Federico Cifuentes-Urtubey
 *
 * Implementation of the BST class
 */

#ifndef BST_CPP
#define BST_CPP

#include "BST.h"

/*** public functions begin here ***/

template <class T>
BST<T>::BST() : root(NULL) {}

template <class T>
BST<T>::BST(const BST<T> &rhs) { *this = rhs; }

template <class T>
BST<T>::~BST() { empty(root); }

template <class T>
void BST<T>::insert(const T value) { insert(value, root); }  

template <class T>
void BST<T>::remove(const T value) { remove(value, root); }
 
template <class T>
T BST<T>::findMin(BinaryNode<T>* t)
{
  if (t->left == NULL)
	 return t->data;

  return findMin(t->left);
}

template <class T>
T BST<T>::findMax(BinaryNode<T>* t)
{
  if (t->right == NULL)
	 return t->data;
   
  return findMax(t->right);
}

template <class T>
bool BST<T>::isEmpty() const { return root == NULL; }

template <class T>
T BST<T>::nthElement(int n) { return nthElement(n, root); }

template <class T>
void BST<T>::printTree(BinaryNode<T>* t, ostream &out) const
{
  if (t != NULL)
  {
    printTree(t->left, out);
    out << t->data << endl;
    printTree(t->right, out);
  }
}

template <class T>
const BST& BST<T>::operator= (const BST<T> &rhs)
{
  if (this != &rhs)
  {
    empty(root);
    root = cloneTree(rhs.root);
  }
  
  return *this;
}


/*** private functions begin here ***/

template <class T>
void BST<T>::empty(BinaryNode<T>* t)
{ 
  if (t != NULL)
  {
    empty(t->left);
    empty(t->right);
    delete t;
  }
      
  t = NULL;
}
  
template <class T>
void BST<T>::insert(const T value, BinaryNode<T>* t)
{
  // Add to empty node
  if (t == NULL)
    t = new BinaryNode(value);
    
  // Add to node on the left
  else if (value < t -> data)
    insert(value, t -> left);
    
  // Add to node on the right
  else if (value > t -> data)
    insert(value, t -> right);
    
  // Duplicate, do nothing
  else return;
}

template <class T>
void BST<T>::remove(const T value, BinaryNode<T>* t)
{
  // Empty tree OR nonexistent value case
  if (t == NULL) return;

  // Current node is too large, go left
  else if (value < t->data)
    remove(value, t->left);

  // Current node is too small, go right
  else if (value > t->data)
    remove(value, t->right);

  // Match w/ 2 children nodes
  else if ( (t->left != NULL) && (t->right != NULL) )
  {
    t->data = (findMin(t->right))->data;
    remove(t->data, t->right);
  }

  // Match w/ 1 or no children nodes
  else
  {
    BinaryNode<T>* oldNode = t;
    t = ((t->left != NULL) ? t->left : t->right);
    delete oldNode;
    oldNode = NULL;
  }
}

template <class T>
T BST<T>::nthElement(int n, BinaryNode<T>* t)
{
  if (t == NULL)
    throw ItemError("nthElement() - Item Not Found!\n");
  if (n < 0)
    throw ItemError("nthElement() - n is negative.\n");

  // Saves the tree's items (in order) into a vector
  vector<T> elements; 
  inOrderTraversal(elements, root);

  if (elements.size() < n)
    throw ItemError("nthElement() - n is too large.\n");
  else
    return elements[n - 1];
}

template <class T>
void BST<T>::inOrderTraversal(vector<T> &v, BinaryNode<T>* t)
{
  if (t != NULL)
  {
    inOrderTraversal(v, t->left);
    v.push_back(t->data);
    inOrderTraversal(v, t->right);
  }
}

template <class T>
bool BST<T>::contains(const T find, BinaryNode<T>* t) const
{
  if (t == NULL)
    return false;
      
  // Current node is bigger than what we want to find
  else if (find < t->data)
    return contains(find, t->left);
      
  // Current node is smaller than what we want to find
  else if (t->data < find)
    return contains(find, t->right);
      
  // Match
  else
    return true;
}

template <class T>
BinaryNode<T>* BST<T>::cloneTree(const BinaryNode<T>* t)
{
  if (t == NULL) return NULL;
  else return new BinaryNode<T>(t->data, cloneTree(t->left), cloneTree(t->right));
}

#endif