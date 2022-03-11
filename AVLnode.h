#ifndef AVLNODE_H
#define AVLNODE_H

#include <iostream>
#include <string>
using namespace std;

class AVLNode {
public:
    AVLNode();
    AVLNode(int key, int height);
    int key;
    int height;
    AVLNode * leftChild;
    AVLNode * rightChild;
};

#endif