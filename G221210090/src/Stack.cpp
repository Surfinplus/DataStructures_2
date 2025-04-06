/**
 * @file Stack.cpp
 * @description  Stack veri Yapısının sağlandığı kaynak kod
 * @course   2.Öğretim B grubu
 * @assigment 2.Ödev
 * @date 3.12.2023 
 * @author Eren Çoban G221210090 eren.coban1@ogr.sakarya.edu.tr
*/


#include "../include/Stack.h"
#include "../include/StackNode.h"

Stack::Stack() {
    this->top = nullptr;
}

bool Stack::isEmpty() {
    return this->top == nullptr;
}

void Stack::push(int value) {
    StackNode *temp = new StackNode(value);
    temp->next = this->top;
    this->top = temp;
}

StackNode *Stack::pop() {
    if (this->isEmpty()) {
        throw "Stack is empty";
    }
    StackNode *temp = this->top;
    this->top = this->top->next;
    temp->next = nullptr;
    return temp;
}

StackNode *Stack::peek() {
    if (this->isEmpty()) {
        throw "Stack is empty";
    }
    return this->top;
}

Stack::~Stack() {
    while (top != nullptr) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::setTop(StackNode* node) {
    this->top = node;
}

int Stack::totalStackValues() {
    int total = 0;
    StackNode* temp = this->top;
    while (temp != nullptr) {
        total += temp->value;
        temp = temp->next;
    }
    return total;
}

