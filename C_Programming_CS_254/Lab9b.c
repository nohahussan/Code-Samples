// preprocessor directives
#include<stdlib.h>
#include<stdio.h>
#include <time.h>

// structure for binary tree
typedef struct Nodes 
{
	int value;						// value of tree node
	struct Nodes *left;				// pointer to left subTree
	struct Nodes *right;			// pointer to right subTree
	struct Nodes *parent;			// pointer to subtree parent
	int size;						// tree size, including this node
} Node;

// function prototypes
Node *insertValue(Node *parentNode, Node *insertionNode, int value);

Node *treeSearch(Node *treeRoot, int value);
Node *treeMinimum(Node *treeRoot);
Node *treeMaximum(Node *treeRoot);
Node *treeSuccessor(Node *nodePointer);
Node *treePredecessor(Node *nodePointer);
void treeMedian(Node *treeRoot, Node **medianNode, int treeSize, int *nodeCount);
void treeRange(Node *treeRoot, int minValue, int maxValue);

void treeInOrder(Node *treeRoot);
void printTree(Node *tree);
void clearTree(Node *treeRoot);

// Main program function
int main()
{
	// variable decleration
	Node *treeRoot = NULL;		// pointer for tree root
	int i;						// loop counter
	srand (time(NULL));										// seed the random generator
	
	
	// a 15 element tree
	// creat radnom values and insert in tree
	treeRoot = NULL;
	i = 0;
	while( i < 15 ) 
	{
		treeRoot = insertValue(treeRoot, treeRoot, rand() % 100);		// insert value in tree
		if (treeRoot != NULL)
			i = treeRoot->size;
	}
	printf("\n****Tree Structure*****\n");
	printTree(treeRoot);									// print tree structure
	
	printf("\n****In Order Traversal of Tree Nodes*****\n");
	treeInOrder(treeRoot);									// print tree values in order
	printf("\n");
	
	printf("\n****Minimum and Maximum values*****\n");
	printf("the minimum key value is:%d\n", (treeMinimum(treeRoot))->value);// print min value
	printf("the maximum key value is:%d\n", (treeMaximum(treeRoot))->value);// print max value

	printf("\n****Tree Median*****\n");
	int nodeCount = 0;										// to keep tree of nodes count while traversing
	Node *medianNode;										// to save pointer of median node
	treeMedian(treeRoot, &medianNode, treeRoot->size, &nodeCount);	// find median node
	printf("%d\n", medianNode->value);						// print median node value
	
	// get user input for a value to look for
	int searchValue;
	printf("\nPlease enter a key value to search for: ");
	scanf("%d",&searchValue);
	Node *searchResult = treeSearch(treeRoot, searchValue);	// search tree for value
	if (searchResult != NULL)
	{
		printf("value was found in tree\n");
		// get successor of node
		Node *nodeSuccssor = treeSuccessor(searchResult);
		if (nodeSuccssor != NULL) 
			printf("the successor of this node is: %d\n", nodeSuccssor->value);
		else
			printf("this node doesn't have a successor\n");
			
		// get the predessor of node
		Node *nodePredecessor = treePredecessor(searchResult);
		if (nodePredecessor != NULL) 
			printf("the predecessor of this node is: %d\n", nodePredecessor->value);
		else
			printf("this node doesn't have a predecessor\n");
	}
	else
		printf("value not found it tree\n");
	
	// get user input for two values and print values in that range
	int lowValue, highValue;
	printf("\nPlease enter a two values for a range (low, high): ");
	scanf("%d,%d",&lowValue,&highValue);
	treeRange(treeRoot, lowValue, highValue);
	printf("\n");
	
	clearTree(treeRoot);									// free memory of tree
	// return 0 to indicate sucessful termination of main
	return 0;
}

