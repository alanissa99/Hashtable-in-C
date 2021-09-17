#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashfunc.h"
#include <stdint.h>


struct artist {
  char artistid[20];
  char artistname[400];
  char songtitle[300];
  double length;
  int year;
};

typedef struct artist Artist;

extern const int HASHVEKSIZE;

//  Läser artister från filename och lägger dem i artistarray
//  returnerar antalet inlästa artister
int readartists(char * filename, Artist * artistarray) {
  char linebuffer[425];

  FILE * fil = fopen(filename, "r");

  int currentartist = 0;

  while (fgets (linebuffer, 425, fil) != NULL) {

    Artist * artist = artistarray + currentartist;

    int i = 0;
    int j = 0;
    // kolumner är TAB-separerade 
    while (linebuffer[i] != '\t')             
      i++;

    strncpy(artist -> artistid, linebuffer, j);

    i += 1;
    j = i;
    while (linebuffer[i] != '\t') 
      i++;

    strncpy(artist -> artistname, linebuffer + j, i - j);

    i += 1;
    j = i;
    while (linebuffer[i] != '\t') 
      i++;

    strncpy(artist -> songtitle, linebuffer + j, i - j);

    i += 1;
    // atof - array to float
    artist -> length = atof(linebuffer + i);  

    while (linebuffer[i] != '\t') 
      i++;

    i += 1;
    // atoi - array to integer 
    artist -> year = atoi(linebuffer + i);    

    currentartist += 1;
  }
  free(fil);
  return currentartist;
}

int main() {
  Artist * artister = malloc(sizeof(Artist) * 1000000);

  // calloc är ett alternativ till malloc som initierar vektorn till noll
  //   Artist * artister = calloc(1000000, sizeof(Artist));
  Nod ** myhashvek = malloc(sizeof(Nod *) * HASHVEKSIZE);
  init(myhashvek);



  int antalartister = readartists("sang-artist-data.txt", artister);

  int i = 0;
  for (i = 0; i < antalartister; i += 1) {
    //printf("artist: %s\n  songtitle: %s\n  length: %f\n",
       //sartister[i].artistname, artister[i].songtitle, artister[i].length);
       put(myhashvek, artister[i].artistname, artister[i].songtitle);
  }



  char * test = get(myhashvek,"Elude");//showing that my program works
  printf("%s\n",test);



  int j;
    for (j=0; j<HASHVEKSIZE; ++j ){ //Frees every node in the hashtable
      Nod * p = myhashvek[j];

      if (myhashvek[j]==NULL){
        free( myhashvek[j] );
      }
    
      else{
        while(p){
          Nod * tmp = p;
          p = p->next;
          free(tmp);
        }
      }
    
  }
  


  free(artister);
  free(myhashvek);  //frees the table itself

  return 0;

}