/**
 * @file main.cpp
 * @description  işlemlerin gerçekleştrildiği main dosyası stackten avl ağaçları çıkarılarak ağaçlar güncellenir 
 * @course   2.Öğretim B grubu
 * @assigment 2.Ödev
 * @date 3.12.2023 
 * @author Eren Çoban G221210090 eren.coban1@ogr.sakarya.edu.tr
*/





#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/AVL.h"
#include "../include/AVL_Tree_LinkedList.h"
#include "../include/AVLTree_Node.h"
#include <windows.h>
using namespace std;

char convertAscii(int value) {
    char character = static_cast<char>(value);
    return character;
}



int calculate_formula(int number){
    // int ascii = number%(90-65+1) + 65
    int ascii = number%26 + 65;
    return ascii;
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



    string print(AVLTree_Node* root){
    int total = root->getValue()->getStack()->totalStackValues();
    int tree_total = root->getValue()->sumAllNodes(root->getValue()->getRoot());

    int ascii = calculate_formula(tree_total - total);
    char character = convertAscii(ascii);
        string str(1,character);
    return str;
}


void readFile(AVL_Tree_LinkedList *tree_list, string path){
        ifstream file(path);
        string line;

    if (!file.is_open()) {
            cerr << "Error opening file  " << endl;
        return;
    }
    int index = 1;
    while (getline(file, line)) {
        AVL_Tree *tree = new AVL_Tree(index);
            istringstream iss(line);
        int number;

        while (iss >> number) {
            bool check = tree->isElementExist(number);
            if (check == false) {
                tree->insert(number);
            }
        }
        tree_list->insert(new AVLTree_Node(tree));
        index += 1;
    }

    file.close(); 


}

int string_index = 0;

bool delete_element_from_stack(AVL_Tree_LinkedList *list, bool min_flag){
    AVLTree_Node *node = list->getHead();

    if (min_flag) {
        int min_index = 0;
        int min_value = 99999999;
        int index = 0;
        int current_value;
        while(node != nullptr){
            current_value = node->getValue()->getStack()->peek()->value;

            if (current_value < min_value){
                min_value = current_value;
                min_index = index;
            }
            index += 1;
            node = node->next;
        }
        AVL_Tree *min_tree = list->getbyIndex(min_index)->getValue();
        min_tree->getStack()->pop();
        if (min_tree->getStack()->isEmpty()){
            string_index = min_index;
            AVLTree_Node* temp = list->getbyIndex(min_index);
            if (min_index != 0){
                list->getbyIndex(min_index - 1)->setNext(list->getbyIndex(min_index)->getNext());

            }
            else {
                list->setHead(list->getbyIndex(min_index)->getNext());
            }
            delete temp->getValue();
            temp->setNext(nullptr);
            return true;
        }

    }
    else {
        int max_index = 0;
        int max_value = -99999999;
        int index = 0;
        int current_value;
        while(node != nullptr){
            current_value = node->getValue()->getStack()->peek()->value;

            if (current_value > max_value){
                max_value = current_value;
                max_index = index;
            }
            index += 1;
            node = node->next;
        }
        AVL_Tree *min_tree = list->getbyIndex(max_index)->getValue();
        min_tree->getStack()->pop();
        if (min_tree->getStack()->isEmpty()){
            string_index = max_index;
            AVLTree_Node* temp = list->getbyIndex(max_index);
            if (max_index != 0){
                list->getbyIndex(max_index - 1)->setNext(list->getbyIndex(max_index)->getNext());
            }
            else {
                list->setHead(list->getbyIndex(max_index)->getNext());
            }
            delete temp->getValue();
            temp->setNext(nullptr);
            return true;
        }
    }
    return false;
}

int main() {
    AVL_Tree_LinkedList *list = new AVL_Tree_LinkedList();
    readFile(list, "Veri.txt");
    AVLTree_Node *node = list->getHead();
    while(node != nullptr){
        node->getValue()->addLeafsofAVLTree2Stack(node->getValue()->getRoot());
        node = node->next;
    }
        string tree = "";
    bool min_flag = true;
    while(list->getSize() > 1){
        bool response = delete_element_from_stack(list, min_flag);
        if (response) {
            list->setSize(list->getSize()-1);
            AVLTree_Node *node = list->getHead();
            while(node != nullptr){
                delete node->getValue()->getStack();
                node->getValue()->setStack(new Stack());
                node->getValue()->addLeafsofAVLTree2Stack(node->getValue()->getRoot());
                node = node->next;
            }
            min_flag = true;
            tree = "";
            AVLTree_Node* temp = list->getHead();
            while(temp != nullptr){
                tree += print(temp);
                temp = temp->next;
            }
            Sleep(60);
            if (string_index < tree.size()) {
                tree.erase(string_index, 1);
                gotoxy(0, 0);
                    cout << tree <<flush;
                    cout << string(50, ' ');
                gotoxy(0, 0);
            }


        }
        else {
            min_flag = !min_flag;
        }
    }
    int total = list->getHead()->getValue()->getStack()->totalStackValues();

    int tree_total = list->getHead()->getValue()->sumAllNodes(list->getHead()->getValue()->getRoot());
    int ascii = calculate_formula(tree_total - total);
     
     char result = convertAscii(ascii);
     int avl_index = list->getHead()->getValue()->getIndexOfNode();
        
        cout << "Son Karakter: " << result << endl;
        cout << "AVL No: " << avl_index << endl;
    Sleep(5000);
    delete list;

     return 0;
}
