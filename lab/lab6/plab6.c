#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

typedef struct node_{
  int value;
  struct node_* next;
}Node;


Node* insertnode(Node* head, int value);
void print_list(Node* head);
void print_array(int a[]);

int main(){

  srand(time(NULL));
  int a[SIZE] = {0}, i=0;
  Node* head = NULL;
  
  for(i=0;i<SIZE;i++){
    a[i] = rand()%10;
  }

  for(i=0;i<SIZE;i++){
    head = insertnode(head,rand()%10);
  }

  print_array(a);
  print_list(head);
  
  return 0;

}

Node* insertnode(Node* head,int value){
  Node* n = (Node *)malloc(sizeof(Node));
  if(n == NULL){
    printf("Failed malloc");
    exit(0);
  }

  n->value = value;
  n->next = NULL;
  
  if(head == NULL){
    head = n;
    return head;
  }
  else{
    n->next = head;
    return n;
  }
}

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

void print_array(int a[]){
  int i=0;

  printf("Array:\n");
  for(i=0; i<SIZE; i++){
    printf("%d\n",a[i]);
  }
}
