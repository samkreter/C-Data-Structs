#include<stdio.h>
#include<stdlib.h>

typedef struct node_{
  char data;
  struct node_ *next;
}node;

typedef struct stack_{
  unsigned int size;
  node* stack;
}stack;

stack* create_stack();
void push(stack* s,char val);
char top(stack* s);
void pop(stack* s);
void print_stack(stack* s);


int main(){
  stack* s = NULL;
  int i=0;
  s = create_stack();
  for(i=0;i<4;i++){
    push(s,i+97);
  }

  print_stack(s);
  
  pop(s);
  print_stack(s);
  pop(s);
  print_stack(s);  

  return 0;

}

stack* create_stack(){
  stack* s = (stack *)malloc(sizeof(stack));
  s->stack = NULL;
  s->size = 0;

  return s;
}

void push(stack* s,char val){
  node* n = (node *)malloc(sizeof(node));
  n->data = val;
  s->size++;
  if(s->stack == NULL){
    n->next = NULL;
    s->stack = n;
  }
  else{
    n->next = s->stack;
    s->stack = n;
  }
  
}

char top(stack* s){
  return s->stack->data;
}

void pop(stack* s){
  node* temp = NULL;
  if(s->stack != NULL){
    temp = s->stack;
    s->stack = s->stack->next;
    free(temp);
    s->size--;
  }
  else{
    printf("The stack is empty");
  }
}

void print_stack(stack* s){
  if(s->stack == NULL){
    printf("Can't print empty stack");
    exit(0);
  }
  node* temp = s->stack;
  while (temp->next != NULL){
    printf("%c -> ",temp->data);
    temp = temp->next;
  }
  printf("%c -> ",temp->data);
  printf("NULL");
}

