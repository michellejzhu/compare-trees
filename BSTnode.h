#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>
#include <string>
using namespace std;

class BSTNode {
public:
    BSTNode();
    BSTNode(int key);
    void setLeftChild(BSTNode *);
    void setRightChild(BSTNode *);
    
    int key;
    BSTNode * leftChild;
    BSTNode * rightChild;
};

#endif