#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"
int getSocketFD(){
     return socket(AF_INET,SOCK_STREAM,0);
}



struct server initServer(int port){
    int socketFD = getSocketFD();
    if(socketFD<0){
       printf("Socket Allocation failed\n");
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(socketFD,(struct sockaddr*)&addr,sizeof(addr))<0){
      printf("Bind failed\n");
    }
    struct server newServer;
    newServer.port = port;
    newServer.address = addr;
    newServer.socket = socketFD;
    return newServer;
}


void serverListen(struct server newServer){
    if(listen(newServer.socket,1000)<0){
       printf("CServer listening failed\n");
       return;
    }
    printf("CServer listening on %i port\n",newServer.port);
    while(1){
 //      int clientFD = accept();
    }
}

