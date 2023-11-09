#include <string.h>

struct Route* head = NULL;
void addRoute(char* routeName){
     struct Route* newRoute = (struct Route*)malloc(sizeof(struct Route));
     newRoute->routeName = routeName;
     newRoute->value = "2";
     if(head==NULL){
        head = newRoute;
        printf("Route %s added\n",routeName);
        return;
     }
     struct Route* currentNode = head;
     struct Route* parent;
     int RL = 0;
     while(currentNode!=NULL){
          parent = currentNode;
          if(strcmp(currentNode->routeName,routeName)<0){
             RL = 10;
             currentNode = currentNode->right;
          }else if(strcmp(currentNode->routeName,routeName)>0){
             RL = 01;
             currentNode = currentNode->left;
          }
          else{
             printf("Route already exists\n");
             return;
          }
     }
     if(RL==10){
       parent->right = newRoute;
     }else{
       parent->left = newRoute;
     }
     printf("Route %s inserted\n",routeName);
     return;
}


void findRoute(char* routeName){

}