/*insertValue function
Objective: 		insert a value into a binary tree linked list
				using recursive call, traversed the tree,
				to find the insertion point , the value 
				is inseted to the left or right of a parent based on its value

Inputs:
parentNode:		a pointer to a Node date type 
value:			vlaue to be inserted


Outputs:
pointer to inserted Node is returned 
*/
Node *insertValue(Node *parentNode, Node *insertionNode, int value) 
{
	// insert value in left subTree if it is less than or equal to its parent value, 
	// otherwise insert in right subTree
	if( insertionNode == NULL ) 		// its a new node, create one.
	{
		insertionNode = (Node *) malloc(sizeof(Node));	// memory allocation for new node
		insertionNode->value = value;					// insert value
		// since node is new, no children exist yet
		insertionNode->left = NULL;
		insertionNode->right = NULL;
		// assign parent and size
		insertionNode->parent = parentNode;
		insertionNode->size = 1;
	}
	else if (value < insertionNode->value)				// if value is less than or equal
		insertionNode->left = insertValue(insertionNode, insertionNode->left, value);	// insert in left subTree
	else if (value > insertionNode->value)
		insertionNode->right = insertValue(insertionNode, insertionNode->right, value);	// insert in right subTree
	else												// repeated key values are not inserted
		return insertionNode;
	
	// calculate size
	insertionNode->size = 1;							// this node
	if (insertionNode->left != NULL)					// add left subtree
		insertionNode->size += insertionNode->left->size;
	if (insertionNode->right != NULL)					// add right subtree
		insertionNode->size += insertionNode->right->size;
	
	return insertionNode;
}

/*treeSearch function
Objective: 		find the node with a specific search value

Inputs:
treeRoot:		a pointer tree or subtree

Outputs:
pointer to node with value equal to the search value.
*/
Node *treeSearch(Node *treeRoot, int value) 
{
	// perform recursive search for a value
	if ( treeRoot == NULL || value == treeRoot->value )	// value found or reached the end of tree
		return treeRoot;
	
	if ( value < treeRoot->value)						// value is in left subTree 
		return treeSearch(treeRoot->left, value);
	else												// value is in the right subTree
		return treeSearch(treeRoot->right, value);
}

/*treeMinimum function
Objective: 		find the minimum value in a binary search tree

Inputs:
treeRoot:		a pointer tree or subtree

Outputs:
pointer to node with minimum value
*/
Node *treeMinimum(Node *treeRoot)
{
	while (treeRoot->left != NULL)
		treeRoot = treeRoot->left;
	
	return treeRoot;
} 

/*treeMaximum function
Objective: 		find the maximum value in a binary search tree

Inputs:
treeRoot:		a pointer tree or subtree

Outputs:
pointer to node with maximum value
*/
Node *treeMaximum(Node *treeRoot)
{
	while (treeRoot->right != NULL)
		treeRoot = treeRoot->right;
	
	return treeRoot;
} 

/*treeSuccessor function
Objective: 		find the successor of a node, 
				the node with the smallest key value greater than
				the value of the input node

Inputs:
nodePointer:	a pointer to a node in a tree.

Outputs:
pointer to successor node, if it exitst, or NULL otherwise
*/
Node *treeSuccessor(Node *nodePointer)
{
	Node *nodeParent;
	if (nodePointer->right != NULL)
		return treeMinimum(nodePointer->right);
	else
	{
		nodeParent = nodePointer->parent;
		while ( nodeParent != NULL && nodePointer == nodeParent->right )
		{
			nodePointer = nodeParent;
			nodeParent = nodeParent->parent;
		}
	}
	
	return nodeParent;
}

/*treePredecessor function
Objective: 		find the predecessor of a node, 
				the node with the largest key value less than
				the value of the input node

Inputs:
nodePointer:	a pointer to a node in a tree.

Outputs:
pointer to predecessor node, if it exitst, or NULL otherwise
*/
Node *treePredecessor(Node *nodePointer)
{
	Node *nodeParent;
	if (nodePointer->left != NULL)
		return treeMaximum(nodePointer->left);
	else
	{
		nodeParent = nodePointer->parent;
		while ( nodeParent != NULL && nodePointer == nodeParent->left )
		{
			nodePointer = nodeParent;
			nodeParent = nodeParent->parent;
		}
	}
	
	return nodeParent;
}


