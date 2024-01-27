//a hashmap using closed addressing
#include <stdio.h>
#define CAP 200



typedef struct hashmap{
     void* items[CAP];
} Map;

void put(void*,void*,int);
void* get(void*);

int hash(void* key,int size){
     int hashed = 0;
     unsigned char *p = key;
     for(int i=0;i<size;i++){
         hashed += *p;
     }
     hashed %= CAP;
     return hashed;
}

void put(void* key,void* val,int size){
     printf("%i\n",hash(key,size));
}


void* get(void* key){
}


int main(){
    int val = 2;
    int k1 = 1;
    int k2 = 2;
    int k3 = 3;
}
