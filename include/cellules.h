#ifndef CELLULE_H
#define CELLULE_H

//Bibliothèques requise
#include <stdio.h>

typedef struct cellule {
    char type;
    int degre;
    int etat;
} cellule;

struct cellule CreerType(int rep);
int afficheType(int i, int j);
struct cellule **initTab(int l, int L);
struct cellule **TabMan(int l, int L);
struct cellule **TabAlea(int l, int L);
void setType(struct cellule *cel, char t);
void setDegre(struct cellule *cel, int d);
void setEtat(struct cellule *cel, int e);
void toString(struct cellule cel);
int estTypeSpe(char c);
int estEnFeu(struct cellule *cel);

#endif 