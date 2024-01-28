//Just a http server
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//File descriptor
int getFD(int,char*,char*,int);

//route addition
int addRoute(char*,void*);

//Incase of heavy traffic
void forkThread();


int main(int argc,char* argv[]){
   if(argc<2){
      printf("Enter address and port to bind to.\n");
      return -1;
   }
   int fd = 0;
   if((fd = getFD(AF_INET,argv[1],argv[2],SOCK_STREAM))<0){
      printf("FD error\n");
      return -1;
   }
   printf("Here is your FD : %i\n",fd);
}


int getFD(int family,char* address,char* port,int socketType){
    int fd = 0;
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
       if(setsockopt()<0){
       }
       break;
    }
    return fd;
}

