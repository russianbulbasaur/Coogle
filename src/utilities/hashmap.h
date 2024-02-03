//a hashmap using closed addressing
#include <stdio.h>
#define CAP 200



typedef struct hashmap{
     void* items[CAP];
} Map;

void put(Map*,void*,void*,int);
void* get(Map*,void*,int);

int hashFun(void* key,int size){
     int hashed = 0;
     unsigned char *p = key;
     for(int i=0;i<size;i++){
         hashed += *p;
     }
     hashed %= CAP;
     return hashed;
}

void put(Map* hashmap,void* key,void* val,int size){
     int hash = hashFun(key,size);
     if(hashmap->items[hash]!=NULL){
        printf("Filled\n");
     }else{
        hashmap->items[hash] = val;
     }
}


void* get(Map* hashmap,void* key,int size){
     int hash = hashFun(key,size);
     return hashmap->items[hash];
}
