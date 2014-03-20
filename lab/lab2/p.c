#include<stdio.h>
#include<stdlib.h>

typedef struct node_{
  int value;
  struct node_* next;
}node;


node* insert(node* head, int value);
void print(node* head);


int main(int argc, char* argv[]){

  int value = 0;
  node *first = NULL;
 
  printf("Enter a value or -1 to quite: ");
  scanf("%d",&value);
  first = insert(first, value);  

  while(value != -1){
    printf("Enter another value");
    scanf("%d",&value);
    first = insert(first, value);
  }  

  print(first);

  return 0;

}

node* insert(node* head, int value){
  node *n,*temp = NULL;

  n =(node*)malloc(sizeof(node));
  if(n == NULL){
    printf("Failed to malloc");
  }
  n->value = value;

  printf("n->value = %d\n",n->value);
  n->next = NULL;

  if (head == NULL){
      head = n;
      return head;
  }
 
  temp = head; 
  while (temp->next != NULL){
    temp = temp->next;
  }
  temp->next = n;
  return head;

}

void print(node* head){
 
  node *n;
  int i=1;

  n = head;
  while(n != NULL){
    printf("vlaue is %d\n",n->value);
    n = n->next;
  }
}
