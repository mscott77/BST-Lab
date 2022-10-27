#include "Node.h"

using namespace std;

/*------------------------------------------------------getData--------------------------------------------------------
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int Node :: getData() const
    {
        return data;
    }

	/*------------------------------------------------------getLeftChild--------------------------------------------------------
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	Node* Node :: getLeftChild() const
    {
        return left;
    }

	/*------------------------------------------------------getRightChild--------------------------------------------------------
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	Node* Node :: getRightChild() const
    {
        return right;
    }