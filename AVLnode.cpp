#include "AVLnode.h"

AVLNode::AVLNode() {
    key = 0;
    height = 1;
    leftChild = NULL;
    rightChild = NULL;
}

AVLNode::AVLNode(int key, int height){
    this->key = key;
    this->height = height;
    leftChild = NULL;
    rightChild = NULL;
}