#include "BSTree.h"

BSTree::BSTree() {
    root = NULL;
    comparisons = 0;
}

void BSTree::print(){
    printBST(root);
    cout << endl;
    cout << "BST comparisons: " << comparisons << endl;
}

void BSTree::printBST(BSTNode * root) { //depth first traversal, preorder
    BSTNode * thisNode = root;
    if(thisNode == NULL){
        return;
    }
    cout << "[";
    cout << thisNode->key;
    if(thisNode->leftChild == NULL && thisNode->rightChild != NULL){
        cout << "[ ]";
    }
    else{
        printBST(thisNode->leftChild);
    }
    if(thisNode->rightChild == NULL && thisNode->leftChild != NULL){
        cout << "[ ]";
    }
    else {
        printBST(thisNode->rightChild);
    }
    cout << "]";
}

void BSTree::insert(int key){
    insertBST(root, key);
}

void BSTree::insertBST(BSTNode * node, int key){
    // cout << "insert entered" << endl;
    BSTNode * thisNode = root;
    if(thisNode == NULL){
        comparisons++;
        root = new BSTNode(key);
        // cout << "root added: " << root->key << endl;
    }
    while(thisNode != NULL){
        if(key > thisNode->key){
            comparisons++;
            if(thisNode->rightChild != NULL){
                thisNode = thisNode->rightChild;
            }
            else if(thisNode->rightChild == NULL){
                thisNode->rightChild = new BSTNode(key);
            }
        }
        else if(key < thisNode->key){
            comparisons++;
            if(thisNode->leftChild != NULL){
                thisNode = thisNode->leftChild;
            }
            else if(thisNode->leftChild == NULL){
                thisNode->leftChild = new BSTNode(key);
                cout << key << endl;
            }
        }
        else {
            comparisons++;
            return; 
        }
    }
}

BSTNode * BSTree::removeBST(BSTNode * root, int key){
    if(root == NULL) {
        comparisons++;
        return root;
    }
    else if(key < root->key) {
        comparisons++;
        root->leftChild = removeBST(root->leftChild, key);
    }
    else if(key > root->key) {
        comparisons++;
        root->rightChild = removeBST(root->rightChild, key);
    }
    else {
        //case 0, no children
        comparisons++;
        if(root->leftChild == NULL && root->rightChild == NULL){
            delete root;
            root = NULL;
        }
        //case 1, one child
        else if(root->leftChild == NULL){
            BSTNode * temp = root;
            root = root->rightChild;
            delete temp;
        }
        else if(root->rightChild == NULL){
            BSTNode * temp = root;
            root = root->leftChild;
            delete temp;
        }
        //case 2, 2 chlidren
        else {
            BSTNode * temp = removeMin(root->rightChild);
            root->key = temp->key;
            root->rightChild = removeBST(root->rightChild, temp->key);
        }
    }
    return root;
}

void BSTree::remove(int key){
    removeBST(root, key);
}

BSTNode * BSTree::removeMin(BSTNode * node){
    BSTNode * current = node;
    while(current->leftChild != NULL){
        comparisons++;
        current = current->leftChild;
    }
    return current;
    // while(node->leftChil d != NULL){
    //     node = node->leftChild;
    // }
    // return node;
}
