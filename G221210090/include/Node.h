

#ifndef NODE_H
#define NODE_H

class Node {
public:
    int value;
    Node *left;
    Node *right;
    int height;

    Node(int value);


    void setLeft(Node *left);
    Node* getLeft();
    Node* getRight();
};

#endif //AVL_NODE_H
