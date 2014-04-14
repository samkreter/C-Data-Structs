
//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*This is needed in order to for us to use our functions because they contain the prototypes
as well as our structures. Make sure you understand what this header file is here
for and why we include it outside of our algorithm.c file*/
#include "header.h"

/********************************** createTreeNode *******************************
 parameters: int value to be inserted in the binary search tree
 returns: pointer to a newly created binary search tree node (BST*)
 
 -> createTreeNode simply creates a new tree node using the value passed as the 
    parameter.
*********************************************************************************/

BST* createTreeNode(int nodeValue, int treeNum){
	BST* n = (BST *)malloc(sizeof(BST*));
	n->value = nodeValue;
	n->treeNum = treeNum;
	n->left = NULL;
	n->right = NULL;
	return n;	 
}

/********************************** insert_BST *****************************************
 parameters: the reference of the root (BST**) and the int value to be inserted.
 returns: void
 
 -> This function recursively finds the right position in the binary search tree 
    for the new value and inserts the node containing the new value in that position.
*****************************************************************************************/

void insert_BST(BST** root, int insertValue, int treeNum){
	if(*root == NULL){
		*root = createTreeNode(insertValue,treeNum);
		return;
	}
	else if((*root)->value >= insertValue){
		insert_BST(&((*root)->left), insertValue, treeNum);
	}
	else if((*root)->value < insertValue){
		insert_BST(&((*root)->right), insertValue, treeNum);
	}
}


/********************************** insert_rootList ******************************
 parameters: the reference of the head pointer to the list (BST**) and pointer
             to the root of the new binary search tree
 returns: void
 
 -> This function inserts the new binary search tree at the BACK of the linked 
    list containing pointers to the roots of the binary search trees.
*********************************************************************************/

void insert_rootList(rootList** listHead, BST* new_root){
	
	if((*listHead) == NULL){
		*listHead = (rootList *)malloc(sizeof(rootList*));
		(*listHead)->root = new_root;
		(*listHead)->next = NULL;
	}
	else{
	    rootList* temp = *listHead;
		while(temp->next != NULL){
	      temp = temp->next;
		}

		temp->next = (rootList *)malloc(sizeof(rootList*));
	    temp->next->root = new_root;
	}
}

/************************************** BFS **************************************
 parameters: the pointer to the start of the linked list and the int value to be
 searched
 returns: void
 
 -> This function implements a variant of a level by level search or formally
 called as the BREADTH FIRST SEARCH.
 -> This function searches for a given value in the binary trees and it does that
 by searching for level 1 in each binary trees, then moving on to level 2 if
 it fails to find it that value in level 1 and so on.
 -> Basically, you have to search for a given value in all the binary trees, one
 level at a time, in the linked list simultaneously.
 
 //////////////////////////////////////////////////////////////////////////////
 / HINT: Use the enqueue and dequeue functions to solve this problem. You will
 /       have a hard time solving this problem without using the enqueue and
 /       dequeue functions.
 /////////////////////////////////////////////////////////////////////////////
 
 *********************************************************************************/

void BFS(rootList* listHead, int searchValue){
	//check if empty
	if(listHead == NULL){
		return;
	}

    //declare all the varibles
	bfsQ* queue = NULL;
	rootList* temp = listHead;
	BST* traverse = NULL;
	int level, found;
	level = found = 0;
	
	//queue up all the roots
	while(temp->next != NULL){
		enqueue(&queue,temp->root);
	}

	traverse = dequeue(queue);
	while(traverse != NULL){
		
		if(traverse->left != NULL){
			enqueue(&queue,traverse->left);
		}
		if(traverse->right != NULL){
			enqueue(&queue, traverse->right);
		}

		if(traverse->value == searchValue){
			break;
		}
		else{
			traverse = dequeue(queue);
		}
	}



}

/************************************ enqueue ************************************
 parameters: the reference of the head of the queue and pointer to the tree node
             to be inserted in the queue
 returns: void
 
 -> This Function inserts the new tree node in the queue that is used to do a BFS.
 
 *********************************************************************************/

void enqueue(bfsQ** qHead, BST* new_tree_node){
	if(*qHead == NULL){
		(*qHead)->treeNode = new_tree_node;
		(*qHead)->next = NULL;
	}
	else{
		enqueue(&(*qHead->next),new_tree_node);
	}
}

/********************************** dequeue **************************************
 parameters: the reference of the head of the queue.
 returns: pointer to the dequeued tree node
 
 -> This Function dequeue's the tree node in front of the queue and returns it.
 
 *********************************************************************************/

BST* dequeue(bfsQ** qHead){
	bfsQ* temp = *qHead;
    *qHead = (*qHead)->next;
    return temp;
}

/********************************** printTrees **************************************
 parameters: pointer to the head of the linked list
 returns: void
 
 -> This Function prints all the binary search trees in the linked list
 *********************************************************************************/

void printTrees(rootList* listHead){
  static int counter = 1;
  if(listHead == NULL){
  	return;
  }
  else{
  	printf("Tree %d: ",counter++);
  	print_BST_inorder(listHead->root);
  	printf("\n");
  	printTrees(listHead->next);
  }
}

/****************************** print_BST_inorder *******************************
 parameters: pointer to the root of the tree
 returns: void
 
 -> This Function prints the binary search tree using inorder traversal
 *********************************************************************************/

void print_BST_inorder(BST* root){
	if(root == NULL){
		return;
	}

	print_BST_inorder(root->left);
	printf("%d ",root->value);
	print_BST_inorder(root->right);
}

/********************************* free_list *************************************
 parameters: reference of the pointer to the head of the linked list
 returns: void
 
 -> This function frees all the allocated memory.
 -> This function also calls the free_BSTs function to free the binary search trees.
 *********************************************************************************/

void free_list(rootList** listHead){

}

/********************************* free_BSTs *************************************
 parameters: Pointer to the root of the binary search tree
 returns: void
 
 -> This function frees all the nodes in the given binary search tree recursively.
 *********************************************************************************/

void free_BSTs(BST* root){

}

