#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "Server.c"
#include "routes.c"

void main(){
     struct server newServer = initServer(8000);
     serverListen(newServer);
}