/*treeMedian function
Objective: 		find the median node in a binary search tree

Inputs:
treeRoot:		a pointer tree or subtree
medianNode:		a pointer to a pointer to variabel to type Node to store median pointer
treeSize:		an integer value for the tree size.
nodeCount:		a pointer to an integer to count elements during traversal

Outputs:
median node is found and its pointer is saved in medianNode pointer
*/
void treeMedian(Node *treeRoot, Node **medianNode, int treeSize, int *nodeCount)
{
	// recursive call of left nodes	
	if(treeRoot->left != NULL)
		treeMedian(treeRoot->left, medianNode, treeSize, nodeCount);
		
	(*nodeCount)++;
	// return median node
	if ( (*nodeCount) == (treeSize + 1) / 2 )
	{
		*medianNode = treeRoot;
		return;
	}
	else if ( (*nodeCount) > (treeSize + 1) / 2 )	// if past median, stop traversal
		return;
	
	// recursive call of right nodes	
	if(treeRoot->right != NULL) 
		treeMedian(treeRoot->right, medianNode, treeSize, nodeCount);
}

/*treeRange function
Objective: 		print all values in tree between two values inclusive

Inputs:
treeRoot:		a pointer tree or subtree
minValue:		range mimimum value
maxValue:		range maximum value

Outputs:
print values inside input range
*/
void treeRange(Node *treeRoot, int minValue, int maxValue)
{
	// recursive call of left nodes	
	if(treeRoot->left != NULL)
		treeRange(treeRoot->left, minValue, maxValue);
		
	// print values of nodes in range 
	if ( treeRoot->value >= minValue && treeRoot->value <= maxValue )
	{
		printf("%d,",treeRoot->value);
	}
	
	// if past maximum value, stop traversal
	if ( treeRoot->value > maxValue )
		return;
	
	// recursive call of right nodes	
	if(treeRoot->right != NULL) 
		treeRange(treeRoot->right, minValue, maxValue);
}

/*treeInOrder function
Objective: 		print a binary search tree in order

Inputs:
treeRoot:		a pointer tree or subtree

Outputs:
tree node values are printed in ascending order
*/
void treeInOrder(Node *treeRoot)
{
	// recursive call of left nodes	
	if(treeRoot->left != NULL)
		treeInOrder(treeRoot->left);
	
	// print node value
	printf("%d,",treeRoot->value);
	
	// recursive call of right nodes	
	if(treeRoot->right != NULL) 
		treeInOrder(treeRoot->right);
}

/*clearTree function
Objective: 		free memory created for tree using malloc

Inputs:
treeRoot:		a pointer tree or subtree

Outputs:
memory is feee for other uses within the program
*/
void clearTree(Node *treeRoot)
{
	// recursive call of left nodes	
	if(treeRoot->left != NULL)
		clearTree(treeRoot->left);
	
	// recursive call of right nodes	
	if(treeRoot->right != NULL) 
		clearTree(treeRoot->right);
		
	// clear memory of node 
	free(treeRoot);
}

/*printTree function
Objective: 		print a representation of the tree structure
				to help visulaize how the tree is implemented

Inputs:
treeRoot:		a pointer tree or subtree

Outputs:
every node is printed out with its left and right children values
*/
void printTree(Node *treeRoot) 
{
	// print node value
	printf("node %2d \ttree size = %2d",treeRoot->value, treeRoot->size);
	// print parent value
	if(treeRoot->parent != NULL)
		printf("\tParent %2d ", treeRoot->parent->value);
	else
		printf("\tRoot\t");
		
	// print value of left child
	if(treeRoot->left != NULL)
		printf("\tleft child %2d", treeRoot->left->value);
	else
		printf("\t\t");
		
	// print value of right child
	if(treeRoot->right != NULL) 
		printf("\tright child %2d", treeRoot->right->value);
		
	printf("\n");

	// recursive call of left nodes	
	if(treeRoot->left != NULL)
		printTree(treeRoot->left);
	
	// recursive call of right nodes	
	if(treeRoot->right != NULL) 
		printTree(treeRoot->right);
}
