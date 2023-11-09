#include <string.h>

struct Route head;
void addRoute(char* routeName){
     struct Route newRoute;
     newRoute.routeName = routeName;
     newRoute.value = "2";
     if(head==NULL){
        head = newRoute;
        return;
     }
}


void findRoute(char* routeName){

}
