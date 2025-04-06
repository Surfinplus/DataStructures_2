/**
 * @file AVL_Tree_LinkedList.cpp
 * @description Avl Ağaç Düğümlerinin listede tutulduğu ve onlarla ilgili işlemlerin bulunduğu yer 
 * @course   2.Öğretim B grubu
 * @assigment 2.Ödev
 * @date 3.12.2023 
 * @author Eren Çoban G221210090 eren.coban1@ogr.sakarya.edu.tr
*/



#include "../include/AVL_Tree_LinkedList.h"

AVL_Tree_LinkedList::AVL_Tree_LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

void AVL_Tree_LinkedList::insert(AVLTree_Node* value) {
    if (this->head == nullptr) {
        this->head = value;
        this->tail = value;
    } else {
        this->tail->setNext(value);
        this->tail = value;
    }
    this->size++;
}

void AVL_Tree_LinkedList::remove(AVLTree_Node* value) {
    if (this->head == nullptr) {
        return;
    } else if (this->head == this->tail) {
        this->head = nullptr;
        this->tail = nullptr;
    } else if (this->head == value) {
        this->head = this->head->getNext();
    } else {
        AVLTree_Node* current = this->head;
        while (current->getNext() != value) {
            current = current->getNext();
        }
        current->setNext(value->getNext());
    }
    this->size--;
}


AVL_Tree_LinkedList::~AVL_Tree_LinkedList() {
    AVLTree_Node *current = head;
    while (current != nullptr) {
        AVLTree_Node *next = current->getNext();
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

int AVL_Tree_LinkedList::getSize() {
    return this->size;
}

AVLTree_Node* AVL_Tree_LinkedList::getHead() {
    return this->head;
}

AVLTree_Node* AVL_Tree_LinkedList::getTail() {
    return this->tail;
}

AVLTree_Node* AVL_Tree_LinkedList::getbyIndex(int index) {
    if (index >= this->size) {
        return nullptr;
    }
    AVLTree_Node* current = this->head;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    return current;
}
void AVL_Tree_LinkedList::setHead(AVLTree_Node* value) {
    this->head = value;
}

void AVL_Tree_LinkedList::setSize(int value) {
    this->size = value;
}

