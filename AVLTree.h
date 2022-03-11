#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>
#include "AVLnode.h"
using namespace std;

class AVLTree {
public: 
    AVLTree();
    void printAVL(AVLNode * root);
    void print();
    AVLNode * insertAVL(AVLNode * root, int key);
    AVLNode * insert(int key);
    AVLNode * insertRoot(AVLNode * root, int key);
    int height(AVLNode * node);
    int maxVal(int a, int b);
    int getBalance(AVLNode * node);
    AVLNode * singleRightRotate(AVLNode * node);
    AVLNode * singleLeftRotate(AVLNode * node);
    AVLNode * doubleRightRotate(AVLNode * node);
    AVLNode * doubleLeftRotate(AVLNode * node);
    AVLNode * remove(int key);
    AVLNode * removeAVL(AVLNode * node, int key);
    AVLNode * removeMin(AVLNode * node);

    AVLNode * root; 
    int comparisons;
};



#endif
