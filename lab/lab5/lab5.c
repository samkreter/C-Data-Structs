//Sam Kreter
//sakfy6
//3-4-14
//MARCH4MERGE

#include<stdio.h>
#include<stdlib.h>


//function protoytype
int binary_search(int array[], int key, int low, int high);
int is_sorted(int array[], int length);
void merge_sort(int array[], int low, int high);
void merge(int array[], int low, int middle, int high);
void print(int array[],int length);

int main(int argc, char *argv[]){

  //check command line arguments
  if(argc != 3){
    printf("insufficent command line arguments");
    exit(0);
  }
  
  //open the file and error check it 
  FILE* input = fopen(argv[2],"r");
  if(input == NULL){
    printf("Coulnd not open file");
    exit(0);
  }

  int array[100], length, i, search;
  
  
  search = atoi(argv[1]); //convert the char to an integer
   
  //load the array
  fscanf(input,"%d",&length);
  for(i=0; i<length; i++){
    fscanf(input,"%d",&array[i]);
  }
  
  close(input); //close the file

  //check if the array is sorted
  if(is_sorted(array, length)){
    printf("The array is sorted\n");
  }
  else{
    printf("The array is not sorted\n");
  }
  
  //sort the array
  printf("Calling mergesort\n");
  merge_sort(array,0,length);

  //check if the array is sorted again 
  if(is_sorted(array, length)){
    printf("The array is sorted\n");
  } 
  else{
    printf("The array is not sorted\n");
  }

  //search the array
  if(binary_search(array,search,0,length) != 0){
    printf("%d was found\n",search);
  }
  else{
    printf("%d was not found\n",search);
  }

  //print the array 
  print(array,length);
  
  return 0;

}

int binary_search(int array[], int key, int low, int high){
  
  //if it cycles through the array and the number is not found
  if(high <low){
    return 0;
  }
  int middle = (low + high)/2;
  if(key < array[middle]){ //check if you need to go to the lower half
    return binary_search(array,key,low,middle-1);
  }
  else if(key > array[middle]){ //check if needed to go to higher half
    return binary_search(array, key, middle+1, high);
  }
  else if(key == array[middle]){ //check the last one 
    return middle;
  }
}

int is_sorted(int array[], int length){
  int i;

  //chekc if its in accending order then continue to check 
  if(array[0] <= array[1]){
    for(i=2; i<length; i++){
      if(array[i-1] >= array[i]){
        return 0;
      }
    }
  }
  //check if it is in desending order the continue to check 
  else if(array[0] >= array[1]){
    for(i=2; i<length; i++){
      if(array[i-1] <= array[i]){
        return 0;
      }
    }
  }
  else{
    return 0;
  }
  return 1;

}

void merge(int array[], int low, int middle, int high)
{
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

void merge_sort(int array[], int low, int high)
{
    if (low < high) {
        int middle = (high + low)/2;
        merge_sort(array, low, middle); 
        merge_sort(array, middle + 1, high); 
        merge(array, low, middle, high); 
    }
}

//simply print out the array 
void print(int array[],int length){
  int i = 0;
  printf("The sorted array\n");
  for(i=0; i<length; i++){
    printf("%d\n",array[i]);
  }

}

