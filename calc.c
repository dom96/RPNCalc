#include <stdio.h>

int main()
{
  printf("Reverse Polish Notation Calculator v0.1 by dom96\n\n");
  while (1)
  {
    
    /* Get two INT's */
    int first, second;
    if(scanf("%i", &first) == 1 && scanf("%i", &second))
    {
      /* Get the operator */
      char op[2];
      if(scanf("%1s", op) == 1)
      {
        switch(op[0])
        {
          case '+': printf("== %i\n", first + second); break;
          case '-': printf("== %i\n", first - second); break;
          case '*': printf("== %i\n", first * second); break;
          case '/': printf("== %i\n", first / second); break;
          default: printf("Error: Invalid operator.\n");
        }
      }
      else
      {
        printf("Error: Invalid operator.\n");
      }
    }
    else
    {
      printf("Error: Number expected.\n");
      break;
    }
  }
}


 
