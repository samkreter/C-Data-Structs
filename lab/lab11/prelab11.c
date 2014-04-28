#include <stdio.h>
#include <stdlib.h>



void quick_sort(int* arr, int start, int end);
int  partition(int* arr, int start, int end);

int main(int argc, char* argv[]){

	FILE* input = fopen("input.txt","r");
	if(input == NULL){
		printf("File failed to open");
		return 0;
	}

	int size = 0, i = 0;

	fscanf(input,"%d",&size);

	int* arr = malloc(size*sizeof(int));

	for(i=0; i<size; i++){
		fscanf(input,"%d",&arr[i]);
	}

	quick_sort(arr,0,size-1);

	for(i=0; i<size; i++){
		printf("%d ",arr[i]);
	}

	return 0;
}

void quick_sort( int arr[], int start, int end)
{
   int part;

   if( start < end ) 
   {
   	// divide and conquer
        part = partition( arr, start, end);
       quick_sort( arr, start, part-1);
       quick_sort( arr, part+1, end);
   }
	
}



int partition( int arr[], int start, int end) {
   int pivot, i, j, t;
   pivot = arr[start];
   i = start; j = end+1;
		
   while( 1)
   {
   	do ++i; while( arr[i] <= pivot && i <= end );
   	do --j; while( arr[j] > pivot );
   	if( i >= j ) break;
   	t = arr[i]; arr[i] = arr[j]; arr[j] = t;
   }
   t = arr[start]; arr[start] = arr[j]; arr[j] = t;
   return j;
}



