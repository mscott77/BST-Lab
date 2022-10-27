    #include "BST.h"
    #include "Node.h"

    using namespace std;
    
    /*------------------------------------------getRootNode()------------------------------------------------
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	Node* BST :: getRootNode() const
    {
        //cout << "In getRoot" << endl;
        return root;
    }

	/*------------------------------------------add()------------------------------------------------
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
    // this function is just the wrapper
	bool BST :: add(int data)
    {
        cout << "In add" << endl;
        // just immedietly call the add helper function 'insert'
        return insert(this->root,data); // this->root refers to the BST classes member variable 'root' which is a Node
    }

    // this function does the actual recursion
    bool BST :: insert(Node *& localRoot , int data)
    {
        // if you reach a NULL child, you are either at the bottom of the tree, 
        // or the tree is empty and this is the first element to be added.
        // either way, make a new Node and add the data into it! 
        if(localRoot == NULL){
            localRoot = new Node(data);
            return true;
        }
        else // item has not been found yet, recursively search the tree till you find the correct place and then make the new node!
        {
            if (data < localRoot->getData()){ // if the data to insert is less than the data at the current Node
                return insert(localRoot->left , data); // recursively search the left child of the current Node
            }
            else if (data > localRoot->getData()){ // if the data to insert is more than the data at the current Node
                return insert(localRoot->right , data);
            }
            else { // in the case of a match, don't insert anything and return false. no Duplicate values are allowed
                cout << "item already exists in the tree. no Items were added" << endl;
                return false;
            }
        }

    }

	/*------------------------------------------remove()------------------------------------------------
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST :: remove(int data)
    {
        cout << "In remove" << endl;
        return false;

    }

	/*------------------------------------------clear------------------------------------------------
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST :: clear()
    {
        cout << "In clear" << endl;

    }

	/*------------------------------------------MasonsCustomFunction------------------------------------------------
	* a custom made function for testing. it prints out an In-Order Traversal of the tree
	*/
    // helper function
	void BST :: PrintInOrder()
    {
        cout << "In PrintInOrder" << endl;
        // if the tree is empty, don't call the recursive function
        if(this->root == NULL){
            cout << "root Node is NULL, tree is empty" << endl;
        }
        else{
            cout << "current tree as seen using InOrder Traversal" << endl;
            InOrder(this->root);
        }
    }

    // the actual function
    void BST :: InOrder(Node *n) // takes in the root node of the tree as the only paramater needed to start the traversal
    {
        if (n == NULL){return;}
        InOrder(n->getLeftChild());
        cout << n->getData() << " "<< endl;
        InOrder(n->getRightChild());
    }
