//
// Created by Venus Nguyen on 4/26/21.
//

#ifndef TEMPLATEBINARYTREE_NODE_H
#define TEMPLATEBINARYTREE_NODE_H

template<class T>
struct Node {
    T data;
    Node *left = nullptr;
    Node *right = nullptr;
};


#endif //TEMPLATEBINARYTREE_NODE_H
