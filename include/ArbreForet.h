#ifndef ARBREFORET_H
#define ARBREFORET_H

#include <stdio.h>
#include <stdlib.h>
#include "Noeud.h"
#include "cellules.h"
#include "foret.h"

typedef struct ArbreForet {
    struct Noeud * racine;
} ArbreForet;

struct ArbreForet * ArbreVide();
void libererArbre(struct ArbreForet * a);
int profondeur(struct ArbreForet * a);
struct ArbreForet * ForetToArbre(struct foret * f, int Ax, int Ay);
void construireArbre(struct foret* f, int x, int y, struct Noeud* parent);
void SimulePropa(struct ArbreForet * a, int Ax, int Bx, int Ay, int By);
int nbTourPropa(struct ArbreForet * a, int x, int y);
int longeurChemin(struct ArbreForet * a, int x, int y);

#endif 