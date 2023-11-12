#include <stdio.h>
struct stack{
       int pointer;
       char storage[32];
};


void push(char element,struct stack* Stack){
     Stack->storage[(Stack->pointer)++] = element;
}

char pop(struct stack* Stack){
    if(Stack->pointer<0){
       return -1;
    }
    char element = Stack->storage[--(Stack->pointer)];
    return element;
}
