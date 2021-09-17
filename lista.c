#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"


Nod *newnode(char key[512], char value[512]){   
    Nod *result = malloc( sizeof(Nod) );
    strcpy(result->key, key);
    strcpy(result->value,value);
    result->next=NULL;
    result->prev=NULL;
    return result;
}

void insertnod(Nod ** padr, Nod * tobeadded){
  if (*padr==NULL){   //if the list is empty then simply point at the new node which is the first node
       *padr=tobeadded;
    }
    else {   //Otherwise add new node at the front of list 
      tobeadded->next=*padr;            
      (*padr)->prev=tobeadded;     
      *padr=tobeadded;
      }
      
    }

void removenod(Nod ** padr, Nod * toberemoved){    
   if(toberemoved->prev==NULL){
     *padr=toberemoved->next;
     if (toberemoved->next){
        toberemoved->next->prev=NULL;
        }
     }
  
   else if (toberemoved->next){
     toberemoved->next->prev=toberemoved->prev;
     toberemoved->prev->next=toberemoved->next;
     }
     
     else {
       toberemoved->prev->next=NULL;
       }
       
   free(toberemoved);
}

void printnod(Nod * p){
  if (p==NULL){ //In the case that the pointer isnt pointing to a node
    printf("Unable to print a node that is empty/doesnt exist\n");
  }

  else{
  printf("The key is is: %s\n",p->key);
  printf("With the following value: %s\n\n",p->value);
  }
}

void printlist(Nod * p){
  if (p != NULL){ //If the list isnt empty
      Nod * temp = p;
      printf("The list consists of the following nodes:\n");
      int i = 1;  //To count how many times the while loop repeats
    while (temp != NULL){   //Go through the entire list
      printf("Node #%d:\n",i);
      printnod(temp);
      temp = temp->next;
      i++;
    }
  }

  else {
    printf("The list is empty\n");
  }
}

Nod * search(Nod * p, char givenkey[512]){
  while (p && strcmp( p->key,givenkey)!=0 ){ //The pointer will move through the list until it reaches the end or find the telephone number
    p = p->next;
  }
  if(p==NULL){
    
  }
  return p;
}
