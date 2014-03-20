#include<stdio.h>
#include<stdlib.h>


typedef struct node_{
  int value;
  struct node_ *next;
}node;

node* insert(node* head, int value);
int factorial(int n);
void print(node* head);

int main(){
  int val;
  node* head = NULL;
 
  printf("Please enter a value");
  scanf("%d",&val);

  while(val != -1){
    head = insert(head, factorial(val));
    print(head);
    printf("Please enter a value");
    scanf("%d",&val);
  }

  return 0;

}

node* insert(node* head, int value){
  
  node* temp = head;
  node* prev = head;
  node* n = (node *)malloc(sizeof(node));
 
  if(n == NULL){
    printf("failed to malloc, ending program");
    exit(0);
  }

  n->next = NULL;
  n->value = value;

  if(head == NULL){
    head = n;
    return head;
  }
  
  if(head->next == NULL){
    if(head->value < n->value){
      head->next = n;
      return head;
    }
    else{
      n->next = temp;
      return n;
    }
    
  }
  
  if(temp->value >n->value){
    n->next = temp;
    return n;
  }
 
  temp = temp->next;
  while(temp->next != NULL){
    if(temp->value > n->value){
      prev->next = n;
      n->next = temp;
      return head;
    }
    else{
      prev = temp;
      temp = temp->next;
    }
  }
  
  if(temp->value > n->value){
    prev->next = n;
    n->next = temp;
  }
  else{
    temp->next = n;
  }
  return head;
}

int factorial(int n){
  
  if(n > 1){
    
    return n * factorial(n-1);
  }
  else 
    return n;
}

void print(node* head){
  
  if(head == NULL){
    printf("Trying to print an empty list");
    exit(0);  
  }
  
  node* temp = head;
  
  while(temp->next != NULL){
    printf(" %d ->",temp->value);
    temp = temp->next;
  }
  if(temp->next == NULL){
    printf(" %d ->",temp->value);
  }

  printf(" NULL\n");

}
