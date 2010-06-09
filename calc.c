#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

bool popE(stack *s, T *item); // Prototype

int main()
{
  printf("Reverse Polish Notation Calculator v0.1 by dom96\n\n");
  while (1)
  {
    /* Every time a new calculation is executed, a new stack is created. */
    stack *dataStack = new();
  
    char input[1024];
    gets(input);

    /* Loop through the whole string */
    int i;
    for( i = 0; i < strlen(input); i++ )
    {
      /* If this character is a digit, push it on the stack */
      if (isdigit(input[i]))
      {
        push(dataStack, atoi(&input[i]));
      }
      else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
      {
        //printf("Received, operator: %c\n", input[i]);
        T first;
        T second;
        if (popE(dataStack, &first) && popE(dataStack, &second))
        {
          switch(input[i])
          {
            case '+':
            {
              printf("== %i\n", first + second);
              break;
            }
            case '-':
            {
              printf("== %i\n", first - second);
              break;
            }
            case '*':
            {
              printf("== %i\n", first * second);
              break;
            }
            case '/':
            {
              printf("== %i\n", (int) first / second);
              break;
            }
          }
        }
        else
        {
          printf("Error: Not enough values in the stack.\n");
        }
      }
      else
      {
        if (input[i] != ' ')
        {
          printf("Unsupported operator: %c\n", input[i]);
        }
      }
    }
  }
}

bool popE(stack *s, T *item)
/* Pops a value from the stack and sets item to the value popped. Returns False if that failed and true if it didn't. */
{
  if (!empty(s))
  {
    *item = pop(s);
    return true;
  }
  else
  {
    return false;
  }
}

