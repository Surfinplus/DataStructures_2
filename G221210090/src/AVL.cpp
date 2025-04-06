/**
 * @file AVL.cpp
 * @description Avl Ağaçlarıyla ilgili temel işlemlerin yapıldığı ve yapraklarının stack e eklenmesi gibi işlemlerin yapıldığı yer
 * @course   2.Öğretim B grubu
 * @assigment 2.Ödev
 * @date 3.12.2023 
 * @author Eren Çoban G221210090 eren.coban1@ogr.sakarya.edu.tr
*/


#include "../include/AVL.h"
#include <iostream>
AVL_Tree::AVL_Tree(int index) {
    this->root = nullptr;
    this->stack = new Stack();
    this->index = index;
}

AVL_Tree::~AVL_Tree() {


    deleteNode(root);

    delete stack;

    root = nullptr;
    stack = nullptr;
}

void AVL_Tree::deleteNode(Node* node) {
    if (node != nullptr) {
        deleteNode(node->getLeft());
        deleteNode(node->getRight());
        delete node;
    }
}


void AVL_Tree::insert(int value) {
    this->root = this->insert(this->root, value);
}

void AVL_Tree::remove(int value) {
    this->root = this->remove(this->root, value);
}

void AVL_Tree::print() {
    this->print(this->root);
}

Node *AVL_Tree::insert(Node *node, int value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value < node->value) {
        node->left = this->insert(node->left, value);
        if (this->height(node->left) - this->height(node->right) == 2) {
            if (value < node->left->value) {
                node = this->rotateRight(node);
            } else {
                node = this->doubleRotateRight(node);
            }
        }
    } else if (value > node->value) {
        node->right = this->insert(node->right, value);
        if (this->height(node->right) - this->height(node->left) == 2) {
            if (value > node->right->value) {
                node = this->rotateLeft(node);
            } else {
                node = this->doubleRotateLeft(node);
            }
        }
    }
    node->height = std::max(this->height(node->left), this->height(node->right)) + 1;
    return node;
}

Node *AVL_Tree::remove(Node *node, int value) {
    if (node == nullptr) {
        return nullptr;
    }
    if (value < node->value) {
        node->left = this->remove(node->left, value);
        if (this->height(node->right) - this->height(node->left) == 2) {
            if (this->height(node->right->right) >= this->height(node->right->left)) {
                node = this->rotateLeft(node);
            } else {
                node = this->doubleRotateLeft(node);
            }
        }
    } else if (value > node->value) {
        node->right = this->remove(node->right, value);
        if (this->height(node->left) - this->height(node->right) == 2) {
            if (this->height(node->left->left) >= this->height(node->left->right)) {
                node = this->rotateRight(node);
            } else {
                node = this->doubleRotateRight(node);
            }
        }
    } else if (node->left != nullptr && node->right != nullptr) {
        node->value = this->findMin(node->right)->value;
        node->right = this->remove(node->right, node->value);
        if (this->height(node->left) - this->height(node->right) == 2) {
            if (this->height(node->left->left) >= this->height(node->left->right)) {
                node = this->rotateRight(node);
            } else {
                node = this->doubleRotateRight(node);
            }
        }
    } else {
        Node *temp = node;
        if (node->left == nullptr) {
            node = node->right;
        } else if (node->right == nullptr) {
            node = node->left;
        }
        delete temp;
    }
    if (node != nullptr) {
        node->height = std::max(this->height(node->left), this->height(node->right)) + 1;
    }
    return node;
}

Node *AVL_Tree::findMin(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->left == nullptr) {
        return node;
    }
    return this->findMin(node->left);
}

Node *AVL_Tree::findMax(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right == nullptr) {
        return node;
    }
    return this->findMax(node->right);
}

Node *AVL_Tree::rotateRight(Node *node) {
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = std::max(this->height(node->left), this->height(node->right)) + 1;
    temp->height = std::max(this->height(temp->left), node->height) + 1;
    return temp;
}

Node *AVL_Tree::rotateLeft(Node *node) {
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = std::max(this->height(node->left), this->height(node->right)) + 1;
    temp->height = std::max(this->height(temp->right), node->height) + 1;
    return temp;
}

Node *AVL_Tree::doubleRotateRight(Node *node) {
    node->left = this->rotateLeft(node->left);
    return this->rotateRight(node);
}

Node *AVL_Tree::doubleRotateLeft(Node *node) {
    node->right = this->rotateRight(node->right);
    return this->rotateLeft(node);
}

int AVL_Tree::height(Node *node) {
    return node == nullptr ? -1 : node->height;
}

int AVL_Tree::getBalance(Node *node) {
    return node == nullptr ? 0 : this->height(node->left) - this->height(node->right);
}

void AVL_Tree::print(Node *node) {
    if (node == nullptr) {
        return;
    }
    this->print(node->left);
    std::cout << node->value << " ";
    this->print(node->right);
}

Stack* AVL_Tree::getStack() {
    return this->stack;
}

void AVL_Tree::setStack(Stack* stack) {
    this->stack = stack;
}

void AVL_Tree::addLeafsofAVLTree2Stack(Node *node) {
    if (node != nullptr) {
        
        addLeafsofAVLTree2Stack(node->left);

        
        if (node->left == nullptr && node->right == nullptr) {
            this->stack->push(node->value);
        }

        
        addLeafsofAVLTree2Stack(node->right);
    }
}

Node* AVL_Tree::getRoot() {
    return this->root;
}

bool AVL_Tree::isElementExist(int value) {
    Node *temp = this->root;
    while (temp != nullptr) {
        if (temp->value == value) {
            return true;
        } else if (temp->value > value) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}

int AVL_Tree::sumAllNodes(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->value + sumAllNodes(node->left) + sumAllNodes(node->right);
}

int AVL_Tree::getIndexOfNode() {
    return this->index;
}






