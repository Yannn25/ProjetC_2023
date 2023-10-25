#ifndef CELLULE_H
#define CELLULE_H

//Bibliothèques requise
#include <stdio.h>

typedef struct cellule {
    char type;
    int degre;
    int etat;
} cellule;

void afficheSymbole(struct cellule cel);
struct cellule CreerType(int rep);
void setType(struct cellule *cel, char t);
void setDegre(struct cellule *cel, int d);
void setEtat(struct cellule *cel, int e);
void toString(struct cellule cel);
#endif 