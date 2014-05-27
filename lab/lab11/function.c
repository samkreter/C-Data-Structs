#include<stdio.h>
#include<stdlib.h>
#include"header.h"




int compareSmallerOnLeft(int num1, int num2){
  if(num1 > num2){
    return -1;
  }
  else if(num1 < num2){
    return 1;
  }
  else
    return 0;
}
int compareSmallerOnRight(int num1, int num2){
  if(num1 > num2){
    return 1;
  }
  else if(num1 < num2){
    return -1;
  }
  else 
    return 0;
}




int b_search(int *arr, int data,int(*compare)(int,int), int start, int end){

  if(end <start){
    return 0;
  }
 
  int middle = (start + end)/2;
  int comp = compare(data,arr[middle]);
 
  if(comp){
    return b_search(arr,data,compare,start,middle-1);
  }
  else if(comp == -1){
    return b_search(arr, data,compare, middle+1, end);
  }
  else if(!comp){
    return middle;
  }
}



void print(int* arr, int length){

  int i = 0;

  for(i=0; i<length; i++){
    printf("%d ",arr[i]);
  }

  printf("\n");
}




void quick_sort(int* arr, int start, int end, int(*compare)(int,int))
{
    if(start < end) {
        int middle = partition(arr, start, end,compare);
        quick_sort(arr, start, middle-1,compare);
        quick_sort(arr, middle+1, end,compare);
    }
}



int partition(int* arr, int start, int end,int(*compare)(int,int)){
    
  int pivotIdx = start + rand() % (end-start+1);
  int pivot = arr[pivotIdx], temp = 0;
  
  //swap the elements
  temp = arr[end];
  arr[end] = arr[pivotIdx];
  arr[pivotIdx] = temp;


  pivotIdx = end;
  int i = start -1, j = start;

  int compareV = 0;
 
  pivotIdx = end;
  for(j=start; j<=end-1; j++){
    compareV = compare(arr[j],pivot);
    if(compareV == 1 || compareV == 0){//<=
      i++;
      //swap elements
      temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
    }
  }
 
  //swap elements
  temp = arr[pivotIdx];
  arr[pivotIdx] = arr[i+1];
  arr[i+1] = temp;
  
  return i+1;
}


