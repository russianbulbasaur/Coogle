#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "server/server.c"
#include "server/routes.c"
#include <unistd.h>
#include <string.h>
#define HTTP_HEADER "HTTP/1.1 200 OK\nServer: Coogle:0.0.0\nContent-Type: text/html\nConnection: close\n"
void handler(){
}


void newClientHandler(int clientFD){
    printf("New Connection : %i\n",clientFD);
    char message[300] = HTTP_HEADER;
    strcat(message,"Content-Length: 15\n\n");
    strcat(message,"123456789012345");
    send(clientFD,message,strlen(message),0);
    close(clientFD);
}


void main(){
     struct server newServer = initServer(8000);
     addRoute("/",&handler);
     addRoute("/home",&handler);
     addRoute("/youtube",&handler);
     serverListen(newServer,&newClientHandler);
}


