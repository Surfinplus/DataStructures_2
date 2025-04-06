#ifndef AVLTREE_NODE_H
#define AVLTREE_NODE_H

#include "AVL.h"

class AVLTree_Node {
public:
    AVL_Tree* value;
    AVLTree_Node *next;

    AVLTree_Node(AVL_Tree* value);

    ~AVLTree_Node();

    void setNext(AVLTree_Node* next);

    AVLTree_Node* getNext();

    AVL_Tree* getValue();

    void setVal(AVL_Tree* value);


};

#endif //AVL_HW_AVLTREE_NODE_H
