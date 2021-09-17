#include "hashfunc.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const int HASHVEKSIZE = 1048576;    // 2 upphöjt till 20 ungefär 1 miljon
//const int HASHVEKSIZE = 2097152     // 2 upphöjt till 21
//const int HASHVEKSIZE = 4194304;     // 2 upphöjt till 22

uint32_t tilpro_hash(const char * s) {
  uint32_t hash = 0;
  size_t i = 0;
  while (s[i] != '\0') {
    hash += s[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 13;

  hash = hash & ( HASHVEKSIZE - 1 );
  //hash = 17;
  return hash;
}

void put(Nod ** hashtable, char * key, char * value) {
  int hashvalue = tilpro_hash(key);   //Find the hashvalue
  Nod * node = newnode(key,value);    //Creat a new node with key and value
  Nod * searchptr = NULL; 
  searchptr = search(hashtable[hashvalue],key);    //attempt to find a node with same key

  if (searchptr!=NULL){   //if a node with same key is found
    strcpy(searchptr->value, value); //update the value
    free(node);
  }

  else{ //if no node found with similar key, add a new node
    insertnod(&hashtable[hashvalue],node);
  }
  
 
}

char * get(Nod ** hashtable, char * key) {
  int hashvalue = tilpro_hash(key);
  Nod * searchptr = NULL;   //pointer used to search for the node containing the key
  searchptr = search(hashtable[hashvalue],key);

  if (searchptr!=NULL){
    return searchptr->value;
  }

  else{
    char * notfound = "NULL";
    return notfound;
  }

}

void init(Nod ** vek) { //for every slot in the hashtable let the pointer point to NULL
  int i;
  for (i = 0; i<HASHVEKSIZE; ++i){
    vek[i] = NULL;
  }
}