#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stack.h"

char* infix_to_postfix(char* equ);
int evaluate_postfix(char* equ);
char numTochar(int num);
int eval(int val1, int val2, char op);

#endif
