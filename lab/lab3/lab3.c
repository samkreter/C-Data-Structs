//Sam Kreter
//sakfy6
//02-11-14
//LLIST211

#include<stdio.h>
#include<stdlib.h>

//struct node for the list
typedef struct node_{
  int value;
  struct node_ *next;
}node;

//function prototypes
node *insert(node* head, int value);
node *delete(node* head, int value);
void mul_even(node* head, int multiplier);
void print(node* head);
node* reverse(node* head);


int main(int argc, char* argv[]){

  //test for the number of arguments pasted by user
  if(argc != 2){
    printf("Incorrect number of command line arguments\nCorrect Ussage ./a.out <input file>\n");
  }
 
  //open and check if file could be opened
  FILE *input = fopen(argv[1],"r");
  if(input == NULL){
    printf("Unable to open file bad_input.txt");
    return 0;
  }  

  int value;
  char c;
  node *head = NULL; //create an empty list
  
  //read in the contents of the file and send to the correct function
  while(fscanf(input,"%c%d",&c,&value) != EOF){
    if(c == 'i'){
      printf("Inserting %d into the list\n",value);
      head = insert(head, value);
      print(head);
    }
    else if(c == 'd'){
      printf("Deleting %d from the list\n",value);
      head = delete(head, value);
      print(head);
    }
    else if(c == 'm'){
      printf("Multiplying all even numbers by %d\n",value);
      mul_even(head, value);
      print(head);
    }
  }

  
  
  close(input); //close the file

  printf("Bonus: The list has been reversed\n");
  head = reverse(head); // use bonus function to reverse list
  print(head); 

  return 0;

}

node* insert(node* head, int value){
  
  node* temp = NULL;
  node *n = (node *)malloc(sizeof(node)); //malloc mem for node

  //set up the node 
  n->value = value;
  n->next = NULL;

  //test for edge case with empty list
  if(head == NULL){
    head = n;
    return head;
  }

  //see if even to add to front of list or odd addd to end 
  if(value % 2 == 0){
    n->next = head;
    return n;
  }
  else{
    temp = head;
    while(temp->next  != NULL){
      temp = temp->next;
    }
    temp->next = n;
    return head;
  }

}

node* delete(node* head, int value){
  
  node *curr = head;
  node *last = NULL;
  
  //edge if list is null
  if(head == NULL){
    printf("Trying to delete empty list");
    return NULL;
  }
  else if(head->value == value){ //test if need to delete the first node in the list
    head = head->next;
    free(curr);//free malloc memory
    return head;
  }

  last = curr;
  curr = curr->next;

  while(curr->next != NULL){
    if(curr->value == value){
      last->next = curr->next;
      free(curr); //free malloc memory 
      return head;
    }
    else{
      last = curr;
      curr = curr->next;
    }
   
  }
  if(curr->value == value){
    last->next = NULL;
    free(curr);
  }
  return head;

}

void mul_even(node* head, int multiplier){
  node* temp = head;

  //search for the even values then multiply them by the value
  while(temp->next != NULL){
    if(temp->value % 2 == 0){
      temp->value = temp->value * multiplier;
    }
    temp = temp->next;
  }
}

void print(node* head){

  node *temp = head;
  
  //edge case for empty list
  if(head == NULL){
    printf("List is empty");
    exit(0);
  }

  //edge case of first time entry to print
  if(head->next == NULL){
    printf(" %d ->",head->value);
  }
  else{
  while(temp->next != NULL){
    printf(" %d ->",temp->value);
    temp = temp->next;
  }
  printf(" %d ->",temp->value);
  }
  printf(" NULL\n");
  

}

node* reverse(node* head){
  node* prev = NULL;
  node* curr = NULL;
  node* holder = NULL;

  if(head != NULL){  //test if its an empty list
    prev = head;
    if(prev->next != NULL){ //test if theres only one node
      curr = prev->next;
      if(curr->next !=NULL){ 
        holder = curr->next;
        prev->next = NULL;
        curr->next = prev;
        prev = curr;
        curr = holder;
        while(curr->next != NULL){
          holder = curr->next;
          curr->next = prev;
          prev = curr;
          curr = holder;
        }
      curr->next = prev;
      return curr;
      }  
      else{
        prev->next = NULL;
        curr->next = prev; 
        return curr;
      }
    }
    else{
      return head;
    }
  }
  else{
    printf("Cannot revese an empty list");
    return NULL;
  }

  
}

