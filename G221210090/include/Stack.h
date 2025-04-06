
#ifndef STACK_H
#define STACK_H

#include "StackNode.h"

class Stack {
private:
    StackNode *top;
public:
    Stack();

    ~Stack();

    void push(int value);

    StackNode *pop();

    StackNode *peek();

    bool isEmpty();

    void clear(StackNode* node);

    void setTop(StackNode* node);

    int totalStackValues();
};

#endif //AVL_STACK_H
