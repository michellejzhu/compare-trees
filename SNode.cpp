#include "SNode.h"

SNode::SNode() {
    key = 0;
    leftChild = NULL;
    rightChild = NULL;
}

SNode::SNode(int key) {
    this->key = key;
    leftChild = NULL;
    rightChild = NULL; 
}
