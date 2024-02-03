//Just a http server
#include "../../utilities/hashmap.h"
#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "glb.h"
//File descriptor
int getFD(int,char*,char*,int);

//route addition
int addRoute(char*,void*);

//Incase of heavy traffic
void forkThread();

//handler for connection
void handler(int);

//routes registrar
void registerRoutes();


int main(int argc,char* argv[]){
   socklen_t addrLen;
   struct sockaddr_in* clientAddr;
   int clientSocket = 0;
   if(argc<2){
      printf("Enter address and port to bind to.\n");
      return -1;
   }
   int fd = 0;
   if((fd = getFD(AF_INET6,argv[1],argv[2],SOCK_STREAM))<0){
      printf("FD error : %s\n",strerror(errno));
      return -1;
   }
   if(listen(fd,5)<0){
      printf("Listening error\n");
      return -1;
   }
   printf("Here is your FD : %i\n",fd);
   registerRoutes();
   while(1){
      if((clientSocket = accept(fd,(struct sockaddr*)clientAddr,&addrLen))<0){
        printf("Accept error\n");
        return -1;
      }
      handler(clientSocket);
   }
}


void handler(int socket){
   char mess[100] = "1000\n";
   while(1){
      if(send(socket,&mess,10,MSG_NOSIGNAL)<0){
         printf("Connection closed\n");
         return;
      }
      sleep(1);
   }
}


int getFD(int family,char* address,char* port,int socketType){
    int fd = 0;
    int yes = 1;
    struct addrinfo hints,*res,*iterator;
    struct sockaddr_in* servAddr;
    hints.ai_family = family;
    hints.ai_socktype = socketType;
    //0 -> success
    if(getaddrinfo(address,port,&hints,&res)!=0){
      printf("Addr info error\n");
      return -1;
    }
    //Linked list traversal
    //-1 failures
    for(iterator=res;iterator!=NULL;iterator=res->ai_next){
       char address[200];
       servAddr = (struct sockaddr_in*)iterator->ai_addr;
       if((fd=socket(family,iterator->ai_socktype,iterator->ai_protocol))<0){
          printf("Socket error\n");
          return -1;
       }
       if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes))<0){
         close(fd);
         printf("Options error\n");
         return -1;
       }
       if(bind(fd,iterator->ai_addr,iterator->ai_addrlen)<0){
         close(fd);
         printf("Bind error\n");
         return -1;
       }
       break;
    }
    return fd;
}


void registerRoutes(){
   Map* router = (Map*)malloc(sizeof(Map));
   char routeOne[1] = "/";
   char routeTwo[11] = "/createGame";
   char routeThree[9] = "/joinGame";
   void (*makeGame)() = &createGame;
   put(router,routeOne,makeGame,sizeof(routeOne));
   createGame();
   (*(void (*)())get(router,routeOne,sizeof(routeOne)))();
}
