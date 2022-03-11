#include "BSTnode.h"

BSTNode::BSTNode() {
    key = 0;
    leftChild = NULL;
    rightChild = NULL;
}

BSTNode::BSTNode(int key){
    this->key = key;
    leftChild = NULL;
    rightChild = NULL;
}
