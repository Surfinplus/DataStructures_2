#ifndef AVL_TREE_LINKEDLIST_H
#define AVL_TREE_LINKEDLIST_H

#include "AVLTree_Node.h"

class AVL_Tree_LinkedList {
private:
    AVLTree_Node *head;
    AVLTree_Node *tail;
    int size;
public:

    AVL_Tree_LinkedList();
    void insert(AVLTree_Node* value);
    void remove(AVLTree_Node* value);
    void print();
    AVLTree_Node* find(AVL_Tree* value);
    ~AVL_Tree_LinkedList();
    int getSize();
    AVLTree_Node* getHead();
    AVLTree_Node* getTail();
    AVLTree_Node* getbyIndex(int index);
    void setHead(AVLTree_Node* value);
    void setSize(int value);

};

#endif 
