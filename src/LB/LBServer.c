#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include "../WebServer/headers/server.h"
struct server initLBServer(){
     struct server Server;
     int socketFD = socket(AF_INET,SOCK_STREAM,0);
     if(socketFD<0){
        printf("Socket allocation failed\n");
        exit(0);
     }
     struct sockaddr_in address;
     address.sin_family = AF_INET;
     address.sin_addr.s_addr = INADDR_ANY;
     address.sin_port = htons(3000);
     Server.port = 3000;
     Server.socket = socketFD;
     Server.address = address;
     if(bind(socketFD,(struct sockaddr*)&address,sizeof(address))){
         printf("Binding failed\n");
         exit(0);
     }
     if(listen(socketFD,1000)){
        printf("Listening failed\n");
        exit(0);
     }
     return Server;
}



void serverListen(struct server Server,void (*handler)()){
     struct sockaddr_in address = Server.address;
     socklen_t addrlen = sizeof(address);
     if(listen(Server.socket,1000)<0){
        printf("Listening failed\n");
        exit(0);
     }
     printf("LB Listening on port 3000\n");
     while(1){
       int clientFD = accept(Server.socket,(struct sockaddr*)&address,&addrlen);
       (*handler)();
     }
}
