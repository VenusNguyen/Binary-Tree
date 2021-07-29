//
// Created by Venus Nguyen on 4/25/21.
//

#ifndef TEMPLATEBINARYTREE_BINARYTREE_NODE_CPP
#define TEMPLATEBINARYTREE_BINARYTREE_NODE_CPP

#include "BinaryTree_Node.h"

template<class T>
BinaryTree_Node<T>::BinaryTree_Node()
{}

template<class T>
BinaryTree_Node<T>::BinaryTree_Node(const T& initData, BinaryTree_Node<T>* initLeft, BinaryTree_Node<T>* initRight)
{
    data = initData;
    left = initLeft;
    right = initRight;
}

template<class T>
T& BinaryTree_Node<T>::getData( )
{
    return data;
}

template<class T>
BinaryTree_Node<T>* BinaryTree_Node<T>::getLeft( )
{
    return left;
}

template<class T>
BinaryTree_Node<T>* BinaryTree_Node<T>::getRight( )
{
    return right;
}

template<class T>
void BinaryTree_Node<T>::setData(const T& newData)
{
    data = newData;
}

template<class T>
void BinaryTree_Node<T>::setLeft(BinaryTree_Node<T>* newLeft)
{
    left = newLeft;
}

template<class T>
void BinaryTree_Node<T>::setRight(BinaryTree_Node<T>* newRight)
{
    right = newRight;
}

template<class T>
const T& BinaryTree_Node<T>::getData( ) const
{
    return data;
}

template<class T>
const BinaryTree_Node<T>* BinaryTree_Node<T>::getLeft( ) const
{
    return left;
}

template<class T>
const BinaryTree_Node<T>* BinaryTree_Node<T>::getRight( ) const
{
    return right;
}

template<class T>
bool BinaryTree_Node<T>::isLeaf( ) const
{
    return (left == nullptr) && (right == nullptr);
}

#endif //TEMPLATEBINARYTREE_BINARYTREE_NODE_CPP