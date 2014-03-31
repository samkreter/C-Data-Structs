#include<stdio.h>
#include<time.h>
#include<stdlib.h>


typedef struct bt_{
  int value;
  struct bt_ *right;
  struct bt_ *left;
}BST;


BST* create_node(int value);
BST* insert(BST* root, int value);
void printTree(BST* root);
void displayBST(BST* root, int depth);
void padding(char toPrint, int numTimes);

int main(){

  BST* root = NULL;
  int i, array[9] ={1,6,4,8,10,9,3,2,7};
  root = insert(root,5);
  for(i=0; i<9; i++){
    root = insert(root,array[i]);
  }
  
  printTree(root);

  return 0;

}

BST* create_node(int value){
  BST* n = (BST *)malloc(sizeof(BST));
  n->left = NULL;
  n->right = NULL;
  n->value = value;
  return n;
}

BST* insert(BST* root, int value){
  if(root == NULL){
    root = create_node(value);
    return root;
  }
  else if(root->value < value){
    root->right = insert(root->right, value);
  }
  else{
    root->left = insert(root->left, value);
  }

  return root;
}

void printTree(BST* root){
  displayBST(root,0);
}

void displayBST(BST* root, int depth){
  if(root == NULL){
    padding(' ',depth);
    printf("-\n");
    return;
  }

  displayBST(root->left,depth+4);
  padding(' ',depth);
  printf("%d\n",root->value);
  displayBST(root->right, depth+4);

}

void padding(char toPrint, int numTimes){
  int i;
  for(i=0; i<numTimes; i++){
    printf("%c",toPrint);
  }
}
