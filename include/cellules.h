#ifndef CELLULE_H
#define CELLULE_H

//Bibliothèques requise
#include <stdio.h>

typedef struct cellule {
    char type;
    int degre;
    int etat;
} cellule;

void afficheSymbole(struct cellule foret);

#endif 