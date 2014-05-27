//Sam Kreter
//sakfy6
//04/29/14
//QUICK_FUNCTION_PTR

#include<stdio.h>
#include<stdlib.h>
#include "header.h"





int main(int argc, char* argv[]){

  FILE* input = fopen("numbers.txt","r");
  if(input == NULL){
    printf("File  %d failed to open", argv[1]);
    return 1;
  }
  FILE* searchFile = fopen("search.txt","r");
  if(input == NULL){
    printf("File %d could not be opened",argv[2]);
    return 1;
  }

 

  int(*compare)(int,int);
  int size = 0, i = 0,choice =0, data = 0;

  fscanf(input,"%d",&size);

  int* arr = malloc(size*sizeof(int));

  for(i=0; i<size; i++){
    fscanf(input,"%d",&arr[i]);
  }
  close(input);
  print(arr, size);
  
  //check for accending or decending   
  printf("Do you want to sort with smaller values on the right(1) or left(2)? ");
  scanf("%d",&choice);
  while(choice != 1 && choice != 2){
    printf("Please enter 1 for smaller values on the right or 2 for smaller values on the left: ");
    scanf("%d",&choice);
  }
 
  //sort the array
  if(choice == 1){
    compare = compareSmallerOnRight;
  }
  else
    compare = compareSmallerOnLeft;

  quick_sort(arr,0,size-1,compare);
  print(arr, size);

  while(fscanf(searchFile,"%d",&data) != EOF){
    if(b_search(arr, data, compare, 0, size)){
      printf("%d was found in the array\n",data);
    }
    else{
      printf("%d was not found in the array\n",data);
    }
  }

  close(searchFile);

  return 0;
}
