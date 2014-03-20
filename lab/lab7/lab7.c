//Sam Kreter
//sakfy6
//3-18-14
//STACKITUP
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EQU_LEN 100


//struct for the nodes
typedef struct node_{
  char data;
  struct node_ *next;
}node;

//struct for the stack
typedef struct stack_{
  unsigned int size;
  node* topStack;
}stack;


//fucntion prototypes
stack* create_stack();
void push(stack* s,char val);
char top(stack* s);
void pop(stack* s);
void print_stack(stack* s);
int paren_match(char* equation);
int paren_and_brackets_match(char* equation);

int main(int argc, char* argv[]){
  //test command line arguments
  if(argc != 2){
    printf("insufficent command line arguments");
    exit(0);
  }  

  //open the file
  FILE* input = fopen(argv[1],"r");
  if(input == NULL){
    printf("File not found\n");
    exit(0);
  }

  char equation[MAX_EQU_LEN] = {0}; // initilize the array

  while(fscanf(input,"%s",equation) != EOF){
    printf("For equation %s; %s : %s\n",equation,paren_match(equation)?"Parensmatch":"Parens do not match",paren_and_brackets_match(equation)?"Bonus Brackets match":"Bonus Brackets do not match");
    equation[0] = '\0'; //reset the array
  }
  
  close(input); //close the file
  
  return 0;

}

//creates the stack
stack* create_stack(){
  stack* s = (stack *)malloc(sizeof(stack));
  s->topStack = NULL; //set the top to null
  s->size = 0;

  return s;
}
//add nodes to the stack
void push(stack* s,char val){
  node* n = (node *)malloc(sizeof(node));
  n->data = val;
  s->size++;
  if(s->topStack == NULL){  //check for empty stack
    n->next = NULL;
    s->topStack = n;
  }
  else{
    n->next = s->topStack;
    s->topStack = n;
  }
  
}
//return the top of the stack
char top(stack* s){
  return s->topStack->data;
}

//removes the node on the top of the stack
void pop(stack* s){
  node* temp = NULL;
  if(s->topStack != NULL){
    temp = s->topStack;
    s->topStack = s->topStack->next;
    free(temp);
    s->size--;
  }
  else{
    printf("The stack is empty"); //print if the stack is empty
  }
}
//prints out the stack
void print_stack(stack* s){
  if(s->topStack == NULL){
    printf("Can't print empty stack");
    exit(0);
  }
  node* temp = s->topStack;
  while (temp->next != NULL){
    printf("%c -> ",temp->data);
    temp = temp->next;
  }
  printf("%c -> ",temp->data);
  printf("NULL");
}
//checks if the parenthises match
int paren_match(char* equation){
  stack* s = create_stack();
  int length = strlen(equation),i=0;
  for(i=0;i<length;i++){
    if(*equation == '('){
      push(s,'p');
    }
    else if(*equation == ')'){
      if(s->size != 0){ //make sure not to pop an empty stack
        pop(s);
      }
      else{
        return 0;
      }
    }
    equation++; //encriment the pointer
  }
  if(s->size == 0){
    return 1;
  }
  else{
    return 0;
  }
}
//checks if the brackets and the parenthises match 
int paren_and_brackets_match(char* equation){
  stack* s = create_stack();
  int length = strlen(equation),i=0;
  for(i=0;i<length;i++){
    if(*equation == '('){
      push(s,'(');
    }
    else if(*equation == '['){
      push(s,'[');
    }
    else if(*equation == ')'){
      if(s->size != 0 && top(s) == '('){ //test if it is in the right order and not pop emtpy stack
        pop(s);
      }
      else{
        return 0;
      }
    }
    else if(*equation == ']'){
      if(s->size != 0 && top(s) == '['){ //check if right order and not pop an empty stack
        pop(s);
      }
      else{
        return 0;
      }
    }
    equation++; //incriment the pointer 
  }
  if(s->size == 0){  //make sure the stack is empty and everything matched up 
    return 1;
  }
  else{
    return 0;
  }
  
}



