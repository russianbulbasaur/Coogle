//a hashmap using closed addressing
#include <stdio.h>
#define CAP 200



struct hashmap{
     void* items[CAP];
} Map;

void put(void*,void*,int);
void* get(void*,int);

int hashFun(void* key,int size){
     int hashed = 0;
     unsigned char *p = key;
     for(int i=0;i<size;i++){
         hashed += *p;
     }
     hashed %= CAP;
     return hashed;
}

void put(void* key,void* val,int size){
     int hash = hashFun(key,size);
     if(Map.items[hash]!=NULL){
        printf("Filled\n");
     }else{
        Map.items[hash] = val;
     }
}


void* get(void* key,int size){
     int hash = hashFun(key,size);
     return Map.items[hash];
}


int main(){
    int val = 2;
    int k1 = 1;
    int k2 = 2;
    int k3 = 3;
    val = 9999;
    put(&k1,&val,4);
    put(&k1,&val,4);
    int res = *((int*)get(&k1,4));
    printf("%i\n",res);
}
