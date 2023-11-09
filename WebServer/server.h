#include <sys/socket.h>
struct server{
     int socket;
     int port;
     struct sockaddr_in address;
};

struct Route{
     char* routeName;
     char* value;
     struct Route* right;
     struct Route* left;
};
