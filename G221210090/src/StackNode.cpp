/**
 * @file Stack.cpp
 * @description  Stack Node yapısını sağlamak için yapılan kod 
 * @course   2.Öğretim B grubu
 * @assigment 2.Ödev
 * @date 3.12.2023 
 * @author Eren Çoban G221210090 eren.coban1@ogr.sakarya.edu.tr
*/



#include "../include/StackNode.h"

StackNode::StackNode(int value) {
    this->value = value;
    this->next = nullptr;
}

