#include <stdlib.h>
#include "LB.h"
#include <unistd.h>
#include <stdio.h>
#include "../utilities/helpers.c"

struct Server availableServer;
void assignRequest(){
}

void forkServer(int port){
     pid_t pid = fork();
     if(pid==0){
        char *myargs[3];
        myargs[0] = "../WebServer/app";
        myargs[1] = itos(port);
        myargs[2] = NULL;
        execvp(myargs[0],myargs);
     }
}


void buildLB(int servers){
     struct Server* previous = NULL;
     int port = 8000;
     for(int i=0;i<servers;i++){
         struct Server* server = (struct Server*)malloc(sizeof(struct Server));
         server->port = port;
         server->address = "127.0.0.1";
         if(previous!=NULL){
           previous->next = server;
         }
         previous = server;
         forkServer(port++);
     }
}


void main(){
   buildLB(5);
}
