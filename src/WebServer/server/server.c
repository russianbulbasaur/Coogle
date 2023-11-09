#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../headers/server.h"
#include "../utilities/helpers.c"
int getSocketFD(){
     return socket(AF_INET,SOCK_STREAM,0);
}



struct server initServer(int port){
    int socketFD = getSocketFD();
    if(socketFD<0){
       printf("Socket Allocation failed\n");
    }
    struct linger so_linger;
    so_linger.l_onoff = 1;
    so_linger.l_linger = 30;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    socklen_t len = sizeof(addr);
    if(setsockopt(socketFD,SOL_SOCKET,SO_LINGER,&so_linger,sizeof(so_linger))){
      printf("Options failed\n");
    }
    if(bind(socketFD,(struct sockaddr*)&addr,sizeof(addr))<0){
      printf("Bind failed\n");
    }
    struct server newServer;
    newServer.port = port;
    newServer.address = addr;
    newServer.socket = socketFD;
    return newServer;
}


void serverListen(struct server newServer,void (*newUserHandler)(int)){
    if(listen(newServer.socket,1000)<0){
       printf("CServer listening failed\n");
       return;
    }
    socklen_t len = sizeof(newServer);
    struct sockaddr_in address = newServer.address;
    printf("CServer listening on %i port\n",newServer.port);
    while(1){
       int clientFD = accept(newServer.socket,(struct sockaddr*)&address,
                             &len);
       (*newUserHandler)(clientFD);
    }
}

char* formHTTPResponse(char* message,int length){
      char content[100+200] = "Content-Length: ";
      char lengthString[100];
      strcat(content,itos(length));
      strcat(content,"\n");
      strcat(content,message);
}


