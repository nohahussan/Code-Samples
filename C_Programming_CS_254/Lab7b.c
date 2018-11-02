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
} Node;

// function prototypes
Node *insertValue(Node *parentNode, int value);
void printTree(Node *tree);
void getTreeCount(Node *treeRoot, int *leaveCount, int *oneChildCount, int *twoChildNodeCount);
void clearTree(Node *treeRoot);

// Main program function
int main()
{
	// variable decleration
	Node *treeRoot = NULL;		// pointer for tree root
	int i;						// loop counter
	int leaveCount, twoChildNodeCount, oneChildCount; 		// for counte calclualtion storage
	srand (time(NULL));										// seed the random generator
	
	
	// a 10 element tree
	// creat radnom values and insert in tree
	for(i = 0; i < 10; i++) 
	{
		treeRoot = insertValue(treeRoot, rand() % 100);		// insert value in tree
	}
	printf("****Tree Structure*****\n");
	printTree(treeRoot);									// print tree structure
	// calculate differnt counts for tree
	leaveCount = 0;
	oneChildCount = 0; 
	twoChildNodeCount = 0;
	getTreeCount(treeRoot, &leaveCount, &oneChildCount, &twoChildNodeCount);
	// print out results
	printf("\nThe previous binary tree has %d leaves,\n", leaveCount);
	printf("%d nodes with only one child,\n", oneChildCount);
	printf("and %d nodes with exactly two children.\n\n", twoChildNodeCount);
	clearTree(treeRoot);									// free memory of tree
	
	
	// a 15 element tree
	// creat radnom values and insert in tree
	treeRoot = NULL;
	for(i = 0; i < 15; i++) 
	{
		treeRoot = insertValue(treeRoot, rand() % 100);		// insert value in tree
	}
	printf("****Tree Structure*****\n");
	printTree(treeRoot);									// print tree structure
	// calculate differnt counts for tree
	leaveCount = 0;
	oneChildCount = 0; 
	twoChildNodeCount = 0;
	getTreeCount(treeRoot, &leaveCount, &oneChildCount, &twoChildNodeCount);
	// print out results
	printf("\nThe previous binary tree has %d leaves,\n", leaveCount);
	printf("%d nodes with only one child,\n", oneChildCount);
	printf("and %d nodes with exactly two children.\n\n", twoChildNodeCount);
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
Node *insertValue(Node *parentNode, int value) 
{
	// insert value in left subTree if it is less than or equal to its parent value, 
	// otherwise insert in right subTree
	if( parentNode == NULL ) 		// its a new node, create one.
	{
		parentNode = (Node *) malloc(sizeof(Node));		// memory allocation for new node
		parentNode->value = value;						// insert value
		// since node is new, no children exist yet
		parentNode->left = NULL;
		parentNode->right = NULL;
	}
	else if (value <= parentNode->value)				// if value is less than or equal
		parentNode->left = insertValue(parentNode->left, value);	// insert in left subTree
	else
		parentNode->right = insertValue(parentNode->right, value);	// insert in right subTree
		
	return parentNode;
}

/*getTreeCount function
Objective: 		counts nodes with only one child and
				nodes with two children, and 
				nodes with no children ie. leaves

Inputs:
treeRoot:		a pointer tree or subtree 
leaveCount:		a pointer to integer for leave count storage
oneChildCount:	a pointer to ingeger for oneChild count storage
twoChildNodeCount: a pointer to integer for two child count storage


Outputs:
counts are updated using their pointers
*/
void getTreeCount(Node *treeRoot, int *leaveCount, int *oneChildCount, int *twoChildNodeCount)
{
	// traverse the tree in PreOrder, and count nodes with various proporties

	// visit root
	// Node has two children
	if ((treeRoot->left != NULL) && (treeRoot->right != NULL))
		(*twoChildNodeCount)++;
	// Node has no children, it is a leaf
	else if ((treeRoot->left == NULL) && (treeRoot->right == NULL))
		(*leaveCount)++;
	// Node has one child
	else
		(*oneChildCount)++;
	
	
	// visit left subtree in preorder
	// recursive call of left nodes	
	if(treeRoot->left != NULL)
		getTreeCount(treeRoot->left, leaveCount, oneChildCount, twoChildNodeCount);
	
	// visit right subtree in preorder
	// recursive call of right nodes	
	if(treeRoot->right != NULL) 
		getTreeCount(treeRoot->right, leaveCount, oneChildCount, twoChildNodeCount);
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
	printf("node %2d ",treeRoot->value);
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
