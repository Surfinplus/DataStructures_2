/**
 * @file Node.cpp
 * @description  
 * @course   2.Öğretim B grubu
 * @assigment 2.Ödev
 * @date 3.12.2023 
 * @author Eren Çoban G221210090 eren.coban1@ogr.sakarya.edu.tr
*/


#include "../include/Node.h"

Node::Node(int value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 0;
}


void Node::setLeft(Node *left) {
    this->left = left;
}

Node* Node::getLeft() {
    return this->left;
}


Node* Node::getRight() {
    return this->right;
}

