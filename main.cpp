#include <iostream>
#include "main.h"
using namespace std;

int main(int argc, char * argv[]) {
    if(argc < 1){
        cout << "No file provided." << endl;
    }
    string fileName = "";
    fileName = argv[1];
    ifstream file;
    file.open(fileName.c_str());

    //getline of data 
    string data = "";
    getline(file, data);
    stringstream BSTss(data);
    int key1 = 0;

    cout << "BST INSERTION" << "\n";
    cout << endl;

    BSTree bst;
    while(BSTss >> key1){
        // cout << "key being inserted is: " << key1 << endl;
        bst.insert(key1);
    }

    bst.print();

    cout << "\n\n";

    //get filler dollar sign
    string dollar = "";
    getline(file, dollar);

    cout << "BST REMOVALS" << "\n";

    //getline of items to be removed 
    string removals = "";
    getline(file, removals);
    stringstream BSTr(removals);
    int toRemove1 = 0;

    while(BSTr >> toRemove1){
        // cout << "key being removed is: " << toRemove1 << endl;
        bst.remove(toRemove1);
        bst.print();
        cout << "\n";
    }

    cout << "\n\n";

    cout << "AVL INSERTION" << "\n";

    AVLTree avl;

    stringstream AVLss(data);
    int key2 = 0;
    while(AVLss >> key2){
        // cout << "key being inserted: " << key2 << endl;
        avl.insert(key2);
    }

    avl.print();

    cout << "\n\n";

    cout << "AVL REMOVAL" << "\n\n";

    stringstream AVLr(removals);
    int toRemove2 = 0;
    while(AVLr >> toRemove2){
        // cout << "key being removed: " << toRemove2 << endl;
        avl.remove(toRemove2);
        avl.print();
        cout << "\n";
    }

    cout << "\n\n";

    SplayTree splay;

    cout << "SPLAY INSERTION" << "\n\n";

    stringstream Splayss(data);
    int key3 = 0;
    while(Splayss >> key3){
        // cout << "key being inserted: " << key3 << endl;
        splay.insert(key3);
    }

    splay.print();

    cout << "\n\n";

    cout << "SPLAY REMOVAL" << "\n\n";

    stringstream Splayr(removals);
    int toRemove3 = 0;
    while(Splayr >> toRemove3){
        // cout << "key being removed: " << toRemove3 << endl;
        splay.remove(toRemove3);
        splay.print();
        cout << "\n";
    }

    splay.print();

    cout << "\n";

    cout << "Total BST comparisons: " << bst.comparisons << endl;
    cout << "Total AVL comparisons: " << avl.comparisons << endl;
    cout << "Total Splay comparisons: " << splay.comparisons << endl;

    if(avl.comparisons < bst.comparisons) {
        cout << "AVL operations are more efficient than BST operations." << endl;
    }
    else {
        cout << "BST operations are more efficient than AVL operations." << endl;
    }

    cout << "\n";

    return 0;
}