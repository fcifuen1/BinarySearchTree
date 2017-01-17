/*
 * File:   BinaryNode.cpp
 * Author: Federico Cifuentes-Urtubey
 *
 * Implementation of the BinaryNode class
 */

#ifndef BINARYNODE_CPP
#define BINARYNODE_CPP

#include "BinaryNode.h"

template <class T>
BinaryNode<T>::BinaryNode() : left(NULL), right(NULL) {}

template <class T>
BinaryNode<T>::BinaryNode(T val) : data(val), left(NULL), right(NULL) {}

template <class T>
BinaryNode<T>::BinaryNode(T val, BinaryNode<T>* l, BinaryNode<T>* r) : 
	data(val), left(l), right(r) {}

template <class T>
BinaryNode<T>::~BinaryNode() 
{
	left = NULL;
    right = NULL;
}

template <class T>
const BinaryNode& BinaryNode<T>::operator= (const BinaryNode<T> &rhs)
{
	if (this != &rhs)
		data = rhs.data;

	return *this;
}

#endif