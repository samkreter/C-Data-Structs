//Sam Kreter
//sakfy6
//3-11-2014
//easy lab

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 
#define SIZE 10

// list struct
typedef struct node_{
  int value;
  struct node_* next;
}Node;


//fucntion prototypes
void free_node(Node* head);
Node* create_node(int data);
void print_list(Node* head);
void print_array(int a[]);
int linearSearch(int array[], int length, int key);
int nodeSearch(Node* head, int key);
Node* insert_end(Node* head, int data);


int main(int argc, char* argv[]){

   // varible declarations
  int i=0,j=0,length=0,*array=NULL, temp=0,key=0,found=0;
  double arrayTime, nodeTime;
  Node* head=NULL;
  clock_t start,end;
  
  key = atoi(argv[1]);// change string to integer
  printf("%-15s%-15s\n","Linear search","Node Search");
 
  //loop for all the argumens
  for(i=2; i<argc; i++){
    FILE* input = fopen(argv[i],"r");
    if(input == NULL){
      printf("Unable to open %s\n",argv[i]);
    }

    else{
      fscanf(input,"%d",&length);
      array = (int *)malloc(length*sizeof(int));
      for(j=0;j<length;j++){
        fscanf(input,"%d",&temp);
        array[j] = temp;
        head = insert_end(head, temp);
      }
      //timing the algorith
      start = clock();
      found = linearSearch(array,length,key);
      end = clock();
      arrayTime = (double)(end-start)/CLOCKS_PER_SEC;
      //check if the search was found 
      if(found == 0){
        printf("number not found in linear search\n");
      }
      start = clock();
      found = nodeSearch(head, key);
      end = clock();
      nodeTime = (double)(end-start)/CLOCKS_PER_SEC;
      if(found == 0){
        printf("number not found in node search\n");
      }
      
    
      printf("%-15lf%-15lf\n",arrayTime,nodeTime);
      //free the malloced memory 
      free(array);
      free_node(head);
      head = NULL;
    }
    close(input);//close the input file
  }
 

}

//frees the linked list
void free_node(Node* head){
  if(head == NULL){
    return;
  }
  else{
    free_node(head->next);
    free(head);
  }
}

//recursivly searches the node
int nodeSearch(Node* head, int key){
  if(head == NULL){
    return 0;
  }
  else if(head->value == key){
    return 1;
  }
  else{
    return nodeSearch(head->next, key);
  }
}

//creates a new node
Node* create_node(int data){
  Node* n = (Node *)malloc(sizeof(Node));
  if(n == NULL){
    printf("Failed malloc");
    exit(0);
  }
  n->next = NULL;
  n->value = data;

  return n;
}

//performs a linear search on an array
int linearSearch(int array[], int length, int key){
  int i = 0;
  for(i=0; i<length; i++){
    if(key == array[i]){
      return 1;
    }
  }
  return 0;
}

//recusivly inserts a node at the end of a list
Node* insert_end(Node* head,int data){
    
    if(head == NULL){
      head = create_node(data);
    }
    else{
     head->next = insert_end(head->next,data);
    }
    return head;
}
//prints the lsit
void print_list(Node* head){
  if(head == NULL){
    printf("Can't print an empty list");
    exit(0);
  }
  
  Node* temp = head;
  printf("Linked LIst:\n");
  while(temp->next != NULL){
    printf("%d\n",temp->value);
    temp = temp->next;
  }
  printf("%d\n\n",temp->value);
  
}
//prints the array 
void print_array(int a[]){
  int i=0;

  printf("Array:\n");
  for(i=0; i<SIZE; i++){
    printf("%d\n",a[i]);
  }
}
