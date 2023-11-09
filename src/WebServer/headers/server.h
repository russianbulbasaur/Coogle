#include <sys/socket.h>
struct server{
     int socket;
     int port;
     struct sockaddr_in address;
};

struct Route{
     char* routeName;
     void (*value)(char*);
     struct Route* right;
     struct Route* left;
};
