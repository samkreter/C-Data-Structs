//Sam Kreter
//sakfy6
//4/1/14
//APRILFOOL

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//struct def
typedef struct bt_{
  int value;
  struct bt_ *right;
  struct bt_ *left;
}BST;

//funciton prototypes
void print_inOrder(BST *n);
BST* create_node(int value);
BST* insert(BST* root, int value);
void printTree(BST* root);
void displayBST(BST* root, int depth);
void padding(char toPrint, int numTimes);
int search(BST* root, int value);
BST* findNearest(BST* root, int value);


int main(int argc, char *argv[]){

  //check command line arguments
  if(argc != 2){
    printf("insufficent command line argument");
    exit(0);
  }
  
  //open the file
  FILE* input = fopen(argv[1],"r");
  if(input == NULL){
    printf("File not found");
    exit(0);
  }

  BST* root = NULL;
  BST* closest = NULL;
  int value = 0,i = 0; 

  //load the file
  while(fscanf(input,"%d",&value) != EOF){
    root = insert(root, value);
  }
 
  close(input); //close the file
 
  print_inOrder(root); //print the tree inorder

  printf("Enter a number to search for in the tree: ");
  scanf("%d",&value);
  printf("%d was %s",value,search(root,value) == 1?"found":"not found");//search the value if found tell the user

  printf("\nBONUS: Enter a number to search for in the tree: ");
  scanf("%d",&value);

  //test if the vals there, if not find nearest
  if(search(root,value)){
    printf("The value %d is in the tree",value);
  }
  else{
    closest = findNearest(root, value);
    printf("The nearest number to %d is %d",value,closest->value);
  }
  

  return 0;

}

BST* findNearest(BST* root, int value){
  BST* closest = NULL;
  BST* curr = root;
  int distance = 0;
  int minDistance = abs(root->value - value);

  if(root == NULL){ // test empty tree
    printf("Can't search an empty tree");
  }
  while(curr != NULL){
    distance = abs(curr->value - value);
    if(distance < minDistance){ //find the lowest distance and return that node
      closest = curr;
      minDistance = distance;
    }
    if(curr->value > value){
      curr = curr->left;    
    }
    else{
      curr = curr->right;
    }
    
  }
  return closest;
}

//recusivly search for the value in the tree, return 1 if found 0 if not
int search(BST* root, int value){
  if(root == NULL){
    return 0;
  }
  else if(root->value == value){
    return 1;
  }
  else if(root->value > value){
    return search(root->left, value); 
  }
  else{
    return search(root->right, value);
  }
}
 
//malloc memory for the tree
BST* create_node(int value){
  BST* n = (BST *)malloc(sizeof(BST));
  n->left = NULL;
  n->right = NULL;
  n->value = value;
  return n;
}


//recursivly insert the node into the correct place in the tree
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

//prints the tree in a horrible way that no! can reat
//
//Go to bottom to see the inorder function that is really awsome and works much better
//
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

//badass function that works better than the above
void print_inOrder(BST *root){

  if(root == NULL){
    return;
  }

  print_inOrder(root->left);
  printf("%d\n", root->value);
  print_inOrder(root->right);

} 
