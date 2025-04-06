/**
 * @file AVLTree_Node.cpp
 * @description Avl.cpp nin düğüm sınıfını saklamak ve işlemek için kullanılan düğüm sınıfı 
 * @course   2.Öğretim B grubu
 * @assigment 2.Ödev
 * @date 3.12.2023 
 * @author Eren Çoban G221210090 eren.coban1@ogr.sakarya.edu.tr
*/



#include "../include/AVLTree_Node.h"

AVLTree_Node::AVLTree_Node(AVL_Tree* value) {
    this->value = value;
    this->next = nullptr;
}

AVLTree_Node::~AVLTree_Node() {
    delete this->value;
    delete this->next;
}

void AVLTree_Node::setNext(AVLTree_Node* next) {
    this->next = next;
}

AVLTree_Node* AVLTree_Node::getNext() {
    return this->next;
}

AVL_Tree* AVLTree_Node::getValue() {
    return this->value;
}

void AVLTree_Node::setVal(AVL_Tree* value) {
    this->value = value;
}