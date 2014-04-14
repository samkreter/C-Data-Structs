//prelab 9 sample code by alex lobzhanidze
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *left, *right;
}bst;

//function prototypes
bst *create_node(int val);
bst *insert(bst *root, int val);
void printInorder(bst *root);

void printTree(bst* root);
void displayBST(bst* root, int depth);
void padding(char toPrint, int numTimes);

bst *create_node(int val)
{
	bst *n = malloc(sizeof(bst));
		n->val=val;
		n->left = NULL;
		n->right = NULL;
	return n;
}

bst *insert(bst *root, int val)
{
	if (root == NULL)
		root = create_node(val);
	else
	{
		if (val < root->val)
			root->left = insert(root->left, val);
		else
			root->right = insert(root->right, val);
	}
 return root;
}



void padding(char toPrint, int numTimes)
{
	int i;
	for (i = 0; i < numTimes; i++)
		printf("%c", toPrint);
}

void displayBST(bst* root, int depth)
{
	if (root == NULL)
	{
		padding(' ', depth);
		printf("-\n");
		return;
	}

	displayBST(root->left, depth+4);
	padding(' ', depth);
	printf("%d\n", root->val);
	displayBST(root->right, depth+4);
}

void printTree(bst* root)
{
	displayBST(root, 0);
}
//prints the bst in order
void printInorder(bst *root){

  if(root == NULL){
    return;
  }

  printInorder(root->left);
  printf("%d ", root->val);
  printInorder(root->right);

}
//prints the bst in preorder
void printPreorder(bst *root){

  if(root == NULL){
    return;
  }

  printf("%d ",root->val);
  printPreorder(root->left);
  printPreorder(root->right);
}
// prints the bst in postorder
void printPostorder(bst* root){

  if(root == NULL){
    return;
  }

  printPostorder(root->left);
  printPostorder(root->right);
  printf("%d ",root->val);
}

