#ifndef NOEUD_H
#define NOEUD_H

#include <stdio.h>
#include <stdlib.h>
#include "cellules.h"

#define MAX_VOISINS  8

typedef struct Noeud {
    struct cellule * cellule;
    struct Noeud * fils[MAX_VOISINS];
    int numFils;
} Noeud;

struct Noeud * newNoeud(struct cellule * c);
void ajtFils(struct Noeud * parent, struct Noeud * fils);
void libererNoeud(struct Noeud * n);
int maxProfondeur(struct Noeud * n);


#endif 