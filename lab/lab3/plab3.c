#include<stdio.h>
#include<stdlib.h>

typedef struct node_{
  int value;
  struct node_ *next;
}node;

node *insert_top(node* head, int value);
node *delete(node* head, int value);
void print(node* head);


int main(){
  
  int value;
  node *head = NULL;

  printf("Enter a value or -1 to exit: ");
  scanf("%d",&value);

  while(value != -1){
  head = insert_top(head,value);
  print(head);
  printf("Enter a value or -1 to exit: ");
  scanf("%d",&value);
  };

  scanf("%d",&value);

  while(value != -1){
  printf("Enter a value to delete: ");
  scanf("%d",&value);
  head = delete(head, value);
  print(head);
  }


  return 0;

}

node* insert_top(node* head, int value){
  
  node* temp = NULL;
  node *n = (node *)malloc(sizeof(node));

  n->value = value;
  n->next = NULL;

  if(head == NULL){
    head = n;
    return head;
  } 

  n->next = head;
    
  return n;

}

node* delete(node* head, int value){
  
  node *curr = head;
  node *last = NULL;
  
  //edge if list is null
  if(head == NULL){
    printf("Trying to delete empty list");
    return NULL;
  }
  else if(head->value == value){
    head = head->next;
    free(curr);
    return head;
  }

  last = curr;
  curr = curr->next;

  while(curr->next != NULL){
    if(curr->value == value){
      last->next = curr->next;
      free(curr);
      return head;
    }
    else{
      last = curr;
      curr = curr->next;
    }
   
  }
  last->next = NULL;
  free(curr);
  return head;

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


