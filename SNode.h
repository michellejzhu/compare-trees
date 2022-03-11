#ifndef SNODE_H
#define SNODE_H

#include <iostream>
using namespace std;

class SNode {
public: 
    SNode();
    SNode(int key);
    int key;
    SNode * leftChild;
    SNode * rightChild;
};

#endif