/* This lab involves building a RPN calculator similar to the one in the text given on pages 75-77. You will use a somewhat different structure for the code. That being said, reviewing the material on RPN calculators given in the text will be useful.
The files associated with this lab should be downloaded to your account and compiled. The Makefile should build the library as well as lexTester. This tests the lexical analyzer given in class. There is also a tokenStack implementation provided.
Q1. Implement popInt and pushInt following the template given in rpnCalc.c popInt should take the stack and pop the top element off of the stack, returning its int value. If this cannot be done, your program should print an error message end quit. pushInt should take an int, create a lexToken that holds a LEX_TOKEN_NUMBER and push that on the stack.
Q2. Implement the RPN calculator using the popInt, pushInt and doOperator functions. Your code should continue to read tokens from the input (see lexical.c for code to read tokens). Given a token your code should

For tokens of type LEX_TOKEN_EOF your code should quit
For tokens of type LEX_TOKEN_IDENTIFIER your code should call doOperator
For tokens of type LEX_TOKEN_NUMBER your code should push the token on the stack
For tokens of type LEX_TOKEN_OPERATOR your code should pop the top two elements off of the stack (you can assume that they will be of type LEX_TOKEN_NUMBER), Perform the corresponding integer operation of the top two elements and push the corresponding result on the stack. (You may find your solution to Q1 helpful here.). Note: if the top stack element was 1 and the element below it was 2, then your code should push 1 on the stack, not -1.

Be very careful to properly delete (free) tokens once you have no further use for them. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexical.h"
#include "nextInputChar.h"
#include "tokenStack.h"

int pop;
struct tokenStack *s;
struct lexToken *tok, *t, * push;
int rpn;
static int popInt(struct tokenStack *s)
{
  if (emptyTokenStack(s))
  {
  exit(1);
  }
  pop = atoi(popTokenStack(s)->symbol);
  return pop;
}
static void pushInt(struct tokenStack *s, int v)
{
  /* puts an int into the stack */
  push = allocToken();
  push->kind = LEX_TOKEN_NUMBER;
  sprintf(push->symbol, "%d", v);
  pushTokenStack(s, push);
}
static void doOperator(struct tokenStack *s, char *op)
{
  if(!strcmp(op,"quit"))
  {
    exit(0);
  } 
  else if(!strcmp(op,"print"))
  {
    t = popTokenStack(s);
    dumpToken(stdout, t);
    freeToken(t);
  }
  else 
  {
    fprintf(stderr,"don’t know |%s|\n", op);
    exit(1);
  }
}

int main(int argc, char *argv[])
{
  setFile(stdin);
  s = createTokenStack();
  tok = nextToken();
  while(tok->kind != LEX_TOKEN_EOF) {
  if(tok->kind == LEX_TOKEN_NUMBER)
  {
    pushInt(s, atoi(tok->symbol));
  }
  if(tok->kind == LEX_TOKEN_OPERATOR)
  {
    int element1 = popInt(s);
    int element2 = popInt(s);
    if(strcmp(tok->symbol, "+") == 0)
    {
      rpn = element2 + element1;
    }
  else if(strcmp(tok->symbol, "-") == 0)
  {
    rpn = element2-element1;
  }
  else if(strcmp(tok->symbol, "/") == 0)
  {
  rpn = element2 / element1;
  }
  else if(strcmp(tok->symbol, "*") == 0)
  {
    rpn = element2 * element1;
  }
    pushInt(s, rpn);
  }
  if(tok->kind == LEX_TOKEN_IDENTIFIER)
  {
    if(s->top == 1 || strcmp(tok->symbol, "quit") == 0)
    {
      doOperator(s, tok->symbol);
    }
  else
  {
    exit(1);
  }
  }
   tok = nextToken();
  }
  return 0;
}
