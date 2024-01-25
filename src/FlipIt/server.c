#include "../Socket/Socket.c"
#include <netdb.h>
int main(int argc,char* argv[]){
    if(argc<3){
      printf("Enter listening address & port\n");
      return -1;
    }
    struct sockaddr client;
    socklen_t len;
    int socket = getSocket(argv[1],AF_INET6,SOCK_STREAM,argv[2]);
    if(listen(socket,1)==-1){
      printf("Listening error\n");
      return -1;
    }
    while(1){
          accept(socket,&client,&len);
          printf("Conn \n");
    }
    printf("%i",socket);
}
