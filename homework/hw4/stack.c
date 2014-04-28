#include <stdlib.h>
#include "stack.h"

/* 
 * Creates an empty stack and sets
 * the size equal to 0
 */

stack* create_stack() {
	stack *s = (stack *)malloc(sizeof(stack));
	s->size = 0;
	s->stack = NULL;
	return s;

}

/*
 * pushes the value into the top of the stack
 */ 
void push(stack *s, int val) {
    node *n = malloc(sizeof(node));
    n->data = val;
    n->next = s->stack;
    s->stack = n;
    s->size++;
}

/*
 * pops the head of the stack
 * the value is not returned
 */
void pop(stack *s) {
	if(s->stack == NULL){
		return;
	}

	
	if(s->stack != NULL){
		node* temp = s->stack;
	
		if(temp->next != NULL){
			s->stack = temp->next;
		}
		else{
			s->stack == NULL;
		}
		free(temp);
	}

}


/*
 * returns the value at the top of the stack
 * the stack remains unchanged
 */
int top(stack *s) {
	return s->stack->data;
}

/*
 * returns 1 if the stack is empty
 * 0 otherwise
 */
int isEmpty(stack *s) {
	if(s->stack == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
