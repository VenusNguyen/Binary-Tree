//
// Created by Venus Nguyen on 4/25/21.
//

#ifndef TEMPLATEBINARYTREE_BINARYTREE_H
#define TEMPLATEBINARYTREE_BINARYTREE_H

#include "Node.h"
#include <vector>
#include <iostream>

namespace {
    template<class T>
    void output(T& item)
    {
        std::cout << item << " ";
    }

    template<class T>
    bool greater(const T& left, const T& right)
    {
        return left > right;
    }

    template<class T>
    void fillVector(std::vector<T*>& v, T& item)
    {
        v.push_back(&item);
    }
}

template<class T>
class BinaryTree {
public:
    enum Traversal{
        PREORDER,
        INORDER,
        POSTORDER
    };

    BinaryTree();

    void inOrder(void f(T&) = output);
    void preOder(void f(T&) = output);
    void postOrder(void f(T&) = output);

    void inOrder(void f(std::vector<T*>& v, T& item) = fillVector);
    void preOder(void f(std::vector<T*>& v, T& item) = fillVector);
    void postOrder(void f(std::vector<T*>& v, T& item) = fillVector);

    void push(const T& item, bool f(const T& left, const T& right) = greater);

    BinaryTree<T>& operator+=(const T& item);
    void print(Traversal traversal);
    void print();

    void changeTraversal(Traversal traversal);
    Traversal getTraversal() const;

    void clear();

    typedef typename std::vector<T*>::iterator iterator;
    iterator begin();
    iterator end();

private:
    Node<T> *root = nullptr;

    Traversal traversal = INORDER; //default

    std::vector<T*> v;

    Node<T>* createNode(const T& item);
    void push(const T& item, Node<T>* &root, bool f(const T& left, const T& right) = greater);

    void inOrder(void f(T&), Node<T>* &root);
    void preOder(void f(T&), Node<T>* &root);
    void postOrder(void f(T&), Node<T>* &root);

    void inOrder(void f(std::vector<T*>& v, T& item), Node<T>* &root);
    void preOder(void f(std::vector<T*>& v, T& item), Node<T>* &root);
    void postOrder(void f(std::vector<T*>& v, T& item), Node<T>* &root);

    void clear(Node<T>* &root);

    Node<T>* copy(const Node<T>* &root);
};

#include "BinaryTree.cpp"

#endif //TEMPLATEBINARYTREE_BINARYTREE_H
