//a hashmap using closed addressing
#include <stdio.h>
#define CAP 200



typedef struct hashmap{
     void* items[CAP];
} Map;

void put(void*,void*);
void* get(void*);

int hash(void* key){
     int hashed = 0;
     int *p = key;
     for(int i=0;i<sizeof(key);i++){
         hashed += *p;
     }
     hashed %= CAP;
     return hashed;
}

void put(void* key,void* val){
     printf("%i\n",hash(key));
}


void* get(void* key){
}


int main(){
    int val = 2;
    put("ankit",&val);
}
