#ifndef LISTA_H
#define LISTA_H

struct nod {
    char key[512];
    char value[512];
    struct nod * next;
    struct nod * prev;
};
typedef struct nod Nod;

void insertnod(Nod ** padr, Nod * tobeadded);
void removenod(Nod ** padr, Nod * toberemoved);
void printnod(Nod * p);
void printlist(Nod * p);
Nod * search(Nod * p, char givenkey[512]);
Nod *newnode(char key[512], char value[512]); //My own function to create nodes

#endif