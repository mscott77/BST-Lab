#include <iostream>

#include "Node.h"
#include "BST.h"

using namespace std;

int main(){

    cout << "Hello World!" << endl;

    BST *myTree = NULL;
    myTree = new BST();
    
    cout << "doing a print command, but nothign should come out because the tree is empty" << endl;
    myTree->PrintInOrder();

    cout << endl;//----------------------------

    myTree->add(5);
    myTree->add(3);
    myTree->add(7);
    myTree->PrintInOrder();
    
    cout << endl;//----------------------------

    myTree->add(5);
    myTree->PrintInOrder();

    cout << endl;//----------------------------
    
    cout << "clearing the tree" << endl;
    myTree->clear();
    cout << "doing a print command, but nothing should come out because the tree just got cleared" << endl;
    myTree->PrintInOrder();
    
    cout << endl;//----------------------------


    delete myTree;
    
    
}
