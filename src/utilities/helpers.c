#include <stdlib.h>
#include <string.h>
#include "stack.c"

char* itos(int number){
      struct stack* Stack = (struct stack*)malloc(sizeof(struct stack));
      while(number!=0){
         int popedVal = number%10;
         number = number/10;
         push(popedVal+'0',Stack);
      }
      char *result = malloc(sizeof(char)*32);
      char element;
      int index = 0;
      while((element = pop(Stack))>0){
          result[index++] = element;
      }
      return result;
}
