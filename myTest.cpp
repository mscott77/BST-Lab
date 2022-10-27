#include <iostream>

#include "Node.h"
#include "BST.h"

using namespace std;

int main(){

    cout << "Hello World!" << endl;

    
    BST *myTree = NULL;
    myTree = new BST();
    
    myTree->add(5);
    myTree->add(3);
    myTree->add(7);
    myTree->PrintInOrder(myTree);

    
    
}
