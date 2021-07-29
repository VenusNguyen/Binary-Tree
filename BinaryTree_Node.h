//
// Created by Venus Nguyen on 4/25/21.
//

#ifndef TEMPLATEBINARYTREE_BINARYTREE_NODE_H
#define TEMPLATEBINARYTREE_BINARYTREE_NODE_H

template<class T>
class BinaryTree_Node {
public:
    // CONSTRUCTOR
    BinaryTree_Node();
    BinaryTree_Node(const T& initData, BinaryTree_Node<T>* initLeft, BinaryTree_Node<T>* initRight);
    // MODIFICATION MEMBER FUNCTIONS
    T& getData();
    BinaryTree_Node<T>* getLeft();
    BinaryTree_Node<T>* getRight();
    void setData(const T& newData);
    void setLeft(BinaryTree_Node<T>* newLeft);
    void setRight(BinaryTree_Node<T>* newRight);
    // CONST MEMBER FUNCTIONS
    const T& getData() const;
    const BinaryTree_Node<T>* getLeft() const;
    const BinaryTree_Node<T>* getRight() const;
    bool isLeaf( ) const;

private:
    T data;
    BinaryTree_Node<T> *left = nullptr;
    BinaryTree_Node<T> *right = nullptr;

};

#include "BinaryTree_Node.cpp"

#endif //TEMPLATEBINARYTREE_BINARYTREE_NODE_H
