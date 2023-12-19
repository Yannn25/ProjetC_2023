#ifndef FORET_H
#define FORET_H

#include <stdio.h>
#include <stdlib.h>
#include "cellules.h"
#include "grille.h"
#include "color_terminal.h"


typedef struct foret {
    struct grille tab;
    struct cellule**  ensemble;
} foret;

struct foret * buildForet(struct grille grid, struct cellule** ens);
void afficheForet(const struct foret * f);
int setFeuCellule(struct foret * f, int x, int y);
int modifCellule(struct foret * f, int x, int y);
struct foret * copieForet(const struct foret * f);
void libererForet(struct foret * f);
int verifVoisins(int i, int j, struct foret * f);
struct foret * propagation(struct foret * f);
int * verifPropagation(struct foret * f, int Ax, int Bx, int Ay, int By);
#endif 