    #include "BST.h"
    #include "Node.h"

    using namespace std;
    
    /*------------------------------------------getRootNode()----------------------------------------(done)
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	Node* BST :: getRootNode() const
    {
        //cout << "In getRoot" << endl;
        return root;
    }

	/*------------------------------------------add()------------------------------------------------(done)
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
        return erase(this->root,data);

    }

    bool BST :: erase(Node*& local_root, const int& item) {
  if (local_root == NULL) { // if you get to a Node and it's NULL, it means you're at a dead end, the item you want to erase was not found down this path
    return false;
  } else {
    if (item < local_root->data) // if the item to insert is less than the current localRoot...
      return erase(local_root->left, item);//search the left side of the subtree
    else if (local_root->data < item)// if the item to insert is greater than the current localRoot...
      return erase(local_root->right, item);//search the right side of the subtree
    else { // if the item is not less than or greater than the current Node, it must BE EQUAL TO the current node 
      Node* old_root = local_root; // save the address to the Node to be deleted in case you need it later
      if (local_root->left == NULL) { // if the node to be deleted's left child is NULL
        local_root = local_root->right; // set the current Node = to the RIGHT child (may be NULL or a valid Node)
      } else if (local_root->right == NULL) {
        local_root = local_root->left;
      } else {
        replace_parent(old_root, old_root->left);
      }
      delete old_root;      
      return true;
    }
  }
}


void BST :: replace_parent(Node*& old_root,Node*& local_root) 
{
  if (local_root->right != NULL) {
    replace_parent(old_root, local_root->right);
  } else {
    old_root->data = local_root->data;
    old_root = local_root;
    local_root = local_root->left;
  }
}

	/*------------------------------------------clear------------------------------------------------
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
    // wrapper function for the eraseTree() function
	void BST :: clear()
    {
        cout << "In clear" << endl;
        // call the helper function to start recursion
        eraseTree(root);

    }

    // recursively search the left and right children. if both a Nodes children are NULL, delete it
    void BST :: eraseTree(Node *& localRoot)
    {
        if(localRoot != NULL)
        {
            eraseTree(localRoot->left);
            eraseTree(localRoot->right);
            delete localRoot;
            localRoot = NULL;
        }
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
