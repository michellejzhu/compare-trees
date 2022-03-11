#include "AVLnode.h"
#include "AVLTree.h"

AVLTree::AVLTree() {
    root = NULL;
    comparisons = 0;
}

void AVLTree::print(){
    printAVL(root);
    cout << endl;
    cout << "AVL comparisons: " << comparisons << endl;
}

void AVLTree::printAVL(AVLNode * root){
    AVLNode * thisNode = root;
    if(thisNode == NULL){
        return;
    }
    cout << "[";
    cout << thisNode->key;
    if(thisNode->leftChild == NULL && thisNode->rightChild != NULL){
        cout << "[ ]";
    }
    else{
        printAVL(thisNode->leftChild);
    }
    if(thisNode->rightChild == NULL && thisNode->leftChild != NULL){
        cout << "[ ]";
    }
    else {
        printAVL(thisNode->rightChild);
    }
    cout << "]";
}


int AVLTree::height(AVLNode * node){
    if(node == NULL) {
        return -1;
    }
    return (maxVal(height(node->leftChild), height(node->rightChild)) + 1);
}

int AVLTree::getBalance(AVLNode * node){
    if(node == NULL) {
        comparisons++;
        return 0;
    }
    return (height(node->leftChild) - height(node->rightChild)); /*node->height;*/
}

int AVLTree::maxVal(int a, int b) {
    if(a > b) return a;
    else return b;
}

AVLNode * AVLTree::insert(int key){
    // cout << "inserting: " << key << endl;
    if(root == NULL){
        comparisons++;
        root = insertRoot(root, key);
    }
    else {
        comparisons++;
        root = insertAVL(root, key);
    }
    // cout << "after insertion" << endl;
    return root;
}

AVLNode * AVLTree::insertRoot(AVLNode * root, int key) {
    // cout << "insertRoot entered" << endl;
    root = new AVLNode(key, 0);
    return root;
}

AVLNode * AVLTree::insertAVL(AVLNode * node, int key){
    // cout << "insertAVL entered" << endl;
    if(node == NULL){
        comparisons++;
        return new AVLNode(key, 0);
    }
    else if(key < node->key) {
        comparisons++;
        node->leftChild = insertAVL(node->leftChild, key);
    }
    else if(key > node->key) {
        comparisons++;
        node->rightChild = insertAVL(node->rightChild, key);
    }
    else {
        return node;
    }

    node->height = 1 + maxVal(height(node->leftChild), height(node->rightChild));


    int balance = getBalance(node); 

    if(balance > 1 && key < node->leftChild->key){
        return singleRightRotate(node);
    }
    if(balance < -1 && key > node->rightChild->key){
        return singleLeftRotate(node);
    }
    //left right
    if(balance > 1 && key > node->leftChild->key) {
        return doubleRightRotate(node);
    }
    //right left
    if(balance < -1 && key < node->rightChild->key) {
        return doubleLeftRotate(node);
    }

    return node;
}

AVLNode * AVLTree::singleRightRotate(AVLNode * node){ //right rotate
    AVLNode * t1 = node->leftChild;
    AVLNode * t2 = t1->rightChild;

    t1->rightChild = node;
    node->leftChild = t2;

    node->height = maxVal(height(node->leftChild), height(node->rightChild)) + 1;
    t1->height = maxVal(height(t1->leftChild), height(t1->rightChild)) + 1;

    return t1;
}

AVLNode * AVLTree::singleLeftRotate(AVLNode * node){ //left rotate
    AVLNode * t1 = node->rightChild;
    AVLNode * t2 = t1->leftChild;

    t1->leftChild = node;
    node->rightChild = t2;

    node->height = maxVal(height(node->leftChild), height(node->rightChild)) + 1;
    t1->height = maxVal(height(t1->leftChild), height(t1->rightChild)) + 1;

    return t1;
}

//left right
AVLNode * AVLTree::doubleRightRotate(AVLNode * node){
    node->leftChild = singleLeftRotate(node->leftChild);
    return singleRightRotate(node);
}

//right left
AVLNode * AVLTree::doubleLeftRotate(AVLNode * node){ //
    node->rightChild = singleRightRotate(node->rightChild);
    return singleLeftRotate(node);
}

// REMOVE 

AVLNode * AVLTree::removeMin(AVLNode * node){
    AVLNode * current = node;
    while(current->leftChild != NULL){
        comparisons++;
        current = current->leftChild;
    }
    return current;
}


AVLNode * AVLTree::remove(int key){
    root = removeAVL(root, key);
    return root;
}

AVLNode * AVLTree::removeAVL(AVLNode * node, int key) {
    if(node == NULL){
        comparisons++;
        return node;
    }
    else if(key < node->key) {
        comparisons++;
        node->leftChild = removeAVL(node->leftChild, key);
    }
    else if(key > node->key) {
        comparisons++;
        node->rightChild = removeAVL(node->rightChild, key);
    }
    else { 
        comparisons++;
        if(node->leftChild == NULL || node->rightChild == NULL){
            AVLNode * temp = NULL;
            if(node->leftChild != NULL){
                temp = node->leftChild;
            }
            else if(node->rightChild != NULL){
                temp = node->rightChild;
            }       
            //if no children
            if(temp == NULL){
                temp = node;
                node = NULL;
            }
            else { //1 child
                *node = *temp;
            }
            delete temp;
        }
        else { //2 children
            AVLNode * temp = removeMin(node->rightChild);
            node->key = temp->key;
            node->rightChild = removeAVL(node->rightChild, temp->key);
        }
    }

    if(node == NULL){
        return node;
    }

    node->height = 1 + maxVal(height(node->leftChild), height(node->rightChild));

    int balance = getBalance(node); 

    if(balance > 1 && getBalance(node->leftChild) >= 0){
        return singleRightRotate(node);
    }
    if(balance < -1 && getBalance(node->rightChild) >= 0){
        return singleLeftRotate(node);
    }
    if(balance > 1 && getBalance(root->leftChild) < 0) {
        return doubleRightRotate(node);
    }
    if(balance < -1 && getBalance(root->rightChild) < 0) {
        return doubleLeftRotate(node);
    }

    return node;
}



