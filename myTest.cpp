#include <iostream>

#include "Node.h"
#include "BST.h"

using namespace std;

int main(){

    cout << "Hello World!" << endl;

    
    BST *myTree = NULL;
    myTree = new BST();
    
    myTree->add(5);
    myTree->add(4);
    myTree->clear();
    myTree->getRootNode();
    myTree->remove(5);
    
}