
#ifndef AVL_HW_LINKEDLIST_H
#define AVL_HW_LINKEDLIST_H

#include "AVL.h"

class LinkedList {
    private:
        Node *head;
        Node *tail;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        void insert(int value);
        void remove(int value);
        void print();
        int getSize();
        Node* getHead();
        Node* getTail();
};

#endif //AVL_HW_LINKEDLIST_H
