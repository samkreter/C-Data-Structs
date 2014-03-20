//Sam Kreter
//sakfy6	
//2-5-14

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct definition
typedef struct node_{
  char *name;
  struct node_* next;
}node;

//function prototypes
node* insert(node* head, char *name);
node* create_node(char *name);
void print(node* head);
void delete(node* head);


int main(int argc, char* argv[]){

  //checking for the correct number of arguments
  if(argc != 2){
    printf("Incorrect Number of Command Line Arguments\nCorrect Usage ./a.out <input file>");
    return 0;
  } 

  //opening the file
  FILE *inFile =fopen(argv[1],"r");
  if(inFile == NULL){
    printf("input file failed to open");
    return 0;
  } 

  int i;
  char *name;
  node *head = NULL; //create the empty list

   //read the file and populate the link list
   while(fscanf(inFile,"%s",name) == 1){
     head = insert(head, name);
  }
  
  close(inFile); //close the file

  print(head); //print out the content of the link list

  delete(head); //delete the list
 
  return 0;

}

//inserts a new node into the list
node* insert(node* head, char *name){
  node *n,*temp = NULL;

  n = create_node(name);
  //checks to see if there is a list already
  if (head == NULL){
      head = n;
      return head;
  }
  
  //find the end of the list to add the node
  temp = head; 
  while (temp->next != NULL){
    temp = temp->next;
  }
  temp->next = n;

  return head;

}


//mallocs the ram for the name and the list
node *create_node(char* name){
  node* new_node = (node *)malloc(sizeof(node));
  if(new_node == NULL){
    printf("malloc failed to create new node\n");
    return NULL;
  }

  new_node->name = (char *)malloc(sizeof(name));
  if(new_node->name == NULL){
    printf("malloc failed to create name");
  }

  strcpy(new_node->name, name); //copy the character string from one set to another
  new_node->next = NULL;

  
  return new_node;
}

void delete(node* head){
  node *temp = head;

  //free each node and name ram space
  while(temp != NULL){
  temp = head->next;
  free(head->name);
  free(head);
  head = temp;
  }
}

//prints out the entire list
void print(node* head){
 
  node *n = NULL;

  n = head;
  while(n != NULL){
    printf("%s -> ",n->name);
    n = n->next;
  }
  printf("NULL\n");
}
