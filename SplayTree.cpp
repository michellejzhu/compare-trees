#include "SplayTree.h"

SplayTree::SplayTree(){
    root = NULL;
    comparisons = 0;
}


void SplayTree::print(){
    printS(root);
    cout << endl;
    cout << "Splay comparisons: " << comparisons << "\n\n";
}

void SplayTree::printS(SNode * root){
    SNode * thisNode = root;
    if(thisNode == NULL){
        return;
    }
    cout << "[";
    cout << thisNode->key;
    if(thisNode->leftChild == NULL && thisNode->rightChild != NULL){
        cout << "[ ]";
    }
    else{
        printS(thisNode->leftChild);
    }
    if(thisNode->rightChild == NULL && thisNode->leftChild != NULL){
        cout << "[ ]";
    }
    else {
        printS(thisNode->rightChild);
    }
    cout << "]";
}

SNode * SplayTree::singleRightRotate(SNode * node){
    SNode * t1 = node->leftChild;
    SNode * t2 = t1->rightChild;
    t1->rightChild = node;
    node->leftChild = t2;
    return t1;
}

SNode * SplayTree::singleLeftRotate(SNode * node){
    SNode * t1 = node->rightChild;
    SNode * t2 = t1->leftChild;
    t1->leftChild = node;
    node->rightChild = t2;
    return t1;
}

SNode * SplayTree::splay(SNode * node, int key){
    // base case root is NULL or key is present at root
    //cout << "entering splay" << endl;
    if(node == NULL || node->key == key){
        comparisons++;
        return node;
    }

    // case 1: key in left tree
    //zig zig (right right)
    if(node->key > key){
        comparisons++;
        //cout << "entering left subtree" << endl;
        if(node->leftChild == NULL){
            return node;
        }
        if(node->leftChild->key > key){
            node->leftChild->leftChild = splay(node->leftChild->leftChild, key);
            node = singleRightRotate(node);
        }
        else if(node->leftChild->key < key){
            node->leftChild->rightChild = splay(node->leftChild->rightChild, key); 
            if (node->leftChild->rightChild != NULL){
                node->leftChild = singleLeftRotate(node->leftChild); 
            }
        }
        return (node->leftChild == NULL) ? node : singleRightRotate(node);     
    }
    else { //case 2: key is in right tree
        //cout << "entering right subtree" << endl;
        comparisons++;
        if(node->rightChild == NULL){
            return node;
        }
        // zig zag (right left)
        if (node->rightChild->key > key){
            node->rightChild->leftChild = splay(node->rightChild->leftChild, key);
            if(node->rightChild->leftChild != NULL){
                node->rightChild = singleRightRotate(node->rightChild);
            }
        }
        // zig zig (left left)
        else if(node->rightChild->key < key){
            node->rightChild->rightChild = splay(node->rightChild->rightChild, key);
            node = singleLeftRotate(node);
        }
        return (node->rightChild == NULL) ? node : singleLeftRotate(node);
    }    
    //return node;
}

SNode * SplayTree::insertRoot(int key){
    root = new SNode(key);
    //cout << "insertRoot: root added " << key << endl;
    return root;
}

// insert normally like bst tree
// splay operation is performed
// as a result, node inserted becomes new root of tree
SNode * SplayTree::insert(int key){
    //cout << "inserting: " << key << endl;
    if(root == NULL){
        comparisons++;
        root = insertRoot(key);
    }
    else {
        comparisons++;
        root = insertS(root, key);
    }
    // cout << "after insertion" << endl;
    return root;
}

SNode * SplayTree::insertS(SNode * node, int key){
    if(node == NULL){
        comparisons++;
        return new SNode(key);
    }

    node = splay(node, key);

    if(node->key == key) return node;

    SNode * thisNode = new SNode(key);

    if(node->key > key) {
        comparisons++;
        thisNode->rightChild = node;
        thisNode->leftChild = node->leftChild;
        node->leftChild = NULL;
    }
    else if(node->key < key) {
        comparisons++;
        thisNode->leftChild = node;
        thisNode->rightChild = node->rightChild;
        node->rightChild = NULL;
    }
    return thisNode;
}

SNode * SplayTree::remove(int key) {
    root = removeS(root, key);
    return root;
}

SNode * SplayTree::removeS(SNode * root, int key){
    SNode * thisNode;
    if(root == NULL){
        comparisons++;
        return root;
    }

    root = splay(root, key);

    if(key != root->key){
        comparisons++;
        return root;
    }

    //if no left child, make right child the new root
    if(root->leftChild == NULL){
        comparisons++;
        thisNode = root;
        root = root->rightChild;
    }
    else { //if root has a left child
        comparisons++;
        thisNode = root;
        root = splay(root->leftChild, key);
        root->rightChild = thisNode->rightChild;
    }
    delete thisNode;
    return root;
}