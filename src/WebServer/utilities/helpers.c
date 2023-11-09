#include <stdlib.h>
#include <string.h>
#include "stack.c"
char* itos(int number){
      struct stack Stack;
      while(number!=0){
         int popedVal = number%10;
         push(popedVal-'0',Stack);
      }
      char *result = malloc(sizeof(char)*32);
      char element;
      int index = 0;
      while((element = pop(Stack))>0){
          result[index++] = element;
      }
      return result;
}
