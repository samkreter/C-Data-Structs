//Sam Kreter
//sakfy6
//02=18-14
//SICKTA

#include<stdio.h>
#include<stdlib.h>

//define the struct for list
typedef struct node{
  int value;
  struct node* next;
}Node;


//function prototypes
Node* insert_end(Node* head, int value);
void print(Node* head);
int search(Node* head, int data);
void factorial_list(Node* head);
void delete_list(Node* head);
int factorial(int n);

int main(int argc, char* argv[]){
  
  //test for the proper number of command line arguments
  if(argc != 2){
    printf("incorrect number of command line arguments, please try again!");
    return 0;
  }
  
  //open the inputfile for the list
  FILE *input = fopen(argv[1],"r");
  if(input == NULL){ //test if the file was opened
    printf("Unable to open file!");
    return 0;
  }

  Node* head = NULL;  //create an empty list
  int data;
  
  //populate the list
  while(fscanf(input,"%d",&data) != EOF){
    head = insert_end(head,data);
  }
  print(head);
  //get a number from the user to search
  printf("Please enter a number to search for: ");
  scanf("%d",&data); 

  //test the search results
  if(search(head, data)){
    printf("%d was found!\n");
  } 
  else{
    printf("%d was NOT found!\n");
  }
 
  factorial_list(head);//find the factorial of all the list
  print(head);

  delete_list(head); //recursivly delte the list
  
  close(input);//close the file 
 
  return 0;
}



Node* insert_end(Node* head, int value){
  
  //base case for the recursive call
  if(head == NULL){
    Node* n = (Node *)malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    head = n;  
  }
  else{
    head->next = insert_end(head->next,value); //recusive call
  }
  return head;
}

void print(Node* head){
  //base case for the recursive call
  if(head == NULL){
    printf("NULL\n");
    return;
  }
  else{
    printf("%d -> ",head->value);
    print(head->next);//recusive call
  }
}

int search(Node* head, int data){
  if(head != NULL){
    if(head->value == data){
      return 1;
    }
    //base case for the recursive call
    else{
      return search(head->next, data);//recusive call
    }
  }
  else{
    return 0;
  }
}

int factorial(int n){
  if(n <= 1){
    return n;
  }
  else{
    return n * factorial(n-1);//recusive call
  }
}

void factorial_list(Node* head){
  //base case for the recursive call
  if(head == NULL){
    return;
  }
  else{
    head->value = factorial(head->value);
    factorial_list(head->next);//recusive call
  }
  return;
}

void delete_list(Node* head){
  //base case for the recursive call 
  if(head == NULL){
    return;
  }
  else{
    delete_list(head->next);//recusive call
    free(head);
  }
  return;
}



