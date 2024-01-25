#include <unistd.h>
#include <stdio.h>
#include <string.h> //memset,memcpy
#include <netdb.h> //structs
#include <arpa/inet.h> //functions of inet_hton etc
#include <sys/socket.h>

int getSocket(char* ip,int family,int socketType,char* port){
   int fd = 0;
   int yes = 1;
   char address[100];
   struct addrinfo hints,*results,*p;
   memset(&hints,0,sizeof(hints));
   hints.ai_family = family;
   hints.ai_socktype = socketType;
   if(getaddrinfo(ip,port,&hints,&results)!=0){
     printf("getaddrinfo error\n");
     return -1;
   }
   for(p=results;p!=NULL;p = p->ai_next){
     struct sockaddr_in6* addr;
     addr = (struct sockaddr_in6*)p->ai_addr;
     inet_ntop(p->ai_family,&(addr->sin6_addr),address,sizeof(address));
     printf("Address : %s\n",address);
     if((fd = socket(p->ai_family,p->ai_socktype,p->ai_protocol))==-1){
        printf("Socket error\n");
        return -1;
     }
     if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))==-1){
       close(fd);
       printf("Options error\n");
       return -1;
     }
     if(bind(fd,p->ai_addr,p->ai_addrlen)==-1){
       close(fd);
       printf("Binding error\n");
       return -1;
     }
     break;
   }
   return fd;
}
