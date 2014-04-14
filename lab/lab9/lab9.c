//Sam Kreter
//sakfy6
//4/8/14
//NOTSOTALL

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"bst.h"

//funciton prototypes
bst *createBST(int a[], int size);
void sort(int a[], int size);
bst* createMinBST(int a[], int start, int end);
void merge_sort(int array[], int low, int high);
void merge(int array[], int low, int middle, int high);


int main(int argc, char *argv[]){

  //check command line arguments
  if(argc != 2){
    printf("usage: ./a.out <input_filename>");
    exit(0);
  }
  
  //open the file
  FILE* input = fopen(argv[1],"r");
  if(input == NULL){
    printf("File not found");
    exit(0);
  }

  bst* root = NULL; 
  int i = 0; 
  int size = 0;
  
  
  fscanf(input,"%d",&size);

  int *a = (int *)malloc(sizeof(int)*size);//create the array
  
  for(i=0;i<size;i++){
    fscanf(input,"%d",&a[i]);
  }
  
  close(input); //close file

  //printout the different ways
  printf("Creating Binary Search Tree\n");
  root = createBST(a,size);
  printf("In-Order traversal: ");
  printInorder(root); 
  printf("\nPre-Order traversal: ");
  printPreorder(root);
  printf("\nPost-Order traversal: ");
  printPostorder(root);

  printf("\n\nMinimum Height BST\n");
  sort(a,size);

  root = createMinBST(a,0,size-1);
  
  printTree(root);

  free(a); //free mem
  return 0;

}

 // creates bst from the array
bst *createBST(int a[], int size){
  int i;
  bst *root = NULL;

  for(i=0;i<size;i++){
    root = insert(root,a[i]);
  }

  return root; 
}

void sort(int a[], int size){
   merge_sort(a,0,size); 
}
 
              
//creates a bst with the minimum height
bst* createMinBST(int a[], int start, int end){
  
 
  if (start > end)
    return NULL;

  int middle = (start+end)/2;
  bst* root = create_node(a[middle]);
  root->left = createMinBST(a, start, middle-1);
  root->right = createMinBST(a, middle + 1, end);

  return root;

}
//merge sort used for sorting the array 
void merge(int array[], int low, int middle, int high){
    int temp[100];
    int lowCurr = low, highCurr = middle + 1, i = 0;


    while (lowCurr <= middle && highCurr <= high) {
        if (array[lowCurr] <= array[highCurr])
            temp[i++] = array[lowCurr++];
        else
            temp[i++] = array[highCurr++];
    }
    while (lowCurr <= middle)
        temp[i++] = array[lowCurr++];

    while (highCurr <= high)
        temp[i++] = array[highCurr++];

    i--;
    while (i >= 0) {
        array[low + i] = temp[i];
        i--;
    }
}

void merge_sort(int array[], int low, int high){
    if (low < high) {
        int middle = (high + low)/2;
        merge_sort(array, low, middle);
        merge_sort(array, middle + 1, high);
        merge(array, low, middle, high);
    }
}
