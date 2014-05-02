#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

#define MAX_EQU_LEN 100

/*
 * Returns a number corresponding the the preccedence 
 * of different arithmetic operators. * has a higher 
 * precedence that / which is greater than %, +, -
 * in that order. Higher precedence should return a higher
 * number so say 5 for * 1 for - and 0 for a non operator
 */
static char prec(char operator) {
	
	switch(operator){
		case '*':
			return 5;
		case '/':
			return 4;
		case '%':
			return 3;
		case '+':
			return 2;
		case '-':
			return 1;
		case ')':
			return -1;
		case '(':
			return -2;
		default: 
			return 0;
	}
}

/*
 * Returns 1 if the string passed is an inteter
 * 0 otherwise
 */
static int isNumeric(char *num) {

	char* end;

	if(!strtol(num,&end,10)){
		return 0;
	}
	else{
		return 1;
	}

}

char numTochar(int num){
	
	switch(num){
		case 5:
			return '*';
		case 4:
			return '/';
		case 3:
			return '%';
		case 2:
			return '+';
		case 1:
			return '-';
		case -1:
			return ')';
		case -2: 
			return '(';
		default:
			printf("bad in numTochar");
	}	
}

int eval(int val1, int val2, char op){
	switch(op){
		case '*':
			return val2 * val1;
		case '/':
			return val2 / val1;
		case '%':
			return val2 % val1;
		case '+':
			return val2 + val1;
		case '-':
			return val2 - val1;
		default:
			printf("something bad in eval %c is the ",op);
			return 0;
	}
}


/*
 * converts a valid infix expression into postfix
 * Hint put a space between numbers and operators 
 * so you can use strtok in evaluate_postfix
 * ex: get 7 8 + vs 78+
 *
 * This is done with the following algorithm
 *
 * for each token in the string
 *     if the next token is a number
 *         append it to the postfix string
 *     else if the next token is a left paren
 *          push it onto the stack
 *     else if the next token is a right paren
 *          while the stack is not empty and the left paren is not at the top of the stack
 *              pop the next operator off of the stack
 *              append it to the postfix string
 *          pop the left paren off of the stack and discard it
 *     else if the next token is an operator (+, -, *, /)
 *         while the stack is not empty and the operator at the top of the stack has a higher precedence than the token
 *              pop the top element off of the stack and append it to the postfix string
 *         push the current token onto the stack
 *
 * while there are elements remaining on the stack
 *     pop the top element off of the stack and append it to the postfix string
 */
char* infix_to_postfix(char* infix) {
	char toke = '\0';
	int i = 0, length = strlen(infix), value = 0, operate = 0;
	char* postfix = malloc(sizeof(char)*length);
	char* holder = postfix;
	char* tokeptr = &toke;
	stack* s = create_stack();

	for(i=0; i<length; i++){
		toke = infix[i];
		if(toke == ' '){

		}
		else if(isNumeric(tokeptr)){
			*postfix = toke;
			postfix++;
		}
		else if(toke == '('){
			value = prec(toke);
			push(s, value);
		}
		else if(toke == ')'){
			while(s->stack != NULL && s->stack->data != -2){
				toke = numTochar(top(s));
				*postfix = toke;
				postfix++;
				pop(s);
			}
			pop(s);
		}
		else{
			operate = prec(toke);
			while(s->stack != NULL && top(s) > operate){
				toke = numTochar(top(s));
				*postfix = toke;
				postfix++;
				pop(s);
			} 
			push(s, operate);

			
		}
		
	}
	while(s->size != 0){
			*postfix = numTochar(top(s));
			postfix++;
			pop(s);
	}
	free(s);
	return holder;

}

/*
 * This function takes in a valid postfix expression
 * and evaluate it to an integer
 *
 * for each token in the string
 *      if the token is numeric
 *          convert it to an integer
 *          push it onto the stack
 *      else
 *          pop the top 2 element off of the stack
 *          the first goes into the right variable
 *          the second goes into the left variable
 *          apply the operation: 
 *              result = left op right
 *              ex result = left + right
 *
 *          push the result onto the stack
 *          
 * return the rsult from the stack
 */

int evaluate_postfix(char* postfix) {
	int i = 0,val1 = 0,val2 = 0;
	char toke = '\0';
	char *tokeptr = &toke, *end = NULL;
	stack* s = create_stack();
	for(i=0;i<strlen(postfix);i++){
		*tokeptr = postfix[i];
		if(isNumeric(tokeptr)){
			push(s,strtol(tokeptr,&end,10));
		}
		else{
			val1 = top(s);
			pop(s);
			val2 = top(s);
			pop(s);
			push(s,eval(val1, val2,*tokeptr));
		}
	}
	return top(s);
}



