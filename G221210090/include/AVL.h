
#ifndef AVL_H
#define AVL_H

#include "Node.h"
#include "Stack.h"
class AVL_Tree {
private:
    Node *root;
    Node *insert(Node *node, int value);
    Node *remove(Node *node, int value);
    Node *findMin(Node *node);
    Node *findMax(Node *node);
    Node *rotateRight(Node *node);
    Node *rotateLeft(Node *node);
    Node *doubleRotateRight(Node *node);
    Node *doubleRotateLeft(Node *node);
    int height(Node *node);
    int getBalance(Node *node);
    void print(Node *node);
    Stack *stack;
    int index;

public:
    AVL_Tree(int index);
    ~AVL_Tree();
    void insert(int value);
    void remove(int value);
    void print();
    Stack* getStack();
    void addLeafsofAVLTree2Stack(Node *node);
    Node* getRoot();
    bool isElementExist(int value);
    void setStack(Stack* stack);
    int sumAllNodes(Node* node);
    void deleteNode(Node* node);
    int getIndexOfNode();
};

#endif //AVL_AVL_H
