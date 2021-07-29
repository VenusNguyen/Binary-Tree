//
// Created by Venus Nguyen on 4/25/21.
//
#ifndef TEMPLATEBINARYTREE_BINARYTREE_CPP
#define TEMPLATEBINARYTREE_BINARYTREE_CPP

#include "BinaryTree.h"

template<class T>
BinaryTree<T>::BinaryTree()
{}

template<class T>
void BinaryTree<T>::inOrder(void f(T&))
{
    inOrder(f, root);
}

template<class T>
void BinaryTree<T>::preOder(void f(T&))
{
    preOder(f, root);
}

template<class T>
void BinaryTree<T>::postOrder(void f(T&))
{
    postOrder(f, root);
}

template<class T>
void BinaryTree<T>::inOrder(void f(std::vector<T*> &v, T& item))
{
    if (!v.empty())
        v.clear();
    inOrder(f, root);
}

template<class T>
void BinaryTree<T>::preOder(void f(std::vector<T*> &v, T& item))
{
    if (!v.empty())
        v.clear();
    preOder(f, root);
}

template<class T>
void BinaryTree<T>::postOrder(void f(std::vector<T*> &v, T& item))
{
    if (!v.empty())
        v.clear();
    postOrder(f, root);
}

template<class T>
void BinaryTree<T>::push(const T& item, bool f(const T& left, const T& right))
{
    push(item, root, f);
}

template<class T>
BinaryTree<T>& BinaryTree<T>::operator+=(const T& item)
{
    push(item, root);
    return *this;
}

template<class T>
void BinaryTree<T>::print(Traversal traversal)
{
    switch (traversal)
    {
        case PREORDER:
            preOder(output);
            preOder(fillVector);
            break;
        case POSTORDER:
            postOrder(output);
            postOrder(fillVector);
            break;
        case INORDER:
            inOrder(output);
            inOrder(fillVector);
            break;
    }
}

template<class T>
void BinaryTree<T>::print()
{
    switch (traversal)
    {
        case PREORDER:
            preOder(output);
            preOder(fillVector);
            break;
        case POSTORDER:
            postOrder(output);
            postOrder(fillVector);
            break;
        case INORDER:
            inOrder(output);
            inOrder(fillVector);
            break;
    }
}

template<class T>
void BinaryTree<T>::changeTraversal(BinaryTree::Traversal traversal)
{
    this->traversal = traversal;
}

template<class T>
typename BinaryTree<T>::Traversal BinaryTree<T>::getTraversal() const
{
    return traversal;
}

template<class T>
void BinaryTree<T>::clear()
{
    clear(root);
}

template<class T>
typename BinaryTree<T>::iterator BinaryTree<T>::begin()
{
    return v.begin();
}

template<class T>
typename BinaryTree<T>::iterator BinaryTree<T>::end()
{
    return v.end();
}

///private
template<class T>
Node<T>* BinaryTree<T>::createNode(const T& item)
{
    auto* node = new Node<T>;
    node->data = item;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

template<class T>
void BinaryTree<T>::push(const T& item, Node<T>* &root, bool f(const T& left, const T& right))
{
    if (root == nullptr)
    {
        root = createNode(item);
    }
    else
    {
        if (f(item, root->data))
        {
            push(item, root->right, f);
        } else
        {
            push(item, root->left, f);
        }
    }
}

template<class T>
void BinaryTree<T>::inOrder(void f(T&), Node<T>* &root)
{
//    if (!vector.empty())
//        vector.clear();
    if (root != nullptr)
    {
        inOrder(f, root->left);
        f(root->data);
//        v.push_back(&root->data);
        inOrder(f, root->right);
    }
}

template<class T>
void BinaryTree<T>::preOder(void f(T&), Node<T>* &root)
{
//    if (!vector.empty())
//        vector.clear();
    if (root != nullptr)
    {
        f(root->data);
//        v.push_back(&root->data);
        preOder(f, root->left);
        preOder(f, root->right);
    }
}

template<class T>
void BinaryTree<T>::postOrder(void f(T&), Node<T>* &root)
{
//    if (!vector.empty())
//        vector.clear();
    if (root != nullptr)
    {
        postOrder(f, root->left);
        postOrder(f, root->right);
        f(root->data);
//        v.push_back(&root->data);
    }
}

template<class T>
void BinaryTree<T>::inOrder(void f(std::vector<T*>& v, T& item), Node<T>* &root)
{
    if (root != nullptr)
    {
        inOrder(f, root->left);
        f(v, root->data);
        inOrder(f, root->right);
    }
}

template<class T>
void BinaryTree<T>::preOder(void f(std::vector<T*>& v, T& item), Node<T>* &root)
{
    if (root != nullptr)
    {
        f(v, root->data);
        preOder(f, root->left);
        preOder(f, root->right);
    }
}

template<class T>
void BinaryTree<T>::postOrder(void f(std::vector<T*>& v, T& item), Node<T>* &root)
{
    if (root != nullptr)
    {
        postOrder(f, root->left);
        postOrder(f, root->right);
        f(v, root->data);
    }
}

template<class T>
void BinaryTree<T>::clear(Node<T>* &root)
{
// 1. Clear the left subtree, returning all its nodes to the heap.
// 2. Clear the right subtree, returning all its nodes to the heap.
// 3. Return the root node to the heap.
// 4. Set the root pointer to null.
    Node<T>* temp;
    if (root != nullptr)
    {
        temp = root->left;
        clear(temp);
        temp = root->right;
        clear(temp);
        delete root;
        root = nullptr;
    }
}

template<class T>
Node<T>* BinaryTree<T>::copy(const Node<T>* &root)
{
    Node<T> *leftPtr; //point to copy of the left subtree, which maybe empty
    Node<T> *rightPtr; //point to copy of the right subtree, which maybe empty
    if (root == nullptr)
        return nullptr;
    else
    {
        leftPtr = copy( root->left );
        rightPtr = copy( root->right );
        Node<T>* temp;
        temp->data = root->data;
        temp->left = leftPtr;
        temp->right = rightPtr;
        return temp;
    }
}


#endif //TEMPLATEBINARYTREE_BINARYTREE_CPP