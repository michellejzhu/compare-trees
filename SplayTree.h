#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>
#include "SNode.h"
using namespace std;

class SplayTree {
public:
    SplayTree();
    void printS(SNode * root);
    void print();
    SNode * insert(int key);
    SNode * insertS(SNode * node, int key);
    SNode * splay(SNode * node, int key);
    SNode * remove(int key);
    SNode * removeS(SNode * node, int key);
    SNode * singleRightRotate(SNode * node);
    SNode * singleLeftRotate(SNode * node);
    SNode * doubleRightRotate(SNode * node);
    SNode * doubleLeftRotate(SNode * node);
    SNode * insertRoot(int key);
    SNode * root;
    int comparisons;
};

#endif 