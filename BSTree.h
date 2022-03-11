#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include "BSTnode.h"
using namespace std;

class BSTree {
public:
    BSTree();
    void insert(int key);
    void insertBST(BSTNode *root, int key);
    BSTNode * removeMin(BSTNode * node);
    void remove(int key);
    BSTNode * removeBST(BSTNode * root, int key);
    void print();
    void printBST(BSTNode * root);

    BSTNode * root;
    int comparisons;
};

#endif

